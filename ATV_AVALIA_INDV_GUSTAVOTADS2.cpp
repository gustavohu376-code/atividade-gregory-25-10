#include <iostream>
#include <string>
#include <limits>

#define MAX 10

using namespace std;

struct filme {
    char titulo[80];
    int Ano;
};

struct genero {
    char nome[80];
    char descricao[80];
};

filme listaFilmes[MAX];
int contFilmes = 0;

genero listaGeneros[MAX];
int contGeneros = 0;

//Função para Cadastrar Filmes
void cadFilme(filme vet[], int i) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Titulo do filme: ";
    cin.getline(vet[i].titulo, sizeof(vet[i].titulo));

    cout << "Ano do filme: ";
    cin >> vet[i].Ano;
}

//Função para Cadastrar Generos
void cadGenero(genero vet[], int i) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Nome do genero do filme: ";
    cin.getline(vet[i].nome, sizeof(vet[i].nome));

    cout << "Descricao do filme: ";
    cin.getline(vet[i].descricao, sizeof(vet[i].descricao));
}

//Função para Mostrar Filmes
void mostrarFilme(filme vet[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Titulo: " << vet[i].titulo << endl;
        cout << "Ano: " << vet[i].Ano << endl;
    }
}

//Função para Mostrar Generos
void mostrarGenero(genero vet[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nome : " << vet[i].nome << endl;
        cout << "Descrição: " << vet[i].descricao << endl;
    }
}

void mostrarMenu() {
    cout << "1 - Cadastrar filme" << endl;
    cout << "2 - Cadastrar genero" << endl;
    cout << "3 - Exibir filmes cadastrados" << endl;
    cout << "4 - Exibir generos cadastrados" << endl;
    cout << "0 - Sair" << endl;
}

int main() {
    int opcao;

    while(true) {
        mostrarMenu();
        cin >> opcao;

        if(opcao == 0) {
            break;
        }

        switch(opcao) {
            case 1:
                if(contFilmes < MAX) {
                    cadFilme(listaFilmes, contFilmes);
                        contFilmes++;
                }
                else {
                    cout << "Vetor cheio!";
                }
                break;

            case 2:
                if(contGeneros < MAX) {
                    cadGenero(listaGeneros, contGeneros);
                        contGeneros++;
                }
                else {
                    cout << "Vetor cheio!";
                }
                break;
            case 3:
                mostrarFilme(listaFilmes, contFilmes);
                break;

            case 4:
                mostrarGenero(listaGeneros, contGeneros);
                break;



        }
    }
}
