#include <iostream>
#include <string>
#include <stdio.h>

class TicTacToe {
public:
    char dots[3][3];

    bool IsValid() {
        Init();

        if (IsCheated()) {
            return false;
        }
        if (IsXTurn() && IsOWinning()) {
            return false;
        }
        if (IsOTurn() && IsXWinning()) {
            return false;
        }

        return true;
    }

private:
    void Init() {
        x_count_ = 0;
        o_count_ = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (dots[i][j] == 'X') {
                    x_count_++;
                } 
                else if (dots[i][j] == 'O') {
                    o_count_++;
                }
            }
        }
    }

    bool IsXWinning() const {
        return IsWinning('X');
    }

    bool IsOWinning() const {
        return IsWinning('O');
    }

    bool IsWinning(char c) const {
        for (int i = 0; i < 3; i++) {
            if (dots[i][0] == c && dots[i][1] == c && dots[i][2] == c) {
                return true;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (dots[0][j] == c && dots[1][j] == c && dots[2][j] == c) {
                return true;
            }
        }
        if (dots[0][0] == c && dots[1][1] == c && dots[2][2] == c) {
            return true;
        }
        if (dots[0][2] == c && dots[1][1] == c && dots[2][0] == c) {
            return true;
        }
        return false;
    }

    bool IsXTurn() const {
        return (x_count_ == o_count_ + 1);
    }

    bool IsOTurn() const {
        return (x_count_ == o_count_);
    }

    bool IsCheated() const {
        return (x_count_ != o_count_ + 1) && (x_count_ != o_count_);
    }

    int x_count_;
    int o_count_;
};

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        TicTacToe game;

        std::string buffer;
        int curr_row = 0;
        while (getline(std::cin, buffer) && (buffer != ""))
        {
            for (int i = 0; i < 3; i++)
            {
                game.dots[curr_row][i] = buffer[i];
            }
            curr_row++;
        }

        if (game.IsValid())
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }

    return 0;
}