#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

void NounPhrase();

std::string buffer;
int choice = 1;
std::vector<std::string> result;

// <empty> ::= ""
void Empty() 
{ 
}

// <preposition> ::= on | over | through 
void Preposition()
{
    int which = (choice % 3) + 1;
    choice++;

    if (which == 1)
    {
        result.push_back("on");
    }
    else if (which == 2)
    {
        result.push_back("over");
    }
    else if (which == 3)
    {
        result.push_back("through");
    }
}

// <adverb> ::= nearly | suddenly | restlessly 
void Adverb()
{
    int which = (choice % 3) + 1;
    choice++;

    if (which == 1)
    {
        result.push_back("nearly");
    }
    else if (which == 2)
    {
        result.push_back("suddenly");
    }
    else if (which == 3)
    {
        result.push_back("restlessly");
    }
}

// <adjective> ::= green | small | rabid | quick 
void Adjective()
{
    int which = (choice % 4) + 1;
    choice++;

    if (which == 1)
    {
        result.push_back("green");
    }
    else if (which == 2)
    {
        result.push_back("small");
    }
    else if (which == 3)
    {
        result.push_back("rabid");
    }
    else if (which == 4)
    {
        result.push_back("quick");
    }
}

// <article> ::= the | a 
void Article()
{
    int which = (choice % 2) + 1;
    choice++;

    if (which == 1)
    {
        result.push_back("the");
    }
    else if (which == 2)
    {
        result.push_back("a");
    }
}

// <intrans-verb> ::= slept | jumped | walked | swam 
void IntransVerb()
{
    int which = (choice % 4) + 1;
    choice++;

    if (which == 1)
    {
        result.push_back("slept");
    }
    else if (which == 2)
    {
        result.push_back("jumped");
    }
    else if (which == 3)
    {
        result.push_back("walked");
    }
    else if (which == 4)
    {
        result.push_back("swam");
    }
}

// <trans-verb> ::= struck | saw | bit | took 
void TransVerb()
{
    int which = (choice % 4) + 1;
    choice++;

    if (which == 1)
    {
        result.push_back("struck");
    }
    else if (which == 2)
    {
        result.push_back("saw");
    }
    else if (which == 3)
    {
        result.push_back("bit");
    }
    else if (which == 4)
    {
        result.push_back("took");
    }
}

// <noun> ::= man | dog | fish | computer | waves 
void Noun()
{
    int which = (choice % 5) + 1;
    choice++;

    if (which == 1)
    {
        result.push_back("man");
    }
    else if (which == 2)
    {
        result.push_back("dog");
    }
    else if (which == 3)
    {
        result.push_back("fish");
    }
    else if (which == 4)
    {
        result.push_back("computer");
    }
    else if (which == 5)
    {
        result.push_back("waves");
    }
}

// <prep-phrase> ::= <preposition> <noun-phrase> | <empty> 
void PrepPhrase()
{
    int which = (choice % 2) + 1;
    choice++;

    if (which == 1)
    {
        Preposition();
        NounPhrase();
    }
    else if (which == 2)
    {
        Empty();
    }
}

// <intrans-verb-phrase> ::= <intrans-verb> | <adverb> <intrans-verb> 
void IntransVerbPhrase()
{
    int which = (choice % 2) + 1;
    choice++;

    if (which == 1)
    {
        IntransVerb();
    }
    else if (which == 2)
    {
        Adverb();
        IntransVerb();
    }
}

// <verb-phrase> ::= <trans-verb> | <adverb> <trans-verb> 
void VerbPhrase()
{
    int which = (choice % 2) + 1;
    choice++;

    if (which == 1)
    {
        TransVerb();
    }
    else if (which == 2)
    {
        Adverb();
        TransVerb();
    }
}

// <modifier> ::= <adjective> | <adverb> <adjective> 
void Modifier()
{
    int which = (choice % 2) + 1;
    choice++;

    if (which == 1)
    {
        Adjective();
    }
    else if (which == 2)
    {
        Adverb();
        Adjective();
    }
}

// <modified-noun> ::= <noun> | <modifier> <noun> 
void ModifiedNoun()
{
    int which = (choice % 2) + 1;
    choice++;

    if (which == 1)
    {
        Noun();
    }
    else if (which == 2)
    {
        Modifier();
        Noun();
    }
}

// <noun-phrase> ::= <article> <modified-noun> 
void NounPhrase()
{
    Article();
    ModifiedNoun(); 
}

// <object> ::= <noun-phrase> 
void Object()
{
    NounPhrase();
}

// <subject> ::= <noun-phrase> 
void Subject()
{
    NounPhrase();
}

// <intrans-sentence> ::= <subject> <intrans-verb-phrase> <prep-phrase> 
void IntransSentence()
{
    Subject();
    IntransVerbPhrase();
    PrepPhrase(); 
}

// <trans-sentence> ::= <subject> <verb-phrase> <object> <prep-phrase> 
void TransSentence()
{
    Subject();
    VerbPhrase();
    Object();
    PrepPhrase(); 
}

// <sentence> ::= <trans-sentence> | <sentence> ::= <intrans-sentence> 
void Sentence()
{
    int which = (choice % 2) + 1;
    choice++;

    if (which == 1)
    {
        TransSentence();
    }
    else if (which == 2)
    {
        IntransSentence();
    }
}

// -----------------------------------------------------------------------------

void Generate()
{
    result.clear();

    if (buffer == "sentence")
    {
        Sentence();
    }
    else if (buffer == "trans-sentence")
    {
        TransSentence();
    }
    else if (buffer == "intrans-sentence")
    {
        IntransSentence();
    }
    else if (buffer == "subject")
    {
        Subject();
    }
    else if (buffer == "object")
    {
        Object();
    }
    else if (buffer == "noun-phrase")
    {
        NounPhrase();
    }
    else if (buffer == "modified-noun")
    {
        ModifiedNoun();
    }
    else if (buffer == "modifier")
    {
        Modifier();
    }
    else if (buffer == "verb-phrase")
    {
        VerbPhrase();
    }
    else if (buffer == "intrans-verb-phrase")
    {
        IntransVerbPhrase();
    }
    else if (buffer == "prep-phrase")
    {
        PrepPhrase();
    }
    else if (buffer == "noun")
    {
        Noun();
    }
    else if (buffer == "trans-verb")
    {
        TransVerb();
    }
    else if (buffer == "intrans-verb")
    {
        IntransVerb();
    }
    else if (buffer == "article")
    {
        Article();
    }
    else if (buffer == "adjective")
    {
        Adjective();
    }        
    else if (buffer == "adverb")
    {
        Adverb();
    }
    else if (buffer == "preposition")
    {
        Preposition();
    }
    else if (buffer == "empty")
    {
        Empty();
    }
}

// -----------------------------------------------------------------------------

void PrintSolution()
{
    int word_count = result.size();
    if (word_count == 0)
    {
        putchar('\n');
        return;
    }
    for (int i = 0; i < word_count; i++)
    {
        printf("%s", result[i].c_str());
        putchar((i == word_count - 1) ? '\n' : ' ');
    }
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    while (std::cin >> buffer)
    {
        Generate();
        PrintSolution();
    }
    return 0;
}