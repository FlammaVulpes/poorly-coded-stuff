#include <iostream>

using namespace std;

void getFib(int n){
    long long a = 1;
    long long b = 0;
    do{
        cout << a << endl;
        long long t = a;
        a += b;
        b = t;
        n--;
    } while (n > 0);
}

int main(){
    int n;
    cout << "Quantos numeros de Fibonacci calcular? "; cin >> n;
    getFib(n);
    return 0;
}
