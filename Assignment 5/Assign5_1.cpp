#include <iostream>
using namespace std;

bool is_clear(int arr[], int n) {
    for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
        continue;
    } else {
        return false;
    }
    }
    return true;
}

int get_max(int arr[], int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
    if (arr[i] > arr[m]) {
        m = i;
    }
    }
    return m;
}

int main() {
    int step = 0;
    int signals[] = {4, 2, 6, 4, 2, 6, 9, 10, 2, 4};
    int n = 10;
    int k = 1; // 1 to 10 rotate
    while (!is_clear(signals, n)) {
    if (k > 10) {
        k = 1;
    }
    if (signals[get_max(signals, 10)] >= k) {
        signals[get_max(signals, 10)] = signals[get_max(signals, 10)] - k;
    }
    k++;
    step++;
    }

    cout << "All signals are cleared!" << endl;

    for (int i = 0; i < n; i++) {
        cout << signals[i] << " ";
    }
    cout << endl;

    cout << "Minimum Waiting Time: " << step << endl;

    return 0;
}

