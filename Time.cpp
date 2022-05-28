//Time.cpp
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <clocale>
using namespace std;

//definição de tipos de dados
struct NOLLL{
    int id, vitoria, empate, derrota;
    string time;
    NOLLL *prox, *ant;
};

//definição de variáveis globais
NOLLL *il, *fl, *aux, *aux2, *aux3;
char conf;
bool sinal;

//protótipos de funções
void LLL_01_InsFIM();       //inserir no fim
void LLL_02_Imprimir();   //imprimir a lista
void LLL_03_Imprimir_V_E();   //imprimir a lista Vitoria Empate
void LLL_04_Inserir_Antes(); //Procurar e Inserir antes
void LLL_05_Remover();      // Procurar no e Remover
void LLL_06_Remover_K();      // Procurar nó e remover anterior
void LLL_07_Imprimir_X(); //Imprimir a quantidade de nós com vitórias pares com valor menor ou igual a x!

//programa principal
int main () {
    setlocale(LC_ALL, "Portuguese");
    il = NULL; //inicia a lista vazia
    fl = NULL; //Fim da lista vazia

    //menu de opções
    char op = 'X';
    while (op != '0'){
        system("cls");
        cout << "\t\tTrabalho AED1 Segundo Semestre\n\n";
        cout << "\t\tGabriel Mossini\n\n";

        //imprimir opções do menu
        cout << "\n\t 0 - Sair";
        cout << "\n\t 1 - Inserir no fim da lista!";
        cout << "\n\t 2 - Imprimir a lista";
        cout << "\n\t 3 - Verificar na lista os times com a mesma quantidade de empates e vitórias!";
        cout << "\n\t 4 - Procurar um nó e inserir antes!";
        cout << "\n\t 5 - Procurar um nó e remover!";
        cout << "\n\t 6 - Remover na k - 1!";
        cout << "\n\t 7 - Imprimir a quantidade de nós com vitórias pares com valor menor ou igual a x!";
        // demais opções do menu

        cout << "\n\n\tEscolha uma opção: ";
        fflush(stdin);
        cin >> op;
        fflush(stdin);
        op = toupper(op); // se for usar maiuscula e minuscala no menu não usar toupper

        //executar as funções conforme a escolha
        switch (op){
            case '0': cout << "\n\n\t\tObrigado por usar nosso sistema!!!\n\n"; break;
            case '1': LLL_01_InsFIM(); break;
            case '2': LLL_02_Imprimir(); break;
            case '3': LLL_03_Imprimir_V_E(); break;
            case '4': LLL_04_Inserir_Antes(); break;
            case '5': LLL_05_Remover(); break;
            case '6': LLL_06_Remover_K(); break;
            case '7': LLL_07_Imprimir_X(); break;
            default: cout << "\n\n\t\tOpção Inválida!!!\n\n"; break;
        }
        cout << endl << "\t";
        system("pause");
    }
}

//corpo das funções
//inserir novo nó no fim da lista
void LLL_01_InsFIM(){
    sinal = false;
    aux = new(NOLLL);  //aloca(aux);
    system("cls");
    cout << "\t\tInserir novo nó no fim da Lista\n\n";
    if (aux != NULL) {
        cout << "\t\tInforme o ID: ";
        cin >> (*aux).id; // ^aux.id; notação de linguagem C
               //aux->id // notação de referência de memória usada em C++

        fflush(stdin);
        cout << "\n\t\tInforme uma Descrição: ";
        getline(cin, aux->time); //utilizou notação de C++,
                                 //o getline serve para ler nomes compostos

        cout << "\n\t\tInforme as Vitorias: ";
        cin >> (*aux).vitoria; // ^aux.id; notação de linguagem C
        //aux->id // notação de referência de memória usada em C++

        cout << "\n\t\tInforme os Empates: ";
        cin >> (*aux).empate; // ^aux.id; notação de linguagem C
        //aux->id // notação de referência de memória usada em C++

        cout << "\n\t\tInforme as Derrotas: ";
        cin >> (*aux).derrota; // ^aux.id; notação de linguagem C
        //aux->id // notação de referência de memória usada em C++

        fflush(stdin);
        cout << "\n\t\tConfirma (S/N):";
        cin >> conf;
        conf = toupper(conf); //converte caracater para maiusculo

        if (conf=='S'){
            (*aux).prox = NULL;
            if (il == NULL){
                il = aux;
            }

            else {
                aux2 = new(NOLLL);
                aux2 = il;
                while(aux2->prox != NULL){
                    aux2 = aux2->prox;
                }

                (*aux2).prox = aux; //vai receber endereço do novo nó
                (*aux).ant = aux2;
            }

            fl = aux;
            sinal = true;
        }
        else { cout << "\n\t\tDados não confirmados\n";
               delete(aux); //libera o endereço de memória - libera(aux)
             }
    }
    else cout << "\n\t\tOverflow - Memória insuficiente\n";

}

//imprimir a lista
void LLL_02_Imprimir(){
    system("cls");
    cout << "\t\tImprimir Lista Ligada de Informações\n\n";
    if (il != NULL){
        cout << setw(10) << "ENDEREÇO" << setw(5) << "ID" << setw(25) << "TIME" << setw(10) << "VITORIA" << setw(10) << "EMPATE" << setw(10) << "DERROTA" << setw(10) << "PRÓXIMO" << endl;
        for(int i=0; i<82; i++) cout << "-";  // imprime uma linha para separar os dados
        cout << endl;
        //IMPRIMIR A LISTA
        aux = il;
        int cont=0; // varivel usada para contar os valores impressos
        while(aux != NULL){
           //cout << setw(10) << &aux << setw(5) << (*aux).id << setw(25) << (*aux).info << setw(10) << (*aux).prox << endl;
           cout << setw(10) << aux << setw(5) << aux->id << setw(25) << aux->time << setw(10) << aux->vitoria << setw(10) << aux->empate << setw(10) << aux->derrota << setw(10) << aux->prox << endl;
           aux = aux->prox;
           cont++;
        }
        for(int i=0; i<82; i++) cout << "-"; // imprime uma linha para separar os dados
        cout << "\n\t\tTotal de Informações impressas: " << cont << endl;
    }
    else cout << "\n\n\t\tLista Vazia!!!";
}

//verificar na lista os times com mesmo número de empates e vitorias
void LLL_03_Imprimir_V_E(){
    system("cls");
    cout << "\t\tVerificar na lista os times com mesmo número de empates e vitorias\n\n";
    if (il != NULL){
        cout << setw(10) << "ENDEREÇO" << setw(5) << "ID" << setw(25) << "TIME" << setw(10) << "VITORIA" << setw(10) << "EMPATE" << setw(10) << "DERROTA" << setw(10) << "PRÓXIMO" << endl;
        for(int i=0; i<82; i++) cout << "-";  // imprime uma linha para separar os dados
        cout << endl;
        //IMPRIMIR A LISTA
        aux = il;
        int cont=0; // varivel usada para contar os valores impressos
        while(aux != NULL){
            if(aux->vitoria == aux->empate){
           //cout << setw(10) << &aux << setw(5) << (*aux).id << setw(25) << (*aux).info << setw(10) << (*aux).prox << endl;
           cout << setw(10) << aux << setw(5) << aux->id << setw(25) << aux->time << setw(10) << aux->vitoria << setw(10) << aux->empate << setw(10) << aux->derrota << setw(10) << aux->prox << endl;
           }
           aux = aux->prox;
           cont++;
        }
        for(int i=0; i<82; i++) cout << "-"; // imprime uma linha para separar os dados
        cout << "\n\t\tTotal de Informações impressas: " << cont << endl;
    }
    else cout << "\n\n\t\tLista Vazia!!!";
}

//Imprimir a quantidade de nós com vitórias pares com valor menor ou igual a x!
void LLL_07_Imprimir_X(){
    system("cls");
    cout << "\t\tImprimir a quantidade de nós com vitórias pares com valor menor ou igual a x!\n\n";
    if (il != NULL){
        cout << "\n\n\t\tDigite o Valor de X: ";
        int x;
        cin >> x;
        cout << endl << endl;
        cout << setw(10) << "ENDEREÇO" << setw(5) << "ID" << setw(25) << "TIME" << setw(10) << "VITORIA" << setw(10) << "EMPATE" << setw(10) << "DERROTA" << setw(10) << "PRÓXIMO" << endl;
        for(int i=0; i<82; i++) cout << "-";  // imprime uma linha para separar os dados
        cout << endl;
        //IMPRIMIR A LISTA
        aux = il;
        int cont=0; // varivel usada para contar os valores impressos
        while(aux != NULL){
            if(aux->vitoria %2 == 0 && aux->vitoria <= x){
           //cout << setw(10) << &aux << setw(5) << (*aux).id << setw(25) << (*aux).info << setw(10) << (*aux).prox << endl;
           cout << setw(10) << aux << setw(5) << aux->id << setw(25) << aux->time << setw(10) << aux->vitoria << setw(10) << aux->empate << setw(10) << aux->derrota << setw(10) << aux->prox << endl;
           }
           aux = aux->prox;
           cont++;
        }
        for(int i=0; i<82; i++) cout << "-"; // imprime uma linha para separar os dados
        cout << "\n\t\tTotal de Informações impressas: " << cont << endl;
    }
    else cout << "\n\n\t\tLista Vazia!!!";
}

//Procurar um nó e inserir antes!"
void LLL_04_Inserir_Antes(){
    sinal = false;
    aux = new(NOLLL);  //aloca(aux);
    aux2 = new(NOLLL);
    system("cls");
    cout << "\t\tProcurar um nó e inserir antes!\n\n";
    int codigo;
    cout << "\n\t\tDigite o ID que esta sendo procurado para inserir antes: ";
    cin >> codigo;

    (*aux).prox = NULL;
    if (il == NULL){
        il = aux;
    }

    else {
        aux = il;
        while(aux->prox != NULL && aux->id != codigo){
            aux = aux->prox;
        }
    }

    if (aux->id == codigo){
        if (aux2 != NULL) {
            cout << "\t\tInforme o ID: ";
            cin >> (*aux2).id; // ^aux.id; notação de linguagem C
                   //aux->id // notação de referência de memória usada em C++

            fflush(stdin);
            cout << "\n\t\tInforme o nome do Time: ";
            getline(cin, aux2->time); //utilizou notação de C++,
                                     //o getline serve para ler nomes compostos

            cout << "\n\t\tInforme as Vitorias: ";
            cin >> (*aux2).vitoria; // ^aux.id; notação de linguagem C
            //aux->id // notação de referência de memória usada em C++

            cout << "\n\t\tInforme os Empates: ";
            cin >> (*aux2).empate; // ^aux.id; notação de linguagem C
            //aux->id // notação de referência de memória usada em C++

            cout << "\n\t\tInforme as Derrotas: ";
            cin >> (*aux2).derrota; // ^aux.id; notação de linguagem C
            //aux->id // notação de referência de memória usada em C++

            fflush(stdin);
            cout << "\n\t\tConfirma (S/N):";
            cin >> conf;
            conf = toupper(conf); //converte caracater para maiusculo
        }
        if (conf=='S') {
            aux3 = new(NOLLL);
            aux3 = (*aux).ant;

            if (aux == il) {
                (*aux).ant = aux2;
                (*aux2).prox = aux;
                il = aux2;
            }

            else {
                (*aux3).prox = aux2;
                (*aux2).prox = aux;
                (*aux).ant = aux2;   //recebe o anterior do encontrado
            }
            sinal = true;
        }
        else { cout << "\n\t\tDados não confirmados\n";
            delete(aux2); //libera o endereço de memória - libera(aux)
        }
    }
}

//Procurar um nó e Remover"
void LLL_05_Remover(){
    sinal = false;
    aux = new(NOLLL);  //aloca(aux);
    system("cls");
    cout << "\t\tProcurar um nó e remover!\n\n";
    int codigo;
    cout << "\n\t\tDigite o ID para remover: ";
    cin >> codigo;

    aux = il;
    while(aux->prox != NULL && aux->id != codigo){
        aux = aux->prox;
    }

    if (aux->id == codigo){
        if (aux != il && aux != fl){
            aux2 = (*aux).ant;
            aux3 = (*aux).prox;
            (*aux2).prox = aux3;
            (*aux3).ant = aux2;
        }
        else if(aux == il && aux != fl) {
            aux2 = (*aux).prox;
            il = aux2;
        }
            else if (aux != il && aux == fl){
                aux2 = (*aux).ant;
                (*aux2).prox = NULL;
                fl = aux2;
            }
                else {
                    il = NULL;
                    fl = NULL;
                }
    }
}

//Procurar nó e remover no anterior
void LLL_06_Remover_K(){
    sinal = false;
    aux = new(NOLLL);  //aloca(aux);
    system("cls");
    cout << "\t\tProcurar um nó e remover no anterior!\n\n";
    int codigo;
    cout << "\n\t\tDigite o ID para remover o anterior: ";
    cin >> codigo;

    aux = il;
    while(aux->prox != NULL && aux->id != codigo){
        aux = aux->prox;
    }

    if (aux->id == codigo){
        if (aux != il){
            aux2 = (*aux).ant;
            if (aux2 != il) {
                aux3 = (*aux2).ant;
                (*aux3).prox = aux;
                (*aux).ant = aux3;
            }
            else {
                (*aux).ant = NULL;
                il = aux;
            }
        }
        else{
            cout << "\n\t\tNão existe nó anterior!" << endl;
        }
    }
}
