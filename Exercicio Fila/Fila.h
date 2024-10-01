#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct Aluno{
    int matricula;
    float nota;
};

typedef Aluno TipoDado; //Define o tipo de dado que ser� armazenado na Fila


//Essa estrutura ser� utilizada como uma c�lula da Fila

//Item armazena o valor informado pelo usu�rio
//Nesse exemplo ser� criada uma fila de inteiros, mas poderia ser
//qualquer outro tipo de dado

//Prox � um ponteiro que aponta para outra c�lula da Fila
//Esse ponteiro ser� utilizado para apontar para a c�lula que cont�m o pr�ximo
//valor a ser Desenfileirado
struct TipoCelula{

    TipoDado Item;
    TipoCelula *Prox;
};


//Um construtor � um m�todo que deve ser executado obrigatoriamente antes da fila ser utilizada
void Fila_Construtor();

//M�todo para recuperar a mem�ria din�mica alocada para a Fila
//Ao contr�rio de um construtor, o destrutor � um m�todo que deve ser executado
//depois da fila ser utilizada
void Fila_Destrutor();

//Fun��o para indicar se a Fila est� ou n�o vazia (se exite ou n�o algum elemento armazenado)
bool Fila_Vazia();

//Fun��o para retornar a quantidade de elementos armazenados na Fila
int Fila_Tamanho();

//M�todo para adicionar elementos na Fila (Enfileirar)
//Se o elemento for Enfileirado (armazenado na Fila), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//Esse m�todo tamb�m � conhecido como Enqueue
bool Fila_Enfileirar(TipoDado Elemento);

//M�todo para remover elementos da Fila
//Se o elemento for Desenfileirado (removido da Fila), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//O Elemento na Frente da Fila � removido e retornado por refer�ncia pelo par�metro da fun��o
//Esse m�todo tamb�m � conhecido como Dequeue
bool Fila_Desenfileirar(TipoDado &Elemento);

//M�todo para retornar o elemento na frente da Fila sem reemov�-lo
//O elemento � retornado por refer�ncia pelo par�metro da fun��o
bool Fila_Frente(TipoDado &Elemento);

#endif // FILA_H_INCLUDED