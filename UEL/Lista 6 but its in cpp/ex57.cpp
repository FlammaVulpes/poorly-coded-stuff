#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp";

using namespace std;

struct studentsInfo{
    int id;
    float marks;
    int month;
    int day;
};

float avg = 0;
float standardDeviation = 0;

studentsInfo infos[10];

void getGrades(){
    for(int i = 0; i < 10; i++){
        cout << "Insert student " << i + 1 << "'s ID: "; cin >> infos[i].id;
        cout << "Insert student " << i + 1 << "'s provisional marks: "; cin >> infos[i].marks;
        cout << "Insert the month in which the essay was handed in: "; cin >> infos[i].month;
        cout << "Insert the day in which the essay was handed in: "; cin >> infos[i].day;
    }
}

void calcMarks(){
    for(int i = 0; i < 10; i++){
        if(infos[i].month <= 4 && infos[i].day <= 20){
            infos[i].marks += 10;
        } else if (infos[i].month == 5 && infos[i].day <= 2){
            infos[i].marks += 0; // no change
        } else if (infos[i].month == 5 && infos[i].day <= 30){
            infos[i].marks /= 2;
        } else { infos[i].marks = 0; }
    }
}

void calcAvg(){
    for(int i = 0; i < 10; i++){
        avg += infos[i].marks;
    }
    avg /= 10;
}

void calcStdDev(){
    for(int i = 0; i < 10; i++){
        standardDeviation += pow( (double) infos[i].marks - avg, 2);
    }
    standardDeviation /= 9;
    standardDeviation = sqrt(standardDeviation);
}

void ex57(){
    cout << "[Program] Manually fetching grades." << endl;
    getGrades();
    cout << "[Program] Calculating new marks." << endl;
    calcMarks();
    cout << "[Program] Calculating average." << endl;
    calcAvg();
    cout << "[Program] Calculating standard deviation." << endl;
    calcStdDev();
    cout << "\n\n\n \t Done!" << endl;
    cout << "Average = " << avg << "\t Standard Deviation: " << standardDeviation << endl;
}
