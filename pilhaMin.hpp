#include <stack>
#include "pilhaDeque.hpp"

// Para pegar o valor de INT_MAX
#include <climits>

class PilhaMin : public PilhaDeque
{
private:
    int minimo = INT_MAX;
    std::stack<int> p;

public:
    void empilha(int n)
    {
        if (n < this->minimo)
        {
            this->minimo = n;
        }

        this->p.push(n);
    }
    int desempilha()
    {
        char c = this->p.top();
        this->p.pop();

        return c;
    }
    int topo()
    {
        return this->p.top();
    }
    int obterMinimo()
    {
        return this->minimo;
    }
};

static_assert(PilhaTAD<PilhaMin, int>);