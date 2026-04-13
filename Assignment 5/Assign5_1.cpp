
    // 1 -> 10
    // 2 -> 12
    // 3 -> 15
    // 4 -> 14
    
    // signal      Waiting Time
    // 1              1 -> 2 -> 3          
    // 2              0
    // 3              1  
    // 4              1 -> 2
    // total -> 6 (minimum)


#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int signal_no;
    int num_of_vehicles;
    int waiting_time;
} tsv;


void waitingTime(tsv signal[], int num){
    int min = signal[0].num_of_vehicles;
    int sum = 0;
    int index = 0;
    int k = 0;
    for (int i = 0; i < num; i++)
    {
        sum += signal[index].num_of_vehicles;
    }
    
    while (sum != 0)
    {
        for (int i = 1; i < num; i++)
        {
            if(signal[i].num_of_vehicles < min){
                min = signal[i].num_of_vehicles;
                index = i;
            }
        }
        // int x = signal[index].num_of_vehicles * 0.75;
        // int empty_val = (x == (int)x) ? (int)x : (int)x + 1;
        int empty_val = signal[index].num_of_vehicles;
        signal[index].num_of_vehicles -= empty_val;
        for (int i = 0; i < num; i++)
        {
            if(signal[i].waiting_time == 0){
                continue;
            }
            signal[i].waiting_time += empty_val;
        }
        sum -= empty_val;
    }
    
}

int main(){
    int num;
    cout << "Enter the number of signals: " ;
    cin >> num;
    cout << "Enter the number of vehicles for each signal: " << endl;
    tsv signal[num];
    for (int i = 0; i < num; i++)
    {
        cin >> signal[i].num_of_vehicles;
        signal[i].waiting_time = 0;
        signal[i].signal_no = i+1;
    }
    for (int i = 0; i < num; i++)
    {
        cout  << "Signal Number: " << signal[i].signal_no << " -> "<< signal[i].num_of_vehicles << " " << "Waiting time : "<< signal[i].waiting_time << endl;
        
    }
    cout << endl;
    waitingTime(signal, num);
    int twt = 0;
    for (int i = 0; i < num; i++)
    {
        twt += signal[i].waiting_time;
    }
    cout << "Total waiting time: " << twt << endl;

return 0;
}