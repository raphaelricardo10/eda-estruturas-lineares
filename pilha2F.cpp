#include <iostream>
#include "pilha2F.hpp"

int main(){
    Pilha2F p2f;

    p2f.empilha('a');
    p2f.empilha('b');
    p2f.empilha('c');

    std::cout << p2f.desempilha();
    std::cout << p2f.desempilha();
    std::cout << p2f.desempilha() << '\n';
}