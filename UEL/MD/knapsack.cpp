#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
float capacity = 20;
float minSize;

struct songs{
    float fileSize;
    float value;
};

struct fileInfo{
    float valPerUnit;
    bool wasUsed;
};

int amountOfFiles = 10;

songs info[10];
fileInfo worth[10];

void setData(){
    info[0].fileSize = 3.526;
    info[0].value = 4;
    info[1].fileSize = 3.173;
    info[1].value = 3.6;
    info[2].fileSize = 4.934;
    info[2].value = 2;
    info[3].fileSize = 5.126;
    info[3].value = 4.3;
    info[4].fileSize = 7.014;
    info[4].value = 5.2;
    info[5].fileSize = 2.927;
    info[5].value = 3.3;
    info[6].fileSize = 4.708;
    info[6].value = 4.2;
    info[7].fileSize = 3.611;
    info[7].value = 2.6;
    info[8].fileSize = 3.147;
    info[8].value = 3.2;
    info[9].fileSize = 4.206;
    info[9].value = 4;
}

void doWorth(){
    // Calculate all worth before sorting
    for(int i = 0; i < 10; i++){
        worth[i].valPerUnit = info[i].value/info[i].fileSize;
        // Also, let's make something false right now
        worth[i].wasUsed = false;
    }
    // Actually sorting via SELECTION SORT
    for(int i = 0; i < 9; i++){
        // Assume the first element if the max
        int max = i;
        // Now, loop the entire array to find if there is a higher value
        for(int j = i + 1; j < 10; j++){
            // If it is found, new max index is j
            if(worth[j].valPerUnit > worth[max].valPerUnit) max = j;
        }
        // Swap elements unless the max index is the same as i
        if(max != i) swap(worth[i].valPerUnit, worth[max].valPerUnit);
    }
}

void getMinSize(){
    for(int i = 0; i < 10; i++){
        if(i == 0) minSize = info[i].fileSize;
        else{
            if(minSize > info[i].fileSize) minSize = info[i].fileSize;
        }
    }
}

int main(){
    setData();
    doWorth();
    // Gets the minimum file size
    getMinSize();

    float diskVal = 0, usedPercentage; int i = 0;
    while(capacity > minSize || i < 10){
        if(!worth[i].wasUsed && capacity > info[i].fileSize){
            capacity -= info[i].fileSize;
            worth[i].wasUsed = true;
            diskVal += info[i].value;
            cout << "Added song " << i + 1 << " (" << info[i].fileSize << " kB) to the disk!" << endl;
            cout << "Remaining space: " << capacity << " kB" << endl;
        }
        i++;
    }
    usedPercentage = (100/20) * (20 - capacity);
    cout << "Used percentage: " << usedPercentage << "%" << endl;

    return 0;
}
