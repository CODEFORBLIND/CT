#include<bits/stdc++.h>
using namespace std;

int minSteps(int num){
    int steps = 0;
    while (num != 1)
    {
        if(num % 2 == 0){
            num = num/2;
            steps++;
        } else if(num % 3 == 0){
            num = num/3;
            steps++;
        } else{
            num = num - 1;
            steps++;
        }
    }
    return steps;
}

int main(){
    int steps = minSteps(5);
    cout << "Minimum number of steps: " << steps << endl;
    int steps1 = minSteps(7);
    cout << "Minimum number of steps: " << steps1 << endl;
    int steps2 = minSteps(13);
    cout << "Minimum number of steps: " << steps2 << endl;
return 0;
}
