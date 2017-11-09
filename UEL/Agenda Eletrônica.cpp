#include <iostream>
#include <cstring>

using namespace std;

struct pessoa{
    int is;
    char nome[40];
    char endr[50];
    char tel[16];
};

pessoa agenda[10];

void inserir(){
    int i = 0;
    while(1){
        if(i == 10){
            cout << "\tNao ha mais espaco na agenda!" << endl;
            break;
        }
        if(agenda[i].is == 0){
            cin.ignore();
            cout << "\tInsira o nome: "; cin.getline(agenda[i].nome, 40);
            cout << "\tInsira o endereco: "; cin.getline(agenda[i].endr, 50);
            cout << "\tInsira o telefone: "; cin.getline(agenda[i].tel, 16);
            agenda[i].is = 1;
            break;
        }
        i++;
    }
}

void consultar(){
    int i = 0;
    char nome[40];
    cin.ignore();
    cout << "Insira o nome do contato a ser consultado: "; cin.getline(nome, 40);
    cout << "\tProcurando contato..." << endl;
    while(1){
        if(i == 10){
            cout << "Contato nao encontrado!" << endl;
            break;
        }
        int nSize = sizeof(nome)/sizeof(nome[0]);
        if(strncmp(agenda[i].nome, nome, nSize) == 0){
            cout << "Contato encontrado!" << endl;
            cout << "\tNome: " << agenda[i].nome << endl;
            cout << "\tEndereco: " << agenda[i].endr << endl;
            cout << "\tTelefone: " << agenda[i].tel << endl;
            break;
        }
        i++;
    }
}

void remover(){
    int i = 0;
    char nome[40];
    cin.ignore();
    cout << "Insira o nome do contato a ser removido: "; cin.getline(nome, 40);
    cout << "\tProcurando contato..." << endl;
    while(1){
        if(i == 10){
            cout << "\tContato nao encontrado!" << endl;
            break;
        }
        int nSize = sizeof(nome)/sizeof(nome[0]);
        if(strncmp(agenda[i].nome, nome, nSize) == 0){
            cout << "\tContato encontrado! Removendo-o..." << endl;
            agenda[i].is = 0;
            break;
        }
        i++;
    }
}

void atualizar(){
    int i = 0;
    char nome[40];
    cin.ignore();
    cout << "\tInsira o nome do contato a ter seus dados atualizados: "; cin.getline(nome, 40);
    while(1){
        if(i == 10){
            cout << "\tContato nao encontrado!" << endl;
            break;
        }
        int nSize = sizeof(nome)/sizeof(nome[0]);
        if(strncmp(agenda[i].nome, nome, nSize) == 0){
            cout << "\tContato encontrado! Atualizando os dados..." << endl;
            cout << "\tInsira o endereco atual do contato: "; cin.getline(agenda[i].endr, 50);
            cout << "\tInsira o telefone atual do contato: "; cin.getline(agenda[i].tel, 16);
            break;
        }
        i++;
    }
}

// Falta fazer essa merda aqui
/*void ordenar(){
    int i = 0, auxi;
    char auxNome[40], auxEndr[50], auxTel[16];
    for(int a = 0; a < 10; a++){
        for(int b = a; b < 10; b++){

        }
    }
}*/

void listar(){
    int i = 0;
    while(1){
        if(i == 10) break;
        if(agenda[i].is != 0){
            cout << "\n\tContato: " << agenda[i].nome << endl;
            cout << "\tEndereco: " << agenda[i].endr << endl;
            cout << "\tTelefone: " << agenda[i].tel << endl;
        }
        i++;
    }
}

int fim(){
    cout << "Programa encerrado!" << endl;
    return 0;
}

void menu(){
    int k = 1;
    int first = 1;
    // Escrever o menu
    while(k){
        if(first == 1){cout << "Menu: " << endl; first--;} else { cout << "\n\nMenu: " << endl; }
        cout << "\t1. Inserir" << endl;
        cout << "\t2. Consultar" << endl;
        cout << "\t3. Remover" << endl;
        cout << "\t4. Atualizar" << endl;
        cout << "\t5. Ordenar" << endl;
        cout << "\t6. Listar" << endl;
        cout << "\t7. Fim - encerra o programa" << endl;
        // Ler o comando
        int n;
        cout << "\n\nInsira o comando: "; cin >> n;
        switch(n){
        case 1:
            inserir();
            break;
        case 2:
            consultar();
            break;
        case 3:
            remover();
            break;
        case 4:
            atualizar();
            break;
        /*case 5:
            ordenar();
            break;*/
        case 6:
            listar();
            break;
        case 7:
            k = fim();
            break;
        default: cout << "Numero invalido. \n\n";
        }
    }
}

int main(){
    // Inicializar a variável "is":
    for(int i = 0; i < 10; i++){
        agenda[i].is = 0;
    }
    menu();
    return 0;
}
