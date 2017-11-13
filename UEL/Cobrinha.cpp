#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <windows.h>
/*
    O que falta fazer:
        - Renderizar as partes da cobra;
        - Fazer o negócio pra ir movendo a cobra; OK
*/
const int linhas = 15;
const int cobraComprimento = 6;

using namespace std;

struct Cobra{
    int x;
    int y;
    int t;
};

Cobra cobra[6];

char c[60][linhas];

void cFill(){
    for(int y = 0; y < linhas; y++){
        for(int x = 0; x < 60; x++){
            if(x == 0 || x == 59 || y == 0 || y == linhas - 1) c[x][y] = 'o'; else c[x][y] = ' ';
            //cout << c[x][y];
        }
        //cout << endl;
    }
}

void cWrite(){
    for(int y = 0; y < linhas; y++){
        for(int x = 0; x < 60; x++){
            // Falta colocar para renderizar a cobra
            for(int i = 0; i < 6; i++){
                if(x == cobra[i].x && y == cobra[i].y){
                    // Atribuir aqueles negócios lá
                }
                cout << c[x][y];
            }
        }
    cout << endl;
    }
}

void cobraStart(){
    x = rand() % 60;
    y = rand() % 15;
    for(int i = 0; i < 6; i++){
        cobra[i].x = x;
        cobra[i].y = y;
        cobra[i].t = 6 - i;
    }
}

void cobraMove(){
    int dx = 0, dy = 0;
    // Para ver se vai cair no mesmo lugar, se vai cair no lugar anterior ou se vai extrapolar o limite
    while(dx == 0 && dy == 0 && (cobra[0].x + dx != cobra[1].x && cobra[0].y + du != cobra[1].y) && (cobra[0].x + dx >= 60 || cobra[0].x + dx <= 0 || cobra[0].y + dy >= 15 || cobra[0].y + dy <= 0)){
        dx = doRand();
        dy = doRand();
    }
    for(int i = 5; i > 0; i--){
        int tempx = cobra[i - 1].x;
        int tempy = cobra[i - 1).y;
        int tempt = cobra[i - 1].t;

        cobra[i].x = tempx;
        cobra[i].y = tempy;
        cobra[i].t = tempt - 1;
    }
    cobra[0].x += dx;
    cobra[0].y += dy;
    cobra[0].t = 6;
}

int doRand(){
    return (rand() % 3) - 1;
}

void clearScreen(){
    system("cls");
}

int checkNext(){
    // Usar o próximo valor como parâmetro
    return 0;
}

int main(){
    cFill();
    srand(time(NULL));
    return 0;
}
