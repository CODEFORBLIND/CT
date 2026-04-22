#include <cstdint>
#include <iostream>

double CalculateMedian(int a[], int n, int b[], int m)
{
    int low = 0;
    int high = n;

    while (low <= high)
    {
        int partition_a = (low + high) / 2;
        int partition_b = (n + m + 1) / 2 - partition_a;

        int max_left_a = (partition_a == 0) ? INT32_MIN : a[partition_a - 1];
        int min_right_a = (partition_a == n) ? INT32_MAX : a[partition_a];

        int max_left_b = (partition_b == 0) ? INT32_MIN : b[partition_b - 1];
        int min_right_b = (partition_b == m) ? INT32_MAX : b[partition_b];

        if (max_left_a <= min_right_b && max_left_b <= min_right_a)
        {
            if ((n + m) % 2 == 0)
            {
                int max_left = (max_left_a > max_left_b) ? max_left_a : max_left_b;
                int min_right = (min_right_a < min_right_b) ? min_right_a : min_right_b;
                return (max_left + min_right) / 2.0;
            }
            else
            {
                return (max_left_a > max_left_b) ? max_left_a : max_left_b;
            }
        }
        else if (max_left_a > max_left_b)
        {
            high = partition_a - 1;
        }
        else
        {
            low = partition_a + 1;
        }
    }

    return 0.0;
}

void solve()
{
    int n;
    std::cout << "Enter no of elements for A : ";
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int m;
    std::cout << "Enter no of elements for B : ";
    std::cin >> m;

    int b[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }

    double median = 0;
    if (n <= m)
    {
        median = CalculateMedian(a, n, b, m);
    }
    else
    {
        median = CalculateMedian(b, m, a, n);
    }

    std::cout << "Median : " << median << std::endl;
}

int main()
{
    solve();

    return 0;
}