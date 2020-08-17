#include <iostream>
#include <tuple>

std::tuple<int, int, double> ret()
{
    return {1, 2, 3.4};
}

int main()
{   
    std::tuple<int, int, double> t{ ret() };
    std::cout << "tuple: " << std::get<0>(t) << ' ' << std::get<1>(t) << ' ' << std::get<2>(t) << '\n';

    int a{}, b{};
    double c{};
    std::tie(a, b, c) = ret();

    std::cout << "tie: " << a << ' ' << b << ' ' << c << '\n';

    return 0;
}