#include <iostream>
#include <iomanip>

#include "header.hpp"
using namespace std;

int main(){
    // Eu fiz isso na madrugada de virada de ano (porque eu me odeio) e tive a ideia de
    // fazer um menuzinho todo bonitinho, onde você digitava a string e a palavra...
    // A semana passou *voando* e eu achei que já tava 100% feito...
    // Vai ficar assim mesmo...

    char a[30] = "Thales pls"; // Meme interno para testes preliminares
    char b[30] = " kill me";

    int getposResult = my_getpos(b, a); // Deu certo!
    if(getposResult == -1) cout << "Substring nao encontrada!" << endl;
    else cout << "Localizaçao da substring: " << getposResult << endl;

    my_strcpy(a, b); // Ok, também deu certo...

    cout << "Concatenando as substrings: " << a << endl;

    char q[30] = "Thales pls";
    char w[30] = " kill me";

    my_strncat(q, w, 6); // Também deu certo...

    cout << "\"Concatenando\" strings na posicao 6: " << q << endl;

    char tpls[30] = "Thales pls kill me";
    char pls[30] = "pls ";

    my_remstr(tpls, pls); // Também deu certo, amém

    cout << "Apos a remocao: " << tpls << endl;

    // Ok, isso não deu 100% certo
    // Lembrar de arrumar isso aqui depois
    char procurar[] = "marcos";
    if(hasWord(procurar)){
        cout << "Palavra \"" << procurar << "\" encontrada!" << endl;
    } else {
        cout << "Palavra \"" << procurar << "\" nao encontrada." << endl;
    }

    return 0;
}
