#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

std::vector<std::string> Tokenize(const std::string& buffer) {
    std::stringstream tokenizer(buffer);
    std::istream_iterator<std::string> it(tokenizer);
    std::istream_iterator<std::string> end;
    return std::vector<std::string>(it, end);
}

template <class T>
inline T to_type(const std::string& s) {
    std::stringstream builder(s);
    T t;
    builder >> t;
    return t;
}

// -----------------------------------------------------------------------------

long long ToSeconds(const std::string& time)
{
    if (time.size() != 8)
    {
        return 0;
    }
    return (time[0] - '0') * 36000 + (time[1] - '0') * 3600 + 
        (time[3] - '0') * 600 + (time[4] - '0') * 60 + 
        (time[6] - '0') * 10 + time[7] - '0';
}

std::vector<std::string> tokens;
bool is_first = true;
long long begin_time;
double curr_speed = 0.0;
double total_distance = 0.0;

inline void Set()
{
    if (is_first)
    {
        begin_time = ToSeconds(tokens[0]);
        curr_speed = to_type<double>(tokens[1]);
        is_first = false;
    }  
    else
    {
        long long curr_time = ToSeconds(tokens[0]);
        total_distance += (curr_time - begin_time) * curr_speed / 3600.0;
        begin_time = curr_time;
        curr_speed = to_type<double>(tokens[1]);
    }
}

inline void Query()
{
    if (is_first)
    {
        begin_time = ToSeconds(tokens[0]);
        printf("%s 0.00 km\n", tokens[0].c_str());
    }
    else
    {
        long long delta_time = ToSeconds(tokens[0]) - begin_time;
        double curr_distance = total_distance + delta_time * curr_speed / 3600.0;
        printf("%s %.2lf km\n", tokens[0].c_str(), curr_distance);
    }
}

int main(int argc, char* argv[])
{
    std::string buffer;    
    while (getline(std::cin, buffer))
    {
        tokens = Tokenize(buffer);
        if (tokens.size() == 2)
        {
            Set();
        }
        else
        {
            Query();
        }
    }

    return 0;
}