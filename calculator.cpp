#include <iostream>
#include <functional>


using arithmeticFnc = std::function<int(int,int)>;

int getInteger()
{
    do
    {
        std::cout << "Enter integer: ";
        int i{};

        std::cin >> i;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Input is not an integer!\n";
        }
        else
        {
            return i;
        }
        
    } while (1);

    return 0;
}

char getOp()
{
    do
    {
        std::cout << "Enter operation: ";
        char c{};

        std::cin >> c;
        if (std::cin.fail() || (c != '+' && c != '-' && c != '*' && c != '/'))
        {
            std::cout << "Operation is not valid!\n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            return c;
        }
    } while (1);

    return '+';
}

int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a-b;
}

int multiply(int a, int b)
{
    return a*b;
}

int divide(int a, int b)
{
    return a / b;
}

arithmeticFnc getArithmeticFunction(char c)
{
    switch(c)
    {
        case '+':
            return add;
        case '-':
            return subtract;
        case '*':
            return multiply;
        case '/':
            return divide;
    }
}

int main()
{
    int     a{ getInteger()};
    char    op{ getOp()};
    int     b{ getInteger()};

    std::cout << a << ' ' << op << ' ' << b << " = " << getArithmeticFunction(op)(a,b) << '\n'; 

    return 0;
}