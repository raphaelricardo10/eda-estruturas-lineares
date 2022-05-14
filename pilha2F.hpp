#include <queue> // Pilha genérica em C++
#include "pilhaDeque.hpp"

class Pilha2F
{
private:
    // Inverte recursivamente os elementos de f1 e coloca em f2
    void inverte_p1()
    {
        if (this->f1.empty())
        {
            return;
        }

        char c = this->f1.front();
        this->f1.pop();

        this->inverte_p1();
        this->f2.push(c);
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
        this->f1.push(c);
    }
    char desempilha()
    {
        this->inverte_p1();
        char c = this->f2.front();
        this->f2.pop();

        return c;
    }

    char topo()
    {
        this->inverte_p1();
        return this->f2.front();
    }
};

// testa se Fila está correta
static_assert(PilhaTAD<Pilha2F, char>);