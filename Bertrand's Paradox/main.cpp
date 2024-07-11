#include<iostream>
#include<cmath>
#include<random>

using namespace std;

// Distance from center method.

double method1(long long int iterations) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 2 * M_PI); // M_PI = 3.141....

    long long int count = 0;
    for (long long int i = 0; i < iterations; ++i) {
        double angle = dis(gen);
        double chord_length = 2 * sin(angle / 2);
        if (chord_length > sqrt(sqrt(3.0))){
            count++;
        }
    }
    return static_cast<double>(count) / iterations;
}

// Angle-chord method .

double method2(long long int iterations) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> angle(0, M_PI);

    long long int count = 0;
    for (long long int i = 0; i < iterations; ++i) {
        double ag = angle(gen);
        if(ag>(M_PI/3) && ag<(2*(M_PI/3))){
            count++;
        }
    }
    return (static_cast<double>(count) / iterations);
}

// Mid-point chord method.

double method3(long long int iterations) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 2 * M_PI); // M_PI = 3.141....

    long long int count = 0;
    for (long long int i = 0; i < iterations; ++i) {
        double angle1 = dis(gen);
        double angle2 = dis(gen);
        double chord_length = abs(sin(angle1) - sin(angle2));
        if (chord_length > sqrt(sqrt(3.0))){
            count++;
        }
    }
    return static_cast<double>(count) / iterations;
}

int main() {
    long long int iterations;
    cout << "Please input the number of iterations(< 10^8) to be executed : "<< endl;
    cout << "Caution select higher numbers to attain better simultions :)" << endl;

    cin >> iterations;
    
    cout << "Probability Simulation using method 1: " << method1(iterations) << endl;
    cout << "Probability Simulation using method 2: " << method2(iterations) << endl;
    cout << "Probability Simulation using method 3: " << method3(iterations) << endl;

    return 0;
}
