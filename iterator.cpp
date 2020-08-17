#include <array>
#include <iostream>
#include <iterator> // for std::begin and std::end

void test1(const std::array<int, 5> &data)
{
    auto begin{ &data[0] };
    auto end{ &data[0] + data.size() };

    std::cout << "test1\n";

    for (auto ptr{begin}; ptr != end; ++ptr)
    {
        std::cout << *ptr << '\n';
    }
}

void test2(const std::array<int,5> &data)
{
    auto begin {data.begin()};
    auto end {data.end()};

    std::cout << "test2\n";

    for (auto p{begin}; p != end; ++p)
    {
        std::cout << *p << '\n';
    }
}

void test3(const std::array<int, 5> &data)
{
    auto begin{std::begin(data)};
    auto end{std::end(data)};

    std::cout << "test3\n";

    for (auto p{begin}; p != end; ++p)
    {
        std::cout << *p << '\n';
    }
}



int main()
{
    std::array<int, 5> data { 1, 3, 5, 7, 4};

    //test1(data);
    //test2(data);
    test3(data);

    return 0;
}