#include <iostream>
#include <string>


class Logger
{
    public:
        Logger() { incl = 1; };
        Logger& operator<<(int i);
        Logger& operator<<(float f);
        Logger& operator<<(char c);
        Logger& operator<<(const char *s);
        void printSum();
        void printLog(const char* start);

        Logger& out();
        void doIt();
        int strlen(const char* s);

    private:
        int incl;
};


int Logger::strlen(const char *s)
{
    const char *end = s;
    while(*end++ != 0);
    return end - s - 1;
}


void Logger::doIt()
{
    out() << 1 << 1.2f << 'j' << "hello";
}


Logger& Logger::out(){
    return *this;
}


Logger& Logger::operator<<(int i)
{
    if (incl)
    {
        printf("### ");
        incl = 0;
    }
    printf("%d", i);
    return *this;
}

Logger& Logger::operator<<(float f)
{
    if (incl)
    {
        printf("### ");
        incl = 0;
    }
    printf("%g", f);
    return *this;
}

Logger& Logger::operator<<(char c)
{
    if (incl)
    {
        printf("### ");
        incl = 0;
    }
    printf("%c", c);

    if (c == '\n')
        incl = 1;

    return *this;
}

Logger& Logger::operator<<(const char* s)
{
    if (incl)
    {
        printf("### ");
        incl = 0;
    }
    printf("%s", s);
    int last = strlen(s) - 1;
    if (*(s+last) == '\n')
        incl = 1;
    return *this;
}

void Logger::printSum(){
    std::cout << incl << '\n'; 
}

int main()
{
    Logger log;
    
    log.doIt();
    log.doIt();

    log << log.strlen("hello");

    log << "hello world!\n" << 3 << '\n' << "bye world!" << 2.3f << '\n';

    //log.printSum();

    //log << 2 << 3.4f << 'j' << "hello world!";
    //log.printSum();
}