#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

using namespace std;

// Funcao auxiliar para determinar a posicao correta do aluno na pilha
void testaPosicao(float notaTempF, Aluno aluno) {
    Aluno temp;

    // Verifica se a pilha nao esta vazia
    while (!Pilha_Vazia()) {
        // Obtem o aluno no topo da pilha
        Pilha_Topo(temp);
        // Compara as notas
        if (aluno.nota > temp.nota ||
           (aluno.nota == temp.nota && aluno.matricula < temp.matricula)) {
            // Se a nova nota e maior ou em caso de empate a matricula e menor, empilha
            Pilha_Empilhar(aluno);
            return; // Retorna pois a posicao correta foi encontrada
        }
        // Se nao for a posicao correta, desempilha o topo da pilha
        Pilha_Desempilhar(temp);
        // Empilha o aluno desempilhado na fila
        Fila_Enfileirar(temp);
    }
    // Se a pilha estava vazia, empilha diretamente
    Pilha_Empilhar(aluno);
}

// Funcao principal
int main() {
    string opc; // Alterado para string para permitir "Sim" ou "Nao"
    Aluno aluno;

    // Inicializa a fila e a pilha
    Fila_Construtor();
    Pilha_Construtor();

    cout << "Instrucoes para utilizar o programa:" << endl;
    cout << "1- Voce devera incluir obrigatoriamente a matricula e a nota do aluno." << endl;
    cout << "2- A matricula nao podera repetir em mais de um aluno." << endl;

    // Recebe os dados do teclado e enfileira
    do {
        cout << "\nDigite a matricula do aluno: ";
        cin >> aluno.matricula;
        cout << "Digite a nota do aluno: ";
        cin >> aluno.nota;
        Fila_Enfileirar(aluno);

        cout << "\nDeseja adicionar uma nova matricula? (Sim/Nao): ";
        cin >> opc;

    } while (opc == "Sim" || opc == "sim"); // Aceita "Sim" ou "sim"

    // Processa a fila para ordenar na pilha
    while (Fila_Tamanho() != 0) {
        Fila_Frente(aluno); // Obtem o aluno da frente da fila
        Fila_Desenfileirar(aluno); // Remove da fila
        testaPosicao(aluno.nota, aluno); // Coloca na posicao correta da pilha
    }

    // Imprime a pilha da ordem maior para o menor
    cout << "\nAlunos em ordem de notas:" << endl;
    while (Pilha_Tamanho() != 0) {
        Pilha_Topo(aluno);
        cout << "Matricula: " << aluno.matricula << " Nota: " << aluno.nota << endl;
        Pilha_Desempilhar(aluno);
    }

    // Limpeza final
    Pilha_Destrutor();
    Fila_Destrutor();

    return 0;
}
