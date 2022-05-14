#include "deque.hpp"

template <typename Agregado, typename Tipo>
concept PilhaTAD = requires(Agregado a, Tipo t)
{
    // requer operação 'empilha' sobre tipo 't'
    {a.empilha(t)};
    // requer operação 'desempilha' e retorna tipo 't'
    {a.desempilha()};
    // requer operação 'topo' e retorna tipo 't'
    {a.topo()};
};

class PilhaDeque
{
public:
    Deque d;

    void empilha(char c)
    {   // Adiciona um elemento no fim
        this->d.insereFim(c);
    }
    char desempilha()
    {   // Remove o elemento do fim
        return this->d.removeFim();
    }
    char topo()
    {   // Retorna o último elemento da pilha
        return this->d.fim();
    }
};

static_assert(PilhaTAD<PilhaDeque, char>);