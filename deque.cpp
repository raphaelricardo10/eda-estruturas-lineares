#include "deque.hpp"

//Driver para teste
int main()
{
    Deque d;
    d.insereInicio('a');
    d.insereInicio('b');
    d.insereFim('c');

    d.removeFim();
    d.removeInicio();

    std::cout << d.inicio();
}