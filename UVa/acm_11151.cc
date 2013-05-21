#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

char buffer[1002];
int c[1002][1002];

inline int get_max(int a, int b)
{
    return (a > b) ? a : b;
}

// http://mypaper.pchome.com.tw/zerojudge/post/1322937733
// First lesson on LPS, LCS...  I have no sense about strings.  
// The above link is excellent, and I learn a lot on it. 

int LPS(const std::string& word)
{
    memset(c, 0, 1002 * 1002);
    int n = word.size();
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; i+j < n; j++) 
        {
            if (word[j] == word[i+j]) 
            {
                c[j][j+i] = c[j+1][j+i-1] + (i == 0 ? 1 : 2);
            } 
            else 
            {
                c[j][j+i] = get_max(c[j+1][j+i], c[j][j+i-1]);
            }
        }
    }
    return c[0][n-1];
}

int main(int argc, char* argv[])
{
    int T;    
    std::cin >> T;
    getchar();
    for (int t = 0; t < T; t++)
    {
        std::string word;
        getline(std::cin, word);
        std::cout << LPS(word) << std::endl;
    }
    return 0;
}

// Test case
// =========
// 12
// ADAM
// MADAM
// 
// qweqweqwedadqweqweqwe
// 
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// abcdefghijklmnopqrstuvwxyz
// abcdefhh
// abcabcabc
// 0101010101
// a
// abefgba
//
// Expected
// ========
// 3
// 5
// 0
// 13
// 0
// 255
// 1
// 2
// 5
// 9
// 1
// 5