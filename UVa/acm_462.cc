#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

std::map<char, int> suit_map;
std::map<int, char> suit_inverse_map;
std::map<char, int> rank_map;

void InitSuitMap()
{
    suit_map['C'] = 0;
    suit_map['D'] = 1;
    suit_map['H'] = 2;
    suit_map['S'] = 3;

    suit_inverse_map[0] = 'C';
    suit_inverse_map[1] = 'D';
    suit_inverse_map[2] = 'H';
    suit_inverse_map[3] = 'S';
}

void InitRankMap()
{
    for (int i = '2'; i <= '9'; i++)
    {
        rank_map[i] = 14 - i + '0';
    }
    rank_map['T'] = 4;
    rank_map['J'] = 3;
    rank_map['Q'] = 2;
    rank_map['K'] = 1;
    rank_map['A'] = 0;
}

struct Hand
{
    bool cards[4][13];

    Hand() 
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                cards[i][j] = false;
            }
        }
    }

    void InsertCard(char suit, char rank)
    {
        cards[suit_map[suit]][rank_map[rank]] = true;
    }

    void PrepareQuery()
    {
        CountSuitLength();
        CountHighCardPoint();
        CountShortSuitPoint();
        CountTotalPoint();
    }

    bool HasNTBidding()
    {
        return (AreSuitsStopped() && (total_hcp_ >= 16));
    }

    bool HasPassBidding()
    {
        return (total_point_ < 14);
    }

    char GetSuitBidding()
    {
        char suit = 'C';
        int max_length = suit_length_[0];
        for (int i = 1; i < 4; i++)
        {
            if (suit_length_[i] >= max_length)
            {
                max_length = suit_length_[i];
                suit = suit_inverse_map[i];
            }
        }
        return suit;
    }

    // -------------------------------------------------------------------------

    void CountSuitLength()
    {
        for (int i = 0; i < 4; i++)
        {
            suit_length_[i] = 0;
            for (int j = 0; j < 13; j++)
            {
                if (cards[i][j])
                {
                    suit_length_[i]++;
                }
            }
        }
    }

    void CountHighCardPoint()
    {
        for (int i = 0; i < 4; i++)
        {
            hcp_[i] = 0;

            for (int j = 0; j < 4; j++)
            {
                if (cards[i][j])
                {
                    hcp_[i] += (4 - j);
                }  
            }
            if ((suit_length_[i] <= 1) && cards[i][1])
            {
                hcp_[i]--;
            }
            if ((suit_length_[i] <= 2) && cards[i][2])
            {
                hcp_[i]--;
            }
            if ((suit_length_[i] <= 3) && cards[i][3])
            {
                hcp_[i]--;
            }
        }
    }

    void CountShortSuitPoint()
    {
        for (int i = 0; i < 4; i++)
        {
            ssp_[i] = 0;

            if (suit_length_[i] == 2)
            {
                ssp_[i] += 1;
            }
            if (suit_length_[i] == 1)
            {
                ssp_[i] += 2;
            }
            if (suit_length_[i] == 0)
            {
                ssp_[i] += 2;
            }
        }
    }

    void CountTotalPoint()
    {
        total_hcp_ = 0;
        total_ssp_ = 0;
        for (int i = 0; i < 4; i++)
        {
            total_hcp_ += hcp_[i];
            total_ssp_ += ssp_[i];
        }
        total_point_ = total_hcp_ + total_ssp_;
    }

    bool AreSuitsStopped()
    {
        for (int i = 0; i < 4; i++)
        {
            if (cards[i][0])
            {
                continue;
            }
            if (cards[i][1] && (suit_length_[i] >= 2))
            {
                continue;
            }
            if (cards[i][2] && (suit_length_[i] >= 3))
            {
                continue;
            }
            return false;
        }  
        return true;
    }

    int suit_length_[4];
    int hcp_[4];
    int ssp_[4];
    int total_hcp_;
    int total_ssp_;
    int total_point_;
};

int main(int argc, char* argv[]) 
{   
    InitSuitMap();
    InitRankMap();

    char rank;
    char suit;
    while (std::cin >> rank >> suit)
    {
        Hand hand;
        hand.InsertCard(suit, rank);
        for (int i = 1; i <= 12; i++)
        {
            std::cin >> rank >> suit;
            hand.InsertCard(suit, rank);
        }

        hand.PrepareQuery();
        if (hand.HasPassBidding())
        {
            puts("PASS");
        }
        else if (hand.HasNTBidding())
        {
            puts("BID NO-TRUMP");
        }
        else
        {
            printf("BID %c\n", hand.GetSuitBidding());
        }    
    }   
    return 0;
}
