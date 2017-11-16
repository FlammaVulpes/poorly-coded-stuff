#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <windows.h>

const int linhas = 25;
const int cobraComprimento = 6;

using namespace std;

struct Cobra{
    int x;
    int y;
    int t;
};

Cobra cobra[6];

char c[60][linhas];


void clearScreen(){
    system("cls");
}


int doRand(){
    return (rand() % 3) - 1;
}

void cobraMove(){
    int dx = 0, dy = 0;
    // Para ver se vai cair no mesmo lugar, se vai cair no lugar anterior ou se vai extrapolar o limite
    // Só falta arrumar essa parte do negócio sair da borda sem querer
    // E a porra da cobra se mexer, porque a vadia parou de se mexer do nada (y)
    while((dx == 0 && dy == 0) && (cobra[0].x + dx == cobra[1].x && cobra[0].y + dy == cobra[1].y)){
        dx = doRand();
        dy = doRand();
        if(cobra[0].x + dx < 60 && cobra[0].x > 0 && cobra[0].y < linhas - 1 && cobra[0].y > 0) break;
    }
    for(int i = 5; i > 0; i--){
        int tempx = cobra[i - 1].x;
        int tempy = cobra[i - 1].y;
        int tempt = cobra[i - 1].t;

        cobra[i].x = tempx;
        cobra[i].y = tempy;
        cobra[i].t = tempt - 1;
    }
    cout << dx << " " << dy << endl;

    cobra[0].x += dx;
    cobra[0].y += dy;
    cobra[0].t = 6;
}

void cFill(){
    for(int y = 0; y < linhas; y++){
        for(int x = 0; x < 60; x++){
            if(x == 0 || x == 59 || y == 0 || y == linhas - 1){
                c[x][y] = 'o';
            } else { c[x][y] = ' '; }
        }
    }
}

void cWrite(){
    cFill();
    clearScreen();
    for(int y = 0; y < linhas; y++){
        for(int x = 0; x < 60; x++){
            for(int i = 0; i < 6; i++){
                if(x == cobra[i].x && y == cobra[i].y){
                    if(cobra[i].t == 1 || cobra[i].t == 2){
                        c[x][y] = 176;
                    }
                    if(cobra[i].t == 3 || cobra[i].t == 4){
                        c[x][y] = 177;
                    }
                    if(cobra[i].t == 5 || cobra[i].t == 6){
                        c[x][y] = 178;
                    }
                }
            }
            cout << c[x][y];
        }
        cout << endl;
    }
}

void cobraStart(){
    int x = 20 + (rand() % 40);
    int y = 7 + (rand() % (linhas - 7));
    for(int i = 0; i < 6; i++){
        cobra[i].x = x - i;
        cobra[i].y = y;
        cobra[i].t = 6 - i;
    }
}

int main(){
    srand(time(NULL));
    int it;
    int v;
    cout << "Qual o tempo entre passos, em milissegundos? "; cin >> v;
    cout << "Quantas iteracoes realizar? "; cin >> it;
    cobraStart();
    for(int i = 0; i < it; i++){
        cWrite();
        cobraMove();
        Sleep(v);
    }
    return 0;
}
