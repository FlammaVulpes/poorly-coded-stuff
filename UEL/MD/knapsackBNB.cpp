#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Item{
    float peso;
    int valor;
};

struct Node{
    int camada; // Quão fundo esse nódulo está? Aparentemente, isso me permite evitar trabalhar com ponteiros
    int limite; // Limite superior para o valor máximo na sub-árvore desse nódulo
    int valor; // Lucro total dos nódulos partindo da raíz até esse nódulo (incluso)
    float peso; // Peso total dos nódulos partindo da raíz até esse nódulo (incluso)
};

// Compare a densidade (valor por peso) dos dois e retorne TRUE se
// a densidade de A for maior que a densidade de B e FALSO caso contrário
// Uso: realizar sort
bool compare(Item a, Item b){
    double aDensidade = (double) a.valor / a.peso;
    double bDensidade = (double) b.valor / b.peso;
    return aDensidade > bDensidade;
}

// Retorna o limite do lucro
// Encontrar a borda superior para o lucro máximo
// utilizando um algoritmo guloso
int limite(Node node, int n, int capacidade, Item arr[]){
    if(node.peso >= capacidade) return 0;
    int lucro = node.valor; // Iniciar o lucro como sendo o lucro da raíz até esse nódulo incluso
    int j = node.camada + 1;
    int pesoTotal = node.peso; // Iniciar o peso total como sendo o peso da raíz até esse nódulo incluso
    while(pesoTotal + arr[j].peso <= capacidade && j < n){ // Evitar segmentation fault E checar se o peso não estourará
        pesoTotal += arr[j].peso;
        lucro += arr[j].valor;
        j++;
    }
    // Preencher a mochila com um item parcialmente, garantindo uma solução gulosa
    // na qual a mochila está 100% preenchida [HIPÓTESE 2]
    if(j < n) lucro += (capacidade - pesoTotal) * arr[j].valor / arr[j].peso;
    return lucro;
}

// 90% kibado de um negócio feito em Java, porque eu não usaria queue nem fodendo por nunca ter ouvido falar,
// mas, também, jamais chegaria a uma (possível) solução sem ela.
int mochila(int capacidade, Item arr[], int n){
    // Organize, de forma decrescente, os itens a partir de sua densidade [HIPÓTESE 1]
    sort(arr, arr + n, compare);
    // Criar uma queue para navegar pelos nódulos:
    queue<Node> F;
    Node u, v; // Variáveis arbitrárias para posterior definição de nódulo-pai e nódulo-filho
    u.camada = -1;
    u.valor = u.peso = 0;
    F.push(u);
    /*  Note to self:
        - As filas funcionam por FIFO - First In, First Out -, isto é,
        o primeiro elemento que entrar também será o primeiro a sair.
    */

    // 1. Extrair um item de cada vez
    // 2. Calcular o lucro total de cada um dos ramos criados (nódulos-filhos)
    // 3. Salvar o topLucro;
    int topLucro = 0;
    while(!F.empty()){
        u = F.front(); // Pegue o primeiro elemento a ser retirado, no caso, o primeiro a ser colocado
        F.pop(); // Tire esse elemento da queue
        if(u.camada == -1) v.camada = 0; // Se é a camada inicial, defina a sua camada como sendo 0
        if(u.camada == n - 1) continue; // Tem nada na próxima camada? Se sim, ignore a próxima linha. Caso contrário,
        // desça um nível e calcule o lucro dos nódulos-filhos
        v.camada = u.camada + 1;
        // Qual o item da camada atual? Adicione as propriedades desse item
        // aos valores já existentes no nódulo
        v.peso = u.peso + arr[v.camada].peso; // Peso do nódulo-pai + peso do item contido na camada v (item de índice da camada de v)
        v.valor = u.valor + arr[v.camada].valor; // Mesma coisa, mas, agora, para o atributo lucro
        // Se o peso cumulativo for menor que a capacidade da mochila e o lucro é maior que o
        // lucro inicial (calculado pela heurística gulosa) OU o maior lucro possível de alguma iteração anterior
        // maior que o lucro inicial
        if(v.peso <= capacidade && v.valor > topLucro) topLucro = v.valor; // Atualize o melhor lucro

        // Vale a pena colocar v na queue? Calcular o limite para ver se sim ou não
        v.limite = limite(v, n, capacidade, arr);
        if(v.limite > topLucro) F.push(v); // Encaminhe v para a fila se e somente se o valor do seu limite
        // superar o melhor lucro obtido até o momento.

        // Realizar o mesmo procedimento, mas, dessa vez, sem retirar o item da mochila
        v.peso = u.peso;
        v.valor = u.valor;
        v.limite = limite(v, n, capacidade, arr); // Calcular um novo limite superior para o nódulo v
        if(v.limite > topLucro) F.push(v);
    }
    return topLucro;
    // Retorna o melhor lucro obtido quando não houver mais 'caminhos de nódulos' a serem analisados
}

int main(){
    // Usar #include <fstream> e fin para pegar os valores
    // Valores arbitrários para testes:
    int capacidade = 10;
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    int n = sizeof(arr)/sizeof(arr[0]); // Retorna o número de elementos em arr;
    cout << "Melhor lucro obtido: " << mochila(capacidade, arr, n) << endl;
    return 0;
}

// Como o código funciona?
/*
    - Em um primeiro momento, a mochila é preenchida de maneira gulosa (os itens que possuem a maior densidade, isto é, valor
    por unidade de massa, são inseridos na mochila até que o seu peso seja completamente preenchido, mesmo que, para isso, seja
    necessário repartir o item. Esse processo acontece dentro da função limite(), que retorna o lucro máximo com os itens disponíveis.
    - Após o limite superior inicial L ser calculado, possíveis soluções são geradas e colocadas dentro de uma fila F. Enquanto F não
    estiver vazia, o algoritmo cria sucessivas ramificações de uma árvore binária (branch), calculando, para cada combinação, o limite superior
    local L'. Se L' < L, então isso garante que qualquer combinação em um nível inferior à esse nódulo jamais terá um L' tal que L' > L,
    isto é, realiza a poda ("bound"). Assim que o algoritmo encontra um L' tal que L' < L, a melhor combinação de itens anterior à atual
    é automaticamente descartada. Assim que F estiver vazia, ou seja, não houver mais combinações a serem testadas, o algoritmo irá retornar
    o maior valor possível para os itens que podem ser colocados na mochila.
*/
// Dificuldades encontradas durante a criação do código
/*
    - A maior dificuldade fora, sem sombra de dúvidas, contornar o problema de ter que usar ponteiros para a criação da estrutura da
    árvore binária. Fora desenvolvido um método no qual o uso de ponteiros não se faz necessário, utilizando números inteiros para
    a navegação na estrutura da árvore. Para a realização das comparações, duas variáveis, u e v, são utilizadas para representar 
    as camadas.
    - Outra dificuldade encontrada foi a organização do código e a falta de conhecimento para uma implementação correta e eficiente de
    queues (filas). À princípio, uma tentativa fora feita fazendo uso de vetores, arrays unidimensionais dinâmicos, mas o código falhava
    em alguns 'edge cases', situações em que os valores são tão próximos um dos outros que podem apontar uma falha no algoritmo. Após um 
    pouco de pesquisa, aprendeu-se sobre e como implementar as queues tal qual mostrado nesse código.
*/
