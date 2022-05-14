#include <iostream>
#include "pilhaDeque.hpp"

int main(){
    PilhaDeque pd;

    pd.empilha('a');
    pd.empilha('b');
    pd.empilha('c');

    std::cout << pd.desempilha();
    std::cout << pd.desempilha();
    std::cout << pd.desempilha() << '\n';

    return 0;
}