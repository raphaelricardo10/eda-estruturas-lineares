#include <iostream>
#include <stack>
#include <queue>

void inverte_1p(std::queue<char> *f)
{
    std::stack<char> p;

    // Envia todos os dados para a pilha
    while (!f->empty())
    {
        p.push(f->front());
        f->pop();
    }

    // Envia todos os dados de volta para a fila
    while (!p.empty())
    {
        f->push(p.top());
        p.pop();
    }
}

void inverte_2f(std::queue<char> *f)
{
    std::queue<char> f1;
    std::queue<char> f2;

    // Itera sobre todos os elementos de f
    // Para cada dado em f:
    // Esvazia f1 antes de inserir um dado e copia para f2
    // Insere um dado de f em f1
    // Devolve os valores de f2 para f1

    while (!f->empty())
    {
        // Copia f1 para f2
        while (!f1.empty())
        {
            f2.push(f1.front());
            f1.pop();
        }
        // Insere o dado de f em f2
        f1.push(f->front());
        f->pop();

        // Copia f2 para f2
        while (!f2.empty())
        {
            f1.push(f2.front());
            f2.pop();
        }
    }

    // Copia f1 para f
    while (!f1.empty())
    {
        f->push(f1.front());
        f1.pop();
    }
}

// Função auxiliar para gerar valores de teste
void alimenta_fila(std::queue<char> *f)
{
    f->push('a');
    f->push('b');
    f->push('c');
}

// Percore a fila e imprime os valores
void le_fila(std::queue<char> *f)
{
    while (!f->empty())
    {
        std::cout << f->front();
        f->pop();
    }
    std::cout << "\n\n";
}

int main()
{
    std::queue<char> f;
    
    alimenta_fila(&f);
    inverte_1p(&f);
    le_fila(&f);

    alimenta_fila(&f);
    inverte_2f(&f);
    le_fila(&f);

    return 0;
}