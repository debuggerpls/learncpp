#include <iostream>
#include <array>
#include <algorithm>


bool bigger(int a, int b)
{
    return (a > b);
}

bool smaller(int a, int b)
{
    return (a < b);
}

bool evensFirst(int x, int y)
{
	// if x is even and y is odd, x goes first (no swap needed)
	if ((x % 2 == 0) && !(y % 2 == 0))
		return true;
 
	// if x is odd and y is even, y goes first (swap needed)
	if (!(x % 2 == 0) && (y % 2 == 0))
		return false;
 
        // otherwise sort in ascending order
	return smaller(x, y);
}

bool comp(int a, int b, bool (*fnc)(int, int))
{
    return (*fnc)(a, b);
}

int main()
{
    int a{3}, b{6};
    std::array<int, 5> ar{1,3,4,2,0};

    std::cout << "3 is bigger than 6: " << comp(a, b, &bigger) << '\n';
    std::cout << "3 is smaller than 6: " << comp(a, b, &smaller) << '\n';

    for (int i: ar)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::sort(ar.begin(), ar.end(), smaller);

    std::cout << "ascending: ";
    for (int i: ar)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::sort(ar.begin(), ar.end(), bigger);

    std::cout << "descending: ";
    for (int i: ar)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::sort(ar.begin(), ar.end(), evensFirst);

    std::cout << "even first: ";
    for (int i: ar)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}