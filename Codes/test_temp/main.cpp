#include <bits/stdc++.h>
using namespace std;
class ClassName
{
public:
    int number;
    ClassName() // 无参
    {
        number = 1;
    }
    ClassName(int num) : number(num){}

    ClassName(int num,int value) : number(num) 
    {
        print();
        number = value;
        print();
    }
    void print();

private:
};
void ClassName::print()
{
    cout << "number " << number << endl;
}
int main()
{
    if(true)
    {
        ClassName z;
        z.print();
    }
    if(true)
    {
        ClassName z(20);
        z.print();
    }
    if(true)
    {
        ClassName z(10, 20);
    }
}