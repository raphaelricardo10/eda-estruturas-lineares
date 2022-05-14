#include <iostream>
#include "fila2P.hpp"

int main(){
    Fila2P f2p;

    f2p.enfileira('a');
    f2p.enfileira('b');
    f2p.enfileira('c');

    std::cout << f2p.desenfileira();
    std::cout << f2p.desenfileira();
    std::cout << f2p.desenfileira() << '\n';
}