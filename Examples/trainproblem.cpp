#include<bits/stdc++.h>
using namespace std;

typedef struct {
    int arr;
    int dep;
    int train_no;
} trains;

int main(){
    int num;
    cout << "Enter the number of trains: ";
    cin >> num;
    trains train[num];
    int a;
    int d;
    int t;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter train number: ";
        cin >> t;

        cout << "Enter arrival time: ";
        cin >> a;

        cout << "Enter departure time: ";
        cin >> d;

        train[i].train_no = t;
        train[i].arr = a;
        train[i].dep = d;
    }

    cout << "_____________________________________________________________________" << endl;
    cout << "                           TRAIN SCHEDULE" << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "Train number: " << train[i].train_no << " | ";

        cout << "Arrival time: " << train[i].arr << " | ";

        cout << "Departure time: " << train[i].dep << endl;
    }
    cout << "____________________________________________________________________" << endl;


    int plt = 0;
    int avail = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ( train[i].arr > train[j].dep){
                avail = 1;
                break;
            }

        }
        if (avail == 0){
            plt++;
        }

    }
    cout << "No of platforms are: " << plt << endl;
return 0;
}