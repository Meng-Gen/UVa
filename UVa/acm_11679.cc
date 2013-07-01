#include <iostream>
#include <stdio.h>

int B, N;
int D, C, V;
int monetary_reserves[22];
int liquidation_value[22];

int main(int argc, char* argv[]) 
{
    while (std::cin >> B >> N && (B || N))
    {
        for (int bank_id = 1; bank_id <= B; bank_id++)
        {
            std::cin >> monetary_reserves[bank_id];
            liquidation_value[bank_id] = monetary_reserves[bank_id];
        }
        for (int debenture_id = 0; debenture_id < N; debenture_id++)
        {
            std::cin >> D >> C >> V;
            liquidation_value[D] -= V;
            liquidation_value[C] += V;
        }

        bool is_bailout = false;
        for (int bank_id = 1; bank_id <= B; bank_id++)
        {
            if (liquidation_value[bank_id] < 0)
            {
                is_bailout = true;
                break;
            }
        }
        if (is_bailout)
        {
            puts("N");
        }
        else
        {
            puts("S");
        }
    }
    
    return 0;
}
