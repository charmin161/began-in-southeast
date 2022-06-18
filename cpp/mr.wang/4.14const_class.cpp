#include<bits/stdc++.h>
using namespace std;

class A
{
public:
    A():x(199),y(299){}
    void dis() const //const 对象调用时，优先调用
    {
//input(); 不能调用 非 const 函数，因为本函数不会修改，无法保证所调的函数也不会修改
        //y =200; //const 修饰函数表示承诺不对数据成员修改。
        cout<<"x "<<x<<endl;
        cout<<"y "<<y<<endl;

    }
    void dis() //此时构成重载,非 const 对象时，优先调用。
    {
        y = 200;
        //input();
        cout<<"x "<<x<<endl;
        cout<<"y "<<y<<endl;
    }
    void input()
    {
        cin>>y;
    }
private:
    const int x;
    int y;
};


int main()
{
    const A a;
    a.dis();
// const A a;
// a.dis();
    return 0;
}
