#include <iostream>

void merge(int array[], int start, int end, int mid)
{
    int s = start;
    int e = mid + 1;

    int temp[end];
    int x = 0;

    while (s <= mid && e <= end)
    {
        if (array[s] < array[e])
        {
            temp[x++] = array[s++];
        }
        else
        {
            temp[x++] = array[e++];
        }
    }

    while (s <= mid)
    {
        temp[x++] = array[s++];
    }

    while (e <= end)
    {
        temp[x++] = array[e++];
    }

    for (int i = 0; i < x; i++)
    {
        array[start + i] = temp[i];
    }
}

void sort(int array[], int start, int end)
{
    int mid = start + (end - start) / 2;

    if (start < end)
    {
        sort(array, start, mid);
        sort(array, mid + 1, end);
        merge(array, start, end, mid);
    }
};

void solve()
{
    int N;
    std::cout << "Enter n : ";
    std::cin >> N;

    int array[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> array[i];
    }

    sort(array, 0, N - 1);
    for (auto x : array)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    int candidate = array[0];
    int threshold = N / 3;

    int x = 0;
    while (x < N)
    {
        int j = x;
        while (array[j] == candidate)
        {
            j++;
        }

        if (j - x >= threshold)
        {
            std::cout << candidate << " " << j - x << std::endl;
        }

        candidate = array[j];
        x = j;
    }
}

int main()
{
    solve();
    return 0;
}
