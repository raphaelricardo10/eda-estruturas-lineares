#include <queue> // Pilha genérica em C++
#include "pilhaDeque.hpp"

class Pilha2F
{
private:
    // Inverte recursivamente os elementos de f1 e coloca em f2
    void desenfileira_f1()
    {
        while (!this->f1.empty())
        {
            this->f2.push(this->f1.front());
            this->f1.pop();
        }
    }
    void enfileira_f1()
    {
        while (!this->f2.empty())
        {
            this->f1.push(this->f2.front());
            this->f2.pop();
        }
    }

public:
    // Fila para ‘char’
    std::queue<char> f1;

    // Fila para ‘char’
    std::queue<char> f2;

    // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
    // implementar métodos do TAD Fila

    void empilha(char c)
    {
        this->desenfileira_f1();
        this->f1.push(c);
        this->enfileira_f1();
    }
    char desempilha()
    {
        char c = this->f1.front();
        this->f1.pop();

        return c;
    }

    char topo()
    {
        return this->f1.front();
    }
};

// testa se Fila está correta
static_assert(PilhaTAD<Pilha2F, char>);