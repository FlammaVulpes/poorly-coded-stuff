#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

void ex5(){
    double sum = 0;
    for(int i = 1; i <= 10; i++){
        if(i % 2 == 1) sum+= (float) i/(i*i);
        else sum-= (float) i/(i*i);
    }
    cout << "Sum: " << sum << endl;
}
