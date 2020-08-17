#include <iostream>
#include <fstream>

int main()
{
    std::ofstream mFile("test.txt");

    if (mFile.is_open())
    {
        mFile << "hello deividas!\n";
        mFile << "How are you doing?\n";
        mFile.close();
    }
    else std::cout << "could not open file (write)!\n";

    std::ifstream f("test.txt");
    std::string s;

    if (f.is_open())
    {
        while (getline(f, s))
        {
            std::cout << s << '\n';
        }    
        f.close();
    }
    else std::cout << "could not open file (read)\n";

    return 0;
}