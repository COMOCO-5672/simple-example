#include <iostream>
#include <string>

int main()
{
    std::string a = "aaaaaa";
    auto lambda_fun = [&]()
    {
        std::cout << "wwww" << std::endl;
    };
    lambda_fun();
    return 1;
}