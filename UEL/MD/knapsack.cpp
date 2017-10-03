#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <time.h>

// Greedy

using namespace std;
float capacity = 120;
const int amountOfFiles = 60;

float minSize, diskVal = 0;

struct songs{
    float fileSize;
    float value;
};

struct fileInfo{
    float valPerUnit;
    bool wasUsed;
    int fileIndex;
    float fileSize;
    float value;
};

songs info[amountOfFiles];
fileInfo worth[amountOfFiles];

int random(int min, int max){ //Range = [min, max]
   static bool first = true;
   if(first){
      srand(time(NULL)); // Seed only once
      first = false;
   }
   return (min + rand() % (max - min));
}

void setData(){
    /*
    info[0].fileSize = 3.526;
    info[0].value = 4; */
    for(int i = 0; i < amountOfFiles; i++){
        info[i].fileSize = random(2000, 6000);
        info[i].value = random(1000, 6000);
        info[i].fileSize /= (float) 1000;
        info[i].value /= (float) 1000;

        cout << info[i].fileSize << " kB " << "[" << info[i].value << "]";
        if((i+1) % 3 == 0) cout << endl; else cout << "\t";
    }
    cout << endl;
}

void doWorth(){
    // Calculate all worth before sorting
    for(int i = 0; i < amountOfFiles; i++){
        worth[i].valPerUnit = info[i].value/info[i].fileSize;
        // Also, let's make something false right now
        worth[i].wasUsed = false;
        // Also², let's make sure the program uses the same indexes for both arrays
        worth[i].fileIndex = i;
        worth[i].fileSize = info[i].fileSize;
        worth[i].value = info[i].value;
    }
    // Actually sorting via SELECTION SORT
    for(int i = 0; i < amountOfFiles - 1; i++){
        // Assume the first element if the max
        int max = i;
        // Now, loop the entire array to find if there is a higher value
        for(int j = i + 1; j < amountOfFiles; j++){
            // If it is found, new max index is j
            if(worth[j].valPerUnit > worth[max].valPerUnit) max = j;
        }
        // Swap elements unless the max index is the same as i
        // Swap indexes as well
        if(max != i){
            swap(worth[i].valPerUnit, worth[max].valPerUnit);
            swap(worth[i].fileIndex, worth[max].fileIndex);
            swap(worth[i].fileSize, worth[max].fileSize);
            swap(worth[i].value, worth[max].value);
        }
        cout << worth[i].fileSize << " kB " << "[V/U = " << worth[i].valPerUnit << "]";
        if((i+1) % 3 == 0) cout << endl; else cout << "\t";
    }
}

void getMinSize(){
    for(int i = 0; i < amountOfFiles - 1; i++){
        if(i == 0) minSize = worth[i].fileSize;
        else{
            if(minSize > worth[i].fileSize) minSize = worth[i].fileSize;
        }
    }
    cout << minSize << endl;
}

void addToDisk(){
    int i = 0;
    while(1){
        if(!worth[i].wasUsed && (capacity - worth[i].fileSize >= 0)){
            capacity -= worth[i].fileSize;
            worth[i].wasUsed = true;
            diskVal += worth[i].value;
            cout << "Added song " << i + 1 << " (" << worth[i].fileSize << " kB) [" << worth[i].valPerUnit <<"] to the disk!" << "\tRemaining space: " << capacity << " kB" << endl;
        }
        i++;
        if(capacity < minSize || i >= amountOfFiles) break;
    }
}

int main(){
    cout << fixed << setprecision(3);
    cout << "Running the simulation with " << amountOfFiles << " files and " << capacity << " MB of storage." << endl;
    setData();
    doWorth();
    cout << endl;
    // Gets the minimum file size
    getMinSize();

    float usedPercentage, maxCapacity = capacity;
    cout << endl;
    // Loop some times (in this case, 4) to guarantee it can fetch the most disks
    addToDisk();
    usedPercentage = (100/maxCapacity) * (maxCapacity - capacity);
    cout << "\nUsed percentage: " << usedPercentage << "%" << endl;
    cout << "Total value: " << diskVal << endl;

    return 0;
}
