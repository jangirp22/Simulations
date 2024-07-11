#include<bits/stdc++.h>
using namespace std;

int number_of_students(double p){
    double probability = 0;
    int k = 2;
    long long int execution = 0;
    while(1){
         probability = 1.0 - exp(-k * (k - 1) / (2.0 * 365));
        if(probability > p){
            break;
        }
        else{
            k++;
        }
        execution++;
        if(execution > 100000000){
            break;
        }
    }
    return k;
}

int main(){
    double p;
    cout << "Enter a valid probability threshold : \n";
    cin >> p;
    if(p>0 && p<1){
        int k = number_of_students(p);
        cout << "Number of students to have probability greater than " << p << " = " << k << ".\n";
    }
    else{
        cout << "Invalid probability threshold given.\n";
    }

    return 0;
}
