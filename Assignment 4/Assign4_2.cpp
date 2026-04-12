#include <iostream>
#include <vector>
using namespace std;

bool match(string a, string b)
{
    int m = a.length();
    int n = b.length();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        if (b[i - 1] == '*')
        {
            dp[0][i] = dp[0][i - 1];
        }
    }   

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (b[j - 1] == '?' || a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (b[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
};

int main()
{

    bool result = match("aa", "?*");
    if (result)
    {
        cout << "Matched" << endl;
    }
    else
    {
        cout << "Not Matched" << endl;
    }

    return 0;
}