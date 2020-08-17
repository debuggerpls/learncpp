#include <iostream>

int main()
{
    int widthC = 5; // copy initialization
    int widthD(5); // direct initialization (performs better for advanced types)

    // added in C++11
    // brace initialization (uniform initialization)
    int widthBD{ 5 }; // direct brace initialization (preferred)
    int widthBC = { 5 }; // copy brace initialization

    int zeroInit{}; // zero initialization to value 0

    // it does not allow "narrowing" conversions
    //int width{ 4.5 }; // error: not all double values fit into an int
    //int width2 = { 4.5 }; // error: not all double values fit into an int

    //int width3 = 4.5; // OK
    //int width4 (4.5); // OK

    //int x{0}; //explicit init, when value is used!
    //int x{}; // when temp and immediatlely is replaced (e.g. std::cin)
}