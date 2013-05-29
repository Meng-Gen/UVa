#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

// ----------------------------------------------------------------------------
// Char Predicates

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// ----------------------------------------------------------------------------
// Validator

struct Validator {
    std::string source_;

    void Scan() {
        Initialize();
        ScanOperand();
        ScanSymbol(); // + -
        ScanOperand();
        Advance(); // =
        ScanOperand();
    }

    bool IsValid() {
        if (operands_.size() != 3) {
            return false;
        }
        if (symbol_ == '+') {
            return (operands_[0] + operands_[1] == operands_[2]);
        } 
        else if (symbol_ == '-') {
            return (operands_[0] - operands_[1] == operands_[2]);
        }
        // It should not be here.
        return false;
    }

    void Initialize() {
        pos_ = -1;
        c0_ = -1;
        operands_.clear();
    }

    void ScanOperand() {
        Advance();
        if (!IsDecimalDigit(c0_)) {
            return;
        }
        PushBack();

        int operand = 0;
        while (1) {
            Advance();
            if (IsDecimalDigit(c0_)) {
                operand *= 10;
                operand += (c0_ - '0');
            }
            else {
                PushBack();
                break;
            }
        }
        operands_.push_back(operand);
    }

    void ScanSymbol() {
        Advance();
        symbol_ = c0_;
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

    std::vector<int> operands_;
    char symbol_;
    int pos_;
    char c0_;
};

// ----------------------------------------------------------------------------
// Entry for UVa Online Judge

int main(int argc, char* argv[]) {
    Validator validator;
    int num_correct_answers = 0;
    while (getline(std::cin, validator.source_)) {
        validator.Scan();
        if (validator.IsValid()) {
            num_correct_answers++;
        }
    }
    printf("%d\n", num_correct_answers);
    return 0;
}