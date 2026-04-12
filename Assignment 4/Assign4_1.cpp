#include <iostream>
#include <map>
#include <string>
using namespace std;

bool anagram(string first, string second)
{
    map<char, int> map_one;
    map<char, int> map_sec;

    for (int i = 0; i < first.length(); i++)
    {
        if (map_one.count(first[i]) == 0)
        {
            map_one[first[i]] = 1;
        }
        else
        {
            map_one[first[i]]++;
        }
    };

    for (int j = 0; j < second.length(); j++)
    {
        if (map_sec.count(second[j]) == 0)
        {
            map_sec[second[j]] = 1;
        }
        else
        {
            map_sec[second[j]]++;
        }
    };

    return map_one == map_sec;
};

int main()
{

    bool result = anagram("greate", "regate");
    // bool result = anagram("greatew", "regate");

    if (result)
    {
        cout << "Anagram!" << endl;
    }
    else
    {
        cout << "Not an Anagram!" << endl;
    }
    return 0;
}