#include "deque.hpp"

template <typename Agregado, typename Tipo>
concept FilaTAD = requires(Agregado a, Tipo t)
{
    // requer operação 'enfileira' sobre tipo 't'
    {a.enfileira(t)};
    // requer operação 'desenfileira' e retorna tipo 't'
    {a.desenfileira()};
    // requer operação 'base' e retorna tipo 't'
    {a.base()};
};

class FilaDeque
{
public:
    Deque d;

    void enfileira(char c)
    {
        // Adiciona o elemento no início da fila
        this->d.insereInicio(c);
    }
    char desenfileira()
    {
        // Remove o elemento do fim da fila
        return this->d.removeFim();
    }
    char base()
    {
        // Retorna o próximo elemento a sair da fila
        return this->d.fim();
    }
};

static_assert(FilaTAD<FilaDeque, char>);