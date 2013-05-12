#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <string>
#include <stdio.h>

// ----------------------------------------------------------------------------
// Char Predicates

inline int AsciiAlphaToLower(char c) 
{
    return c | 0x20;
}

inline bool IsLineFeed(char c) 
{
    return c == 0x000A;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) 
{
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) 
{
    return IsInRange(c, '0', '9');
}

inline bool IsAsciiAlpha(char c) 
{
    return IsInRange(AsciiAlphaToLower(c), 'a', 'z');
}

inline bool IsHexDigit(char c) 
{
    return IsDecimalDigit(c) || IsInRange(AsciiAlphaToLower(c), 'a', 'f');
}

// ----------------------------------------------------------------------------
// Token

std::set<std::string> ReservedWords;

void InitReservedWords()
{
    std::string reservedWords[21] = 
    {
        "and", "break", "do", "else", "elseif",
        "end", "false", "for", "function", "if",
        "in", "local", "nil", "not", "or",
        "repeat", "return", "then", "true", "until", "while",
    };
    ReservedWords = std::set<std::string>(reservedWords, 
        reservedWords + 21);
}

enum TokenType
{
    RESERVED = 0,
    DECIMAL_NUMBER = 1,
    DECIMAL_HEX_NUMBER = 2,
    FLOATING_NUMBER = 3,
    STRING = 4,
    SYMBOL = 5,
    NAME = 6,
    EOL = 7,
    COMMENT = 8,
};

std::map<TokenType, std::string> TokenTypeToString;

void InitTokenTypeToString()
{
    TokenTypeToString[RESERVED] = "RESERVED";
    TokenTypeToString[DECIMAL_NUMBER] = "NUMBER";
    TokenTypeToString[DECIMAL_HEX_NUMBER] = "NUMBER";
    TokenTypeToString[FLOATING_NUMBER] = "NUMBER";
    TokenTypeToString[STRING] = "STRING";
    TokenTypeToString[SYMBOL] = "SYMBOL";
    TokenTypeToString[NAME] = "NAME";
    TokenTypeToString[EOL] = "EOL";
    TokenTypeToString[COMMENT] = "COMMENT";
}

struct Token
{
    TokenType Type;
    std::string Value;

    Token()
    {
    }

    Token(TokenType type)
    {
        this->Type = type;
    }

    Token(TokenType type, const std::string& value)
    {
        this->Type = type;
        this->Value = value;
    }

    void ToString()
    {
        if (this->Type == COMMENT)
        {
            return;
        }
        std::cout << "[" << TokenTypeToString[this->Type] << "]";
        if (this->Type != EOL)
        {
            std::cout << " " << this->Value;
        }
        std::cout << std::endl;
    }
};

// ----------------------------------------------------------------------------
// Scanner

struct Scanner
{
    void Initialize(const std::vector<char>& source)
    {
        InitTokenTypeToString();
        InitReservedWords();
        source_ = source;
        pos_ = -1;
        c0_ = -1;
        tokens_.clear();
    }

    void Scan()
    {
        do
        {
            Advance();
            switch (c0_)
            {
            case '\n':
                tokens_.push_back(Token(EOL));
                break;
            case '+':
                tokens_.push_back(Token(SYMBOL, "+"));
                break;
            case '-':
                // - --
                Advance();
                if (c0_ == '-')
                {
                    ScanComment();
                }
                else
                {
                    tokens_.push_back(Token(SYMBOL, "-"));
                    PushBack();
                }
                break;
            case '*':
                tokens_.push_back(Token(SYMBOL, "*"));
                break;
            case '/':
                tokens_.push_back(Token(SYMBOL, "/"));
                break;
            case '%':
                tokens_.push_back(Token(SYMBOL, "%"));
                break;
            case '^':
                tokens_.push_back(Token(SYMBOL, "^"));
                break;
            case '#':
                tokens_.push_back(Token(SYMBOL, "#"));
                break;
            case '=':
                // = ==
                Advance();
                if (c0_ == '=')
                {
                    tokens_.push_back(Token(SYMBOL, "=="));
                }
                else
                {
                    tokens_.push_back(Token(SYMBOL, "="));
                    PushBack();
                }
                break;
            case '~':
                // ~=
                Advance();
                if (c0_ == '=')
                {
                    tokens_.push_back(Token(SYMBOL, "~="));
                }
                else
                {
                    // It should not be here.
                    PushBack();
                }
                break;
           case '<':
                // < <=
                Advance();
                if (c0_ == '=')
                {
                    tokens_.push_back(Token(SYMBOL, "<="));
                }
                else
                {
                    tokens_.push_back(Token(SYMBOL, "<"));
                    PushBack();
                }
                break;
            case '>':
                // > >=
                Advance();
                if (c0_ == '=')
                {
                    tokens_.push_back(Token(SYMBOL, ">="));
                }
                else
                {
                    tokens_.push_back(Token(SYMBOL, ">"));
                    PushBack();
                }
                break;
            case '(':
                tokens_.push_back(Token(SYMBOL, "("));
                break;
            case ')':
                tokens_.push_back(Token(SYMBOL, ")"));
                break;
            case '{':
                tokens_.push_back(Token(SYMBOL, "{"));
                break;
            case '}':
                tokens_.push_back(Token(SYMBOL, "}"));
                break;
            case '[':
                tokens_.push_back(Token(SYMBOL, "["));
                break;
            case ']':
                tokens_.push_back(Token(SYMBOL, "]"));
                break;
            case ';':
                tokens_.push_back(Token(SYMBOL, ";"));
                break;
            case ':':
                tokens_.push_back(Token(SYMBOL, ":"));
                break;
            case ',':
                tokens_.push_back(Token(SYMBOL, ","));
                break;
            case '.':
                // . .. ... number
                Advance();
                if (c0_ == '.')
                {
                    Advance();
                    {
                        if (c0_ == '.')
                        {
                            tokens_.push_back(Token(SYMBOL, "..."));
                        }
                        else
                        {
                            PushBack();
                            tokens_.push_back(Token(SYMBOL, ".."));
                        }
                    }
                }
                else if (IsDecimalDigit(c0_))
                {
                    PushBack();
                    ScanFloatingNumber();
                }
                else 
                {
                    PushBack();
                    tokens_.push_back(Token(SYMBOL, "."));
                }
                break;
            case '0':
                Advance();
                // hexadecimal number
                if (AsciiAlphaToLower(c0_) == 'x')
                {
                    ScanHexNumber();
                }
                else
                {
                    PushBack();
                    ScanNumber();
                }
                break;
            case '\"':
                ScanString();
                break;
            default:
                // number
                if (IsDecimalDigit(c0_))
                {
                    ScanNumber();
                }
                // name or reserved word
                else if (IsAsciiAlpha(c0_))
                {
                    ScanWord();
                }
                break;
            }
        }
        while (c0_ > 0);
    }

    void ScanComment()
    {
        while (1)
        {
            Advance();
            if (c0_ == '\n' || c0_ <= 0)
            {
                PushBack();
                break;
            }
            buffer_ << c0_;
        }       
        tokens_.push_back(Token(COMMENT, buffer_.str()));
        buffer_.str("");
    }

    void ScanFloatingNumber()
    {
        buffer_ << c0_;
        bool has_exponent = false;
        while (1)
        {
            Advance();
            if (AsciiAlphaToLower(c0_) == 'e')
            {
                has_exponent = true;
                ScanFloatingNumberExponent();
                break;
            }
            if (!IsDecimalDigit(c0_))
            {
                PushBack();
                break;
            }
            buffer_ << c0_;
        }
        if (!has_exponent)
        {
            tokens_.push_back(Token(FLOATING_NUMBER, buffer_.str()));
            buffer_.str("");
        }
    }

    void ScanFloatingNumberExponent()
    {
        buffer_ << c0_;
        
        Advance();
        if (c0_ == '+' || c0_ == '-')
        {
            buffer_ << c0_;
        }
        else 
        {
            PushBack();
        }

        ScanFloatingNumberExponentPrefixed();
    }

    void ScanFloatingNumberExponentPrefixed()
    {
        while (1)
        {
            Advance();
            if (!IsDecimalDigit(c0_))
            {
                PushBack();
                break;
            }
            buffer_ << c0_;
        }       
        tokens_.push_back(Token(FLOATING_NUMBER, buffer_.str())); 
        buffer_.str("");
    }

    void ScanNumber()
    {
        buffer_ << c0_;
        bool is_decimal_number = true;
        while (1)
        {
            Advance();
            if (IsDecimalDigit(c0_))
            {
                buffer_ << c0_;
            }
            else if (c0_ == '.')
            {
                ScanFloatingNumber();
                is_decimal_number = false;
                break;
            }
            else if (AsciiAlphaToLower(c0_) == 'e')
            {
                ScanFloatingNumberExponent();
                is_decimal_number = false;
                break;
            }
            else
            {
                PushBack();
                break;
            }
        }

        if (is_decimal_number)
        {
            tokens_.push_back(Token(DECIMAL_NUMBER, buffer_.str()));
            buffer_.str("");
        }
    }

    void ScanHexNumber()
    {
        buffer_ << "0" << c0_;
        while (1)
        {
            Advance();
            if (!IsHexDigit(c0_))
            {
                PushBack();
                break;
            }
            buffer_ << c0_;
        }       
        tokens_.push_back(Token(DECIMAL_HEX_NUMBER, buffer_.str()));
        buffer_.str("");
    }

    void ScanString()
    {
        buffer_ << c0_;

        bool is_enclosed = false;
        while (!is_enclosed)
        {
            Advance();
            buffer_ << c0_;
            switch (c0_)
            {
            case '\\':
                Advance();
                // escaped characters
                if (c0_ == '\"' || c0_ == '\'' || c0_ == '\\' || c0_ == 'n')
                {
                    buffer_ << c0_;
                }
                else
                {
                    PushBack();
                }
                break;
            case '\"':
                is_enclosed = true;
                break;
            default:
                break;
            }
        }
        tokens_.push_back(Token(STRING, buffer_.str()));
        buffer_.str("");
    }

    void ScanWord()
    {
        buffer_ << c0_;
        while (1)
        {
            Advance();
            if (IsAsciiAlpha(c0_) || IsDecimalDigit(c0_) || c0_ == '_')
            {
                buffer_ << c0_;
            }
            else
            {
                PushBack();
                break;
            }
        }

        std::string word = buffer_.str();
        if (ReservedWords.find(word) != ReservedWords.end())
        {
            tokens_.push_back(Token(RESERVED, word));
        }
        else
        {
            tokens_.push_back(Token(NAME, word)); 
        }
        buffer_.str("");
    }

    void Advance() 
    { 
        pos_++;
        if (static_cast<unsigned int>(pos_) < source_.size())
        {
            c0_ = source_[pos_];
        }
        else
        {
            c0_ = -1;
        }
    }

    void PushBack() 
    {
        pos_--;
        if (pos_ >= 0)
        {    
            c0_ = source_[pos_];
        }
        else
        {
            c0_ = -1;
        }
    }

    std::vector<char> source_;
    std::stringstream buffer_;
    int pos_;
    char c0_;

    std::vector<Token> tokens_;
};

int main(int argc, char* argv[])
{
    std::vector<char> source;
    char c;
    while (1) 
    {
        c = getchar();
        if (c == EOF) 
        { 
            break; 
        }
        source.push_back(c);
    }

    Scanner scanner;
    scanner.Initialize(source);
    scanner.Scan();

    std::vector<Token> tokens = scanner.tokens_;
    for (unsigned int i = 0; i < tokens.size(); i++)
    {
        tokens[i].ToString();
    }

    system("pause");

    return 0;
}