#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

double x, y;
double sx = 0, sy = 0, sxy = 0, sx2 = 0, sy2 = 0;

double ca, cb;

void sumx(double a){
    sx += a;
}

void sumy(double a){
    sy += a;
}

void sumxy(double a, double b){
    sxy += a * b;
}

void sumx2(double a){
    sx2 += pow((double) a, 2);
}

void sumy2(double a){
    sy2 += pow((double) a, 2);
}

void ex65(){
    int n = 0;
    while(1){
        cout << "Insert (x, y) coordinates: "; cin >> x >> y;
        if(x == 0 && y == 0){ break; }
        // Calculate the summations
        sumx(x);
        sumy(y);
        sumxy(x, y);
        sumx2(x);
        sumy2(y);
        n++;
    }
    // Calculate the coefficients
    ca = (double) (n*sxy - (sx * sy))/((n*sx2) - pow((double) sx, 2));
    cb = (double) ((sy*sx2) - (sx*sxy))/(((double) n*sx2) - pow((double) sx, 2));
    //cb = (double) (1/n) * (sy - (ca * sx));
    double R;
    R = (double) ((n*sxy) - (sx*sy))/(sqrt((n*sx2) - pow((double) sx, 2) * ((n*sy2) - pow((double) sy, 2))));
    cout << "Coefficients: " << endl;
    cout << "\ta = " << ca << endl;
    cout << "\tb = " << cb << endl;
    cout << "\tR = " << R << endl;
    cout << "y = " << ca << "x + " << cb << endl;
}
