#include <iostream>
#include <map>
#include <string>
using namespace std;

bool anagram(std::string a, std::string b)
{
    std::map<char, int> map_a;
    std::map<char, int> map_b;

    for (int i = 0; i < a.length(); i++)
    {
        if (map_a.count(a[i]) == 0)
        {
            map_a[a[i]] = 1;
        }
        else
        {
            map_a[a[i]]++;
        }
    };

    for (int i = 0; i < b.length(); i++)
    {
        if (map_b.count(b[i]) == 0)
        {
            map_b[b[i]] = 1;
        }
        else
        {
            map_b[b[i]]++;
        }
    };

    return map_a == map_b;
};

int main()
{

    bool result = anagram("greate", "regate");
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