#include <iterator>
#include <iostream>
#include <map>
#include <set>
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

// -----------------------------------------------------------------------------

std::string notes[12] = 
{
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",
};

std::map<std::string, int> note_order;

inline void InitNoteOrder() 
{
    for (int i = 0; i < 12; i++)
    {
        note_order[notes[i]] = i;
    }
}

// tone, tone, semi-tone, tone, tone, tone, semi-tone.
int tone[7] = { 0, 2, 4, 5, 7, 9, 11 };

std::set<int> tone_set;

inline void InitToneSet()
{
    for (int i = 0; i < 7; i++)
    {
        tone_set.insert(tone[i]);
    }
}

// -----------------------------------------------------------------------------

std::vector<std::string> keys;
std::vector<int> major_scales;

bool IsMajorScale(int offset)
{
    for (std::vector<std::string>::iterator it = keys.begin();
        it != keys.end(); it++)
    {
        int note_pos = (note_order[*it] - offset + 12 ) % 12;
        if (tone_set.find(note_pos) == tone_set.end())
        {
            return false;
        }
    }
    return true;
}

void BuildMajorScales()
{
    major_scales.clear();
    for (int offset = 0; offset < 12; offset++)
    {
        if (IsMajorScale(offset))
        {
            major_scales.push_back(offset);
        }
    }
}

int main(int argc, char* argv[]) 
{
    InitNoteOrder();
    InitToneSet();

    std::string buffer;
    while (getline(std::cin, buffer) && (buffer != "END"))
    {
        keys = Tokenize(buffer);
        BuildMajorScales();
        int num_major_scales = major_scales.size();
        for (int i = 0; i < num_major_scales; i++)
        {
            if (i != 0)
            {
                putchar(' ');
            }
            printf("%s", notes[major_scales[i]].c_str());
        }
        putchar('\n');
    }
    return 0;
}