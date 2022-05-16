#include <string>
#include <iostream>
#include <string.h>

std::string polonesa_recursiva(std::string exp)
{
    // define a, operador e b sendo respectivamente os 3 primeiro caracteres da string
    // a e b são operandos genéricos
    std::string a(1, exp.at(0));
    std::string op(1, exp.at(1));
    std::string b(1, exp.at(2));

    // Inicializa a variável para usar no if
    size_t parentese_fechado = 0;

    // Se houver um parêntese em a, entra nesse parêntese recursivamente
    if (a.at(0) == '(')
    {
        // Resolve o parêntese
        a = polonesa_recursiva(exp.substr(1));

        // Sai do parêntese e atualiza os valores de b e op após o fechamento do parêntese
        // Por exemplo: ((x+y)*z)
        // op = 1 char depois do parêntese
        // b = 2 chars depois do parêntese
        parentese_fechado = exp.find(')');
        op = exp.at(parentese_fechado + 1);
        b = exp.at(parentese_fechado + 2);
    }

    // Resolve o parêntese do b recursivamente
    if (b.at(0) == '(')
    {
        b = polonesa_recursiva(exp.substr(parentese_fechado + 3));
    }

    // Após desempilhar todas as chamadas, o resultado fica em a
    // Por conta deste algoritmo, no final, b se torna substring de a
    if (a.find(b) != a.npos)
    {
        return a;
    }

    // Realiza a operação quando não há parênteses
    return a + b + op;
}
void polonesa(char *expressao, int N, char *saida_polonesa)
{
    // Cria string a partir do ponteiro
    std::string exp_str(expressao, N);

    // Chama a função para avaliar a expressão
    std::string saida_str = polonesa_recursiva(exp_str);

    // Cria um ponteiro para a str
    const char *ptr = saida_str.c_str();

    // Copia os dados para o buffer de saída a partir do ponteiro
    memcpy(saida_polonesa, ptr, N);
}

int main()
{
    char exp[100] = "(A+B)*(C-(F/D))";
    char saida[100];

    polonesa(exp, 100, saida);

    std::cout << saida << '\n';
}