#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
    int job_no;
    int units;
    int profit;
} jobs;

void bubble_sort(jobs job[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(job[i].profit > job[j].profit){
                swap(job[i], job[j]);
            }
        }
    }
}

void maxProfit(jobs job[], int n, int max_cap){
    bubble_sort(job, n);
    int cap = 0;
    int max_profit = 0;
    jobs temp[n];
    int k = 0;
    for (int i = n-1; i >= 0; i--)
    {
        cap += job[i].units;
        if(cap < max_cap){
            max_profit += job[i].profit;
            temp[k] = job[i];
            k++;
        } else {
            cap-= job[i].units;
        }
    }
    cout << "_____________________________________________________" << endl;
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        cout << temp[i].job_no << "->" << "CPU UNITS: " << temp[i].units << " Profit: " << temp[i].profit << endl;
    }
    cout << "Max Profit: " << max_profit << endl;
    cout << "_____________________________________________________" << endl;

}

int main(){
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    jobs job[n];
    int max_cap;
    cout << "Enter the maximum capacity: ";
    cin >> max_cap;
    cout << "Enter the profit for each job: ";
    for (int i = 0; i < n; i++)
    {
        cin >> job[i].profit;
    }
    cout << "Enter the CPU Units for each job: ";
    for (int i = 0; i < n; i++)
    {
        cin >> job[i].units;
        job[i].job_no = i+1;
    }
    cout << "_____________________________________________________" << endl;
    cout << "Capacity Details" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << job[i].job_no << "->" << "CPU UNITS: " << job[i].units << " Profit: " << job[i].profit << endl;
    }
    
    maxProfit(job, n, max_cap);

return 0;
}