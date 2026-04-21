#include <iostream>

void solve()
{
    int N;
    std::cout << "Enter N : ";
    std::cin >> N;

    int ads[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> ads[i];
    }

    int h1 = 0;
    int h1_key = 0;
    int h2 = 0;

    int x = 0;
    while (x < N)
    {
        if (ads[x] > h1)
        {
            h1 = ads[x];
            h1_key = x;
        }
        x++;
    }

    ads[h1_key] = 0;
    x = 0;
    while (x < N)
    {
        if (ads[x] > h2)
        {
            h2 = ads[x];
        }
        x++;
    }

    std::cout << h1 << " " << h2 << std::endl;

    int maxprofit = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2)
        {
            maxprofit += h2;
        }
        else
        {
            maxprofit += h1;
        }
    }

    std::cout << "Ads ran for " << N << " times" << std::endl;
    std::cout << "Max profit : " << maxprofit << std::endl;
}

int main()
{   
    solve();
    return 0;
}