#ifndef DequeH
#define DequeH

#include <string>
#include <cstddef>
#include <concepts>
#include <iostream>
#include <queue>

template <typename Agregado, typename Tipo>
concept DequeTAD = requires(Agregado a, Tipo t)
{
    // requer operação de consulta ao elemento 'inicio'
    {a.inicio()};
    // requer operação de consulta ao elemento 'fim'
    {a.fim()};
    // requer operação 'insereInicio' sobre tipo 't'
    {a.insereInicio(t)};
    // requer operação 'insereFim' sobre tipo 't'
    {a.insereFim(t)};
    // requer operação 'removeInicio' e retorna tipo 't'
    {a.removeInicio()};
    // requer operação 'removeFim' e retorna tipo 't'
    {a.removeFim()};
};

class No
{
public:
    char valor;
    No *prox;
    No *ant;

    // Cria um nó sem vizinhos;
    No(char valor)
    {
        this->valor = valor;
        this->ant = 0;
        this->prox = 0;
    }

    // Cria um nó e o insere antes de outro nó
    No(char valor, No *prox)
    {
        this->valor = valor;
        this->ant = 0;
        this->prox = prox;

        prox->ant = this;
    }

    // Cria um nó e o insere depois de outro nó
    No(No *ant, char valor)
    {
        this->valor = valor;
        this->ant = ant;
        this->prox = 0;

        ant->prox = this;
    }
};

class Deque
{
private:
    // Ponteiros para os extremos
    No *primeiro;
    No *ultimo;

public:
    // Apenas retorna os valores dos ponteiros
    char inicio() { return this->primeiro->valor; }
    char fim() { return this->ultimo->valor; }

    void insereInicio(char c)
    {
        // Se o deque estiver vazio, crie um nó que será o primeiro e o último
        if (!this->primeiro)
        {
            No *no = new No(c);
            this->primeiro = no;
            this->ultimo = no;
        }
        // Senão crie um nó, corrija os apontamentos e atualize o ponteiro do primeiro nó
        else
        {
            // Sobrecarga para inserir o novo nó antes do primeiro
            No *no = new No(c, this->primeiro);
            this->primeiro = this->primeiro->ant;
        }
    }
    void insereFim(char c)
    {
        // Se o deque estiver vazio, crie um nó que será o primeiro e o último
        if (!this->ultimo)
        {
            No *no = new No(c);
            this->primeiro = no;
            this->ultimo = no;
        }
        // Senão crie um nó, corrija os apontamentos e atualize o ponteiro do último nó
        else
        {
            // Sobrecarga para inserir o novo nó depois do último
            No *no = new No(this->ultimo, c);
            this->ultimo = this->ultimo->prox;
        }
    }
    char removeInicio()
    {
        // Salva o dado a ser removido
        char c = this->primeiro->valor;

        No *segundoNo = this->primeiro->prox;

        // Desaloca a memória do primeiro nó e corrige o apontamento para o segundo
        delete this->primeiro;
        this->primeiro = segundoNo;

        return c;
    }
    char removeFim()
    {
        // Salva o dado a ser removido
        char c = this->ultimo->valor;
        No *penultimoNo = this->ultimo->ant;


        // Desaloca a memória do último nó e corrige o apontamento para o penúltimo
        delete this->ultimo;
        this->ultimo = penultimoNo;

        return c;
    }
};

static_assert(DequeTAD<Deque, char>);

#endif