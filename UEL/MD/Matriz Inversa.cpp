#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

// Eu não iria que é 100% funcional, porque, pelo que eu me lembro, tem uma brecha, mas eu não lembro qual era

using namespace std;

vector< vector<double> > v; // Matriz
vector<double> l;

int countZeroes(vector<double> p){
    int q = 0;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == 0) q++;
    }
    return q;
}


bool hasNull (vector< vector<double> > vv, int n){
    vector<double> a;
    vector<double> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a.push_back(vv[i][j]);
            b.push_back(vv[j][i]);
        }
        if(a.size() == countZeroes(a) || b.size() == countZeroes(b)) return true;
        for(int j = 0; j < n; j++){
            a.pop_back();
            b.pop_back();
        }
    }
    return false;
}

void fetchLines(int n){
    for(int i = 0; i < n; i++){
        cout << "Entre com os elementos da linha " << i + 1 << " da matriz: ";
        for(int k = 0; k < 2*n; k++){
            double input;
            if(k < n){
                cin >> input;
            } else {
                if(k == i + n){
                    input = 1;
                } else {
                    input = 0;
                }
            }
            l.push_back(input);
        }
        v.push_back(l);
        for(int i = 0; i < 2 * n; i++){
            l.pop_back();
        }
    }
}

void printMatrix(int n){
    for(int i = 0; i < n; i++){
        for(int j = n; j < 2*n; j++){
            cout << left << setw(10) << setprecision(6) << v[i][j] << " ";
        }
        cout << endl;
    }
}

void GaussJordanReduction(int n){
    // i = linhas
    for(int i = 0; i < n; i++){
        double factor;
        if(v[i][i] == 0){
            // Somar alguma linha onde v[l][i] não seja nulo
            bool found = false;
            for(int q = 0; q < n; q++){
                if(v[q][i] != 0){
                    found = true;
                    for(int p = 0; p < 2*n; p++){
                        v[i][p] += v[q][p];
                    }
                }
                if(found) break;
            }
            if(!found){
                cout << "Erro: matriz nao invertivel!" << endl;
                break;
            }
        }
        factor = v[i][i];
        // Criar o pivô em v[i][i]
        for(int k = 0; k < 2*n; k++){
            v[i][k] /= factor;
        }
        // Reduzir de linha em linha e coluna em coluna:
        for(int l = 0; l < n; l++){
            if(v[i][i] == 0) continue;
            double x = v[l][i]/v[i][i];
            if(i == l) continue;
            for(int k = 0; k < 2*n; k++){
                v[l][k] -= x * v[i][k];
                if(abs(v[l][k]) < 0.0000001) v[l][k] = 0;
            }
        }
        //printMatrix(n);
    }
}

int main(){
    int n;
    cout << "Insira a ordem da matriz: "; cin >> n;
    fetchLines(n);
    cout << endl;
    if(hasNull(v, n)){
        cout << "Matriz nao invertivel!" << endl;
        cout << "Interrompendo execucao..." << endl;
        return 0;
    }
    GaussJordanReduction(n);
    printMatrix(n);
    return 0;
}
