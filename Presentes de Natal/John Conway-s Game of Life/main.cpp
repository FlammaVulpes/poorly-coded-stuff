#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include <windows.h>
char fileName[] = "MapaTeste2.txt";
//MapaOscilador60.txt possui um oscilador P60
//MapaExplosion.txt possui um negócio que "explode"
//MapaWhatever.txt é algo que eu nem sei o que é, mas termina com vários blinkers P2
//MapaTeste1.txt é outro que termina com vários blinkers P2
//MapaTeste2.txt é mais um que termina com vários blinkers P2 e outras coisas

using namespace std;

void getMap(char m[30][50]){
    ifstream fin;
    fin.open(fileName);
    for(int i = 0; i < 30; i++){
        if(i != 0) fin.ignore();
        char line[52];
        fin.getline(line, 52);
        strncpy(m[i], line, 50);
    }
}

void writeMap(char m[30][50]){
    char output;
    output = 219;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 50; j++){
            if(m[i][j] == '1'){
                cout << 'o';
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int countNeighbours(char m[30][50], int x, int y){
    int numberOfNeighbours = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
                //&& (x + i >= 0 && x + i <= 29 && y + j >= 0 && y + j <= 49)
            if(i == 0 && j == 0) continue;
            if(m[x + i][y + j] == '1'){
                numberOfNeighbours++;
            }
        }
    }
    return numberOfNeighbours;
}

int main(){
    char mapDisplay[30][50], mapTick[30][50];
    int n, delay;
    cout << "Quantas iteracoes realizar? "; cin >> n;
    cout << "Quantos milissegundos para cada iteracao? "; cin >> delay;
    system("cls");
    getMap(mapDisplay);
    writeMap(mapDisplay);
    for(int q = 0; q < n; q++){
        // Limpa a tela!
        system("cls");
        // A parte para calcular o próximo mapa
        for(int i = 0; i < 30; i++){
            //cout << endl;
            for(int j = 0; j < 50; j++){
                int k = countNeighbours(mapDisplay, i, j);
                if(mapDisplay[i][j] == '1'){
                    if(k == 2 || k == 3) mapTick[i][j] = '1'; else mapTick[i][j] = '0';
                } else {
                    if(k == 3) mapTick[i][j] = '1';
                }
            }
        }
        // A parte para copiar o próximo mapa no mapa atual
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 50; j++){
                mapDisplay[i][j] = mapTick[i][j];
            }
        }
        // Printar o mapa
        writeMap(mapDisplay);
        // Dormir <delay> milissegundos
        Sleep(delay);
    }
    return 0;
}
