#include <iostream>
#include "filaDeque.hpp"

int main(){
    FilaDeque fd;

    fd.enfileira('a');
    fd.enfileira('b');
    fd.enfileira('c');

    std::cout << fd.desenfileira();
    std::cout << fd.desenfileira();
    std::cout << fd.desenfileira() << '\n';
}