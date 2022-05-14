#include <stack> // Pilha genérica em C++
#include "filaDeque.hpp"

class Fila2P
{
private:
    void desempilha_p1()
    {
        while (!this->p1.empty())
        {
            this->p2.push(p1.top());
            this->p1.pop();
        }
    }

public:
    // Pilha para ‘char’
    std::stack<char> p1;

    // Pilha para ‘char’
    std::stack<char> p2;

    // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
    // implementar métodos do TAD Fila

    void enfileira(char c)
    {
        this->p1.push(c);
    }
    char desenfileira()
    {
        this->desempilha_p1();
        char c = this->p2.top();
        this->p2.pop();

        return c;
    }

    char base()
    {
        this->desempilha_p1();
        return this->p2.top();
    }
};

// testa se Fila está correta
static_assert(FilaTAD<Fila2P, char>);