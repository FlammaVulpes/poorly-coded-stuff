#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <time.h>

// Greedy

using namespace std;
float capacity = 150;
const int amountOfFiles = 75;

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

int random(int min, int max){ //Range is from min to max exclusive, if I'm not wrong
   static bool first = true;
   if(first){
      srand(time(NULL)); // Seed only once, so it won't generate the same numbers over and over
      first = false;
   }
   return (min + rand() % (max - min));
}

void setData(){
    for(int i = 0; i < amountOfFiles; i++){
        // Generate files ranging from 2000kB to 6000kB
        info[i].fileSize = random(2000, 6000);
        // Generate values ranging from 1 to 6
        info[i].value = random(1000, 6000);
        info[i].fileSize /= (float) 1000;
        info[i].value /= (float) 1000;

        // Display file information
        cout << info[i].fileSize << " kB " << "[" << info[i].value << "]";
        if((i+1) % 3 == 0) cout << endl; else cout << "\t";
    }
    cout << endl;
}

void doWorth(){
    // Calculate all density before sorting (and some extra stuff)
    for(int i = 0; i < amountOfFiles; i++){
        worth[i].valPerUnit = info[i].value/info[i].fileSize;
        // Let's make this false right now to ensure it won't be put twice in the CD, shall we?
        worth[i].wasUsed = false;
        // Let's also ensure the program uses the same indexes for both arrays
        worth[i].fileIndex = i;
        worth[i].fileSize = info[i].fileSize;
        worth[i].value = info[i].value;
    }
    // Actually sorting via SELECTION SORT
    for(int i = 0; i < amountOfFiles - 1; i++){
        // Assume the first element if the max
        int max = i;
        // Now, search the entire array, starting from i + 1, for a higher density
        for(int j = i + 1; j < amountOfFiles; j++){
            // If there is a higher density, then new max index is set to j
            if(worth[j].valPerUnit > worth[max].valPerUnit) max = j;
        }
        // If there is no higher density, then it is already sorted. Move on to the next index.
        if(max != i){
        // Swap elements and indexes
            swap(worth[i].valPerUnit, worth[max].valPerUnit);
            swap(worth[i].fileIndex, worth[max].fileIndex);
            swap(worth[i].fileSize, worth[max].fileSize);
            swap(worth[i].value, worth[max].value);
        }
        // Display the array sorted to maximum density
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
}

void addToDisk(){
    int i = 0;
    while(1){
        // If the file was not used AND there is enough room for it, put it on the CD
        if(!worth[i].wasUsed && (capacity - worth[i].fileSize >= 0)){
            capacity -= worth[i].fileSize;
            worth[i].wasUsed = true;
            diskVal += worth[i].value;
            cout << "Added song #" << i + 1 << " (" << worth[i].fileSize << " kB) [" << worth[i].valPerUnit <<"] to the disk!" << "\tRemaining space: " << capacity << " kB" << endl;
        }
        i++;    if(capacity < minSize || i >= amountOfFiles) break;
    }
}

int main(){
    cout << fixed << setprecision(3);
    cout << "Running the simulation with " << amountOfFiles << " files and " << capacity << " kB of storage." << endl;
    setData(); doWorth(); cout << endl;
    getMinSize();
    float usedPercentage, maxCapacity = capacity; cout << endl;
    addToDisk();
    usedPercentage = (100/maxCapacity) * (maxCapacity - capacity);
    cout << "\nUsed percentage: " << usedPercentage << "%" << endl;
    cout << "Total value: " << diskVal << endl;
    return 0;
}
