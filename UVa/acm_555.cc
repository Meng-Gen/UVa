#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

inline int absolute(int a)
{
    return (a < 0) ? -a : a;
}

// CLUBS < DIAMONDS < SPADES < HEARTS
std::map<char, int> suit_order;

// 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < T < J < Q < K < A.
std::map<char, int> rank_order;

void InitSuitOrder()
{
    suit_order['C'] = 0;
    suit_order['D'] = 1;
    suit_order['S'] = 2;
    suit_order['H'] = 3;
}

void InitRankOrder()
{
    for (int i = '2'; i <= '9'; i++)
    {
        rank_order[i] = i - '2';
    }
    rank_order['T'] = 8;
    rank_order['J'] = 9;
    rank_order['Q'] = 10;
    rank_order['K'] = 11;
    rank_order['A'] = 12;
}

struct Card
{
    char suit_;
    char rank_;

    Card() : suit_(0), rank_(0), order_(0) { }

    void SetOrder()
    {
        order_ = suit_order[suit_] * 13 + rank_order[rank_];
    }

    int order_;
};

bool CompareDelegate(const Card& a, const Card& b)
{
    return a.order_ < b.order_;
}

std::map<char, int> position;

void SetPosition(char dealer)
{
    position['S'] = 0;
    position['W'] = 1;
    position['N'] = 2;
    position['E'] = 3;

    int shift = absolute(3 - position[dealer]);
    
    position['S'] = (position['S'] + shift) % 4;
    position['W'] = (position['W'] + shift) % 4;
    position['N'] = (position['N'] + shift) % 4;
    position['E'] = (position['E'] + shift) % 4;
}

int main(int argc, char* argv[]) 
{   
    InitSuitOrder();
    InitRankOrder();

    char dealer;
    while (std::cin >> dealer && (dealer != '#'))
    {
        SetPosition(dealer);

        Card player_cards[4][13];
        char suit;
        char rank;
        for (int i = 0; i < 52; i++)
        {
            std::cin >> player_cards[i%4][i/4].suit_ >> player_cards[i%4][i/4].rank_;
            player_cards[i%4][i/4].SetOrder();
        }
        for (int i = 0; i < 4; i++)
        {
            std::sort(player_cards[i], player_cards[i] + 13, CompareDelegate);
        }

        char player[] = { 'S', 'W', 'N', 'E' };
        for (int i = 0; i < 4; i++)
        {
            printf("%c: ", player[i]);          
            for (int j = 0; j < 13; j++)
            {
                printf("%c%c", 
                    player_cards[position[player[i]]][j].suit_, 
                    player_cards[position[player[i]]][j].rank_);

                if (j != 12)
                {
                    putchar(' ');
                }
                else 
                {
                    putchar('\n');
                }
            }
        }
    }

    return 0;
}
