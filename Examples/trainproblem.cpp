// Arrival times
// departure times
// min platforms that no train waits
// platforms = 1 to 10
// time = 0000 to 2359

#include<bits/stdc++.h>
using namespace std;

// int minplatforms(int arr[], int dep[], int size){
//     int plt = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i] < dep[i]){
//             if(arr[i+1] >= dep[i]){
//             } else if(arr[i+1] < dep[i]){
//                 plt++;
//             } 
//         }
//     }
//     return plt;
// }



typedef struct {
    int arr;
    int dep;
    int train_no;
} trains;

int main(){
    // int arr[] = {200, 259, 339, 359, 559};
    // int dep[] = {300, 340, 400, 600, 715};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int number = minplatforms(arr, dep, size);
    // cout << "Min number of platforms: " << number << endl;
    int num;
    cout << "Enter the number of trains: ";
    cin >> num;
    trains train[num];
    int a;
    int d;
    int t;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter train number: " << endl;
        cin >> t;

        cout << "Enter arrival time: " << endl;
        cin >> a;

        cout << "Enter departure time: " << endl;
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
    for (int i = 0; i < num; i++)
    {
        if(train[i].arr < train[i].dep){
            if(train[i+1].arr >= train[i].dep){
            } else if(train[i+1].arr < train[i].dep){
                plt++;
            } 
        }
    }
    cout << "No of platforms are: " << plt << endl;
return 0;
}