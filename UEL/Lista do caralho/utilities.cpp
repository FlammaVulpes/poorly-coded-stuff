#include "header.hpp"
using namespace std;

void sudSort(int arr[9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 - i; ++j){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
