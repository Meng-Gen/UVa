#include <iostream>
#include <map>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

#define MAGIC_EPSILON (1e-8)

template <class T>
inline T to_type(const std::string& s) {
    std::stringstream builder(s);
    T t;
    builder >> t;
    return t;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// ----------------------------------------------------------------------------
// Token

enum TokenType {
    DECIMAL_NUMBER = 0,
    FLOATING_NUMBER = 1,
    SYMBOL = 2,
};

struct Token {
    TokenType Type;
    std::string Value;

    Token() { }
    Token(TokenType type) { this->Type = type; }
    Token(TokenType type, const std::string& value) {
        this->Type = type;
        this->Value = value;
    }
};

// ----------------------------------------------------------------------------
// Scanner

class Scanner
{
public:
    void Initialize(const std::vector<char>& source) {
        source_ = source;
        pos_ = -1;
        c0_ = -1;
        tokens_.clear();
    }

    void Scan() {
        do {
            Advance();
            switch (c0_) {
            case '+':
                tokens_.push_back(Token(SYMBOL, "+"));
                break;
            case '-':
                tokens_.push_back(Token(SYMBOL, "-"));
                break;
            case '*':
                tokens_.push_back(Token(SYMBOL, "*"));
                break;
            case '/':
                tokens_.push_back(Token(SYMBOL, "/"));
                break;
            case '.':
                // number
                Advance();
                if (IsDecimalDigit(c0_)) {
                    PushBack();
                    ScanFloatingNumber();
                }
                break;
            default:
                // number
                if (IsDecimalDigit(c0_)) {
                    ScanNumber();
                }
                break;
            }
        }
        while (c0_ > 0);
    }

    std::vector<Token> tokens() const 
    {
        return tokens_;
    }

private:
    void ScanFloatingNumber() {
        buffer_ << c0_;
        while (1) {
            Advance();
            
            if (!IsDecimalDigit(c0_)) {
                PushBack();
                break;
            }
            buffer_ << c0_;
        }
        tokens_.push_back(Token(FLOATING_NUMBER, buffer_.str()));
        buffer_.str("");
    }

    void ScanFloatingNumberExponent() {
        buffer_ << c0_;
        
        Advance();
        if (c0_ == '+' || c0_ == '-') {
            buffer_ << c0_;
        }
        else {
            PushBack();
        }
        ScanFloatingNumberExponentPrefixed();
    }

    void ScanFloatingNumberExponentPrefixed() {
        while (1) {
            Advance();
            if (!IsDecimalDigit(c0_)) {
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
        while (1) {
            Advance();
            if (IsDecimalDigit(c0_)) {
                buffer_ << c0_;
            }
            else if (c0_ == '.') {
                ScanFloatingNumber();
                is_decimal_number = false;
                break;
            }
            else {
                PushBack();
                break;
            }
        }

        if (is_decimal_number) {
            tokens_.push_back(Token(DECIMAL_NUMBER, buffer_.str()));
            buffer_.str("");
        }
    }

    void Advance() { 
        pos_++;
        if (static_cast<unsigned int>(pos_) < source_.size()) {
            c0_ = source_[pos_];
        }
        else {
            c0_ = -1;
        }
    }

    void PushBack() {
        pos_--;
        if (pos_ >= 0) {    
            c0_ = source_[pos_];
        }
        else {
            c0_ = -1;
        }
    }

    std::vector<char> source_;
    std::stringstream buffer_;
    int pos_;
    char c0_;

    std::vector<Token> tokens_;
};

// ----------------------------------------------------------------------------
// Token

enum InterpretedTokenType {
    NUMBER = 0,
    OPERATOR = 1,
};

struct InterpretedToken {
    InterpretedTokenType Type;
    double NumberValue;
    char OperatorValue;
};

// ----------------------------------------------------------------------------
// Interpreter Utilities

std::map<char, int> op_precedence;

void InitOpPrecedence() {
    op_precedence['+'] = 0;
    op_precedence['-'] = 0;
    op_precedence['*'] = 1;
    op_precedence['/'] = 1;
}

// ----------------------------------------------------------------------------
// Interpreter

class Interpreter
{
public:
    void Initialize(const std::vector<Token>& tokens) {
        InterpretedToken token;

        bool is_unary = true;
        int num = tokens.size();
        for (int i = 0; i < num; i++) {
            TokenType type = tokens[i].Type;
            if (type == SYMBOL) {
                if (is_unary) {
                    int sign = 1;
                    for (; tokens[i].Type == SYMBOL; i++) {
                        if (tokens[i].Value[0] == '-') {
                            sign = -sign;
                        }
                    }
                    token.Type = NUMBER;
                    token.NumberValue = to_type<double>(tokens[i].Value) * sign;
                    token.OperatorValue = 0;
                    is_unary = false;
                }
                else {
                    token.Type = OPERATOR;
                    token.OperatorValue = tokens[i].Value[0];
                    token.NumberValue = 0.0;
                    is_unary = true;
                }
            }
            else if (type == DECIMAL_NUMBER || type == FLOATING_NUMBER) {
                token.Type = NUMBER;
                token.NumberValue = to_type<double>(tokens[i].Value);
                token.OperatorValue = 0;
                is_unary = false;
            } 
            tokens_.push_back(token);
        }
    }

    void Interpret() {
        SetPostfixExpression();
        EvaluatePostfixExpression();
    }

    double evaluation() const {
        return evaluation_;
    }

private:
    void SetPostfixExpression() {
        postfix_.clear();
        std::stack<InterpretedToken> op_stack;
        for (std::vector<InterpretedToken>::const_iterator 
            it = tokens_.begin(); it != tokens_.end(); it++)
        {
            if (it->Type == NUMBER) {
                postfix_.push_back(*it);
            }
            else {
                while (!op_stack.empty()) {
                    InterpretedToken top = op_stack.top();
                    if (op_precedence[it->OperatorValue] <= 
                        op_precedence[top.OperatorValue])
                    {
                        postfix_.push_back(top);
                        op_stack.pop();
                    }
                    else {
                        break;
                    }
                }
                op_stack.push(*it);
            }
        }
        while (!op_stack.empty()) {
            postfix_.push_back(op_stack.top());
            op_stack.pop();
        }
    }

    void EvaluatePostfixExpression() {
        std::stack<double> evaluation_stack;
        for (std::vector<InterpretedToken>::const_iterator 
            it = postfix_.begin(); it != postfix_.end(); it++)
        {
            if (it->Type == NUMBER) {
                evaluation_stack.push(it->NumberValue);
            }
            else if (it->Type == OPERATOR) {
                double b = evaluation_stack.top();
                evaluation_stack.pop();
                double a = evaluation_stack.top();
                evaluation_stack.pop();

                if (it->OperatorValue == '+') {
                    evaluation_stack.push(a + b);
                }
                else if (it->OperatorValue == '-') {
                    evaluation_stack.push(a - b);
                }
                else if (it->OperatorValue == '*') {
                    evaluation_stack.push(a * b);
                }
                else if (it->OperatorValue == '/') {
                    evaluation_stack.push(a / b);
                }
            }
        }
        evaluation_ = evaluation_stack.top();        
    }

    std::vector<InterpretedToken> tokens_;
    std::vector<InterpretedToken> postfix_;
    double evaluation_;
};

// ----------------------------------------------------------------------------
// Entry for UVa Online Judge

std::vector<char> source;

void Solve() {
    Scanner scanner;
    scanner.Initialize(source);
    scanner.Scan();

    Interpreter interpreter;
    interpreter.Initialize(scanner.tokens());
    interpreter.Interpret();

    printf("%.3lf\n", interpreter.evaluation() + MAGIC_EPSILON);
}

int main(int argc, char* argv[]) {
    InitOpPrecedence();

    char c;
    while (1) {
        c = getchar();
        if (c == EOF) { 
            Solve();
            break; 
        }        
        if (c == '\n') {
            Solve();
            source.clear();
        }
        else {
            source.push_back(c);
        }
    }

    return 0;
}