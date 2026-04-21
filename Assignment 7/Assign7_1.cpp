#include <iostream>

using namespace std;

struct Coord {
    int x;
    int y;
};

struct Assignment {
    int driver;
    int customer;
};

Coord drivers[105];
Coord customers[105];
Assignment assigned[105];
bool driverAssigned[105];

int abs_val(int val) {
    return val < 0 ? -val : val;
}

int main() {
    int n, m;
    
    cout << "Enter number of drivers and customers: ";
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < n; ++i) {
        cout << "Enter coordinates for Driver " << i + 1 << " (x y): ";
        cin >> drivers[i].x >> drivers[i].y;
        driverAssigned[i] = false;
    }

    for (int i = 0; i < m; ++i) {
        cout << "Enter coordinates for Customer " << i + 1 << " (x y): ";
        cin >> customers[i].x >> customers[i].y;
    }

    int assignedCount = 0;
    int totalDistance = 0;

    for (int i = 0; i < m; ++i) {
        int minDist = 1000000000;
        int closestDriver = -1;

        for (int j = 0; j < n; ++j) {
            if (!driverAssigned[j]) {
                int dist = abs_val(customers[i].x - drivers[j].x) + abs_val(customers[i].y - drivers[j].y);
                if (dist < minDist) {
                    minDist = dist;
                    closestDriver = j;
                }
            }
        }

        if (closestDriver != -1) {
            driverAssigned[closestDriver] = true;
            assigned[assignedCount].driver = closestDriver;
            assigned[assignedCount].customer = i;
            assignedCount++;
            totalDistance += minDist;
        }
    }

    cout << "\n--- Output ---\n";
    for (int i = 0; i < assignedCount; ++i) {
        cout << "Customer " << assigned[i].customer + 1 
             << " assigned to Driver " << assigned[i].driver + 1 << "\n";
    }
    cout << "Total distance: " << totalDistance << "\n";

    return 0;
}