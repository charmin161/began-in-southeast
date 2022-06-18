#include <bits/stdc++.h>
using namespace std;

class A{
public:
static A* getA()
{
}

private:
static A* na;
A(){}

};

A* A::na = NULL;

A* A::getA(){
if(na == NULL){
    na = new A();
}
    return na;
}