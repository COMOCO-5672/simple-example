#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

// 模板类
template <class T>
class Functor
{
public:
    enum Type
    {
        Plus,
        Sub
    };
    Functor(Type t = Plus) : type(t) {}
    T operator()(T a, T b)
    {
        if (type == Plus)
            return a + b;
        return a - b;
    }

private:
    Type type;
};

template <typename T1, typename T2, typename T3>
T1 func(const T2 &t2, const T3 &t3)
{
    return t2 + t3;
}

int main()
{
    //同时定义了一个加法器和一个减法器。
    Functor<int> plus(Functor<int>::Plus);
    Functor<int> sub(Functor<int>::Sub);
    int a = 5, b = 3;
    cout << plus(a, b) << endl;
    cout << sub(a, b) << endl;
    auto ret = func<int, int, int>(12, 34);
    cout << "ret=" << ret << endl;
    return 0;
}