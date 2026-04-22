#include <iostream>

int MinCost(int *usage, int months, int c1, int c3, int c6)
{
    int *dp = new int[months + 1];
    dp[0] = 0;

    for (int i = 1; i <= months; i++)
    {
        if (usage[i - 1] == 0)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            int op1 = dp[i - 1] + c1;
            int op3 = (i >= 3 ? dp[i - 3] : dp[0]) + c3;
            int op6 = (i >= 6 ? dp[i - 6] : dp[0]) + c6;

            int min_cost = op1;
            if (op3 < min_cost)
                min_cost = op3;
            if (op6 < min_cost)
                min_cost = op6;

            dp[i] = min_cost;
        }
        std::cout << dp[i] << std::endl;
    }

    int result = dp[months];
    delete[] dp;

    return result;
};

void solve()
{
    int months;
    std::cout << "Enter no of months : ";
    std::cin >> months;

    int usage[months];
    for (int i = 0; i < months; i++)
    {
        std::cout << "Enter usage for " << i + 1 << "month : ";
        std::cin >> usage[i];
    }

    int min_cost = MinCost(usage, months, 10, 30, 55);

    std::cout << "Minimun Cost to cover all active months is : " << min_cost << std::endl;
};

int main()
{
    solve();
    return 0;
}
