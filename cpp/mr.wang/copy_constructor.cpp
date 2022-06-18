#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A
{
public:
    A(){
        cout<<this<<" constructor"<<endl;
    }
    A(const A &other)
    {
        cout<<this<<" cp contructor from "<<&other<<endl;
    }
    A & operator=(const A &other)
    {
        cout<<this<<" operator = "<<&other<<endl;
    }
    ~A()
    {
        cout<<this<<" destructor"<<endl;
    }
};

A foo(A &a)
{
    cout<<"in foo :"<<(void*)&a<<endl;
    return a;
}
int main()
{
    A a;
    A t;
    t = foo(a);
    cout<<"in main:"<<(void*)&t<<endl;
    return 0;
}