#include <iostream>
#include "pilhaMin.hpp"

int main(){
    PilhaMin p;

    p.empilha(3);
    p.empilha(2);
    p.empilha(4);
    p.empilha(15);

    std::cout << p.obterMinimo();

    return 0;
}