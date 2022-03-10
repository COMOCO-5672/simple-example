
#include <iostream>
#include <string>
using namespace std;
std::string mystr;
enum
{
    TEXT = 1,
    STRING
};

int Setstr(const char *val)
{
    mystr = val;
    return 0;
}

#define AddSet(val) Setstr(#val)

int main()
{
    AddSet(TEXT);
    printf("%s/n", mystr.c_str());
    system("pause");
    return 0;
}