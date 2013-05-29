#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

// ----------------------------------------------------------------------------
// Validator

struct Validator {
    std::string source_;

    bool IsValid(const std::string& buffer) {
        Initialize(buffer);
        if (!Scan()) {
            return false;
        }
        return IsValidSymbol();
    }

    void Initialize(const std::string& buffer) {
        source_ = buffer;
        pos_ = -1;
        c0_ = -1;
        symbol_length_.clear();
    }

    bool Scan() {
        if (!ScanSymbol()) {
            return false;
        }
        if (!ScanChar('M')) {
            return false;
        }
        if (!ScanSymbol()) {
            return false;
        }
        if (!ScanChar('E')) {
            return false;
        }
        if (!ScanSymbol()) {
            return false;
        }
        return (source_.length() == pos_ + 1);
    }

    bool IsValidSymbol() {
        if (symbol_length_.size() != 3) {
            return false;
        }
        return (symbol_length_[0] + symbol_length_[1] == symbol_length_[2]);
    }

    bool ScanSymbol() {
        Advance();
        if (c0_ != '?') {
            PushBack();
            return false;
        }
        int symbol_length = 1;
        while (1) {
            Advance();
            if (c0_ == '?') {
                symbol_length++;
            }
            else {
                PushBack();
                break;
            }
        }
        symbol_length_.push_back(symbol_length);
        return true;
    }

    bool ScanChar(char c) {
        Advance();
        if (c0_ != c) {
            PushBack();
            return false;
        }
        return true;
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

    int pos_;
    char c0_;
    std::vector<int> symbol_length_;
};

// ----------------------------------------------------------------------------
// Entry for UVa Online Judge

int main(int argc, char* argv[]) {
    int num_testcases;
    std::cin >> num_testcases;

    Validator validator;
    for (int case_id = 0; case_id < num_testcases; case_id++) {
        std::string buffer;
        std::cin >> buffer;
        if (validator.IsValid(buffer)) {
            puts("theorem");
        }
        else {
            puts("no-theorem");
        }
    }
    return 0;
}