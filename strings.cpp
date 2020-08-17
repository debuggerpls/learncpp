#include <iostream>
#include <sstream>

int main()
{
    std::string s{"Hello world!"};
    std::cout << s << '\n';



    s = "Not anymore!";


    std::cout << s << '\n';


    std::string string_num{"13.5"};
    float number;
    std::stringstream (string_num) >> number;

    std::cout << "number is " << number << '\n';

    return 0;


}