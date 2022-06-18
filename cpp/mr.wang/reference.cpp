#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct TypeP
{
char *p;
};
struct TypeC
{
char c;
};
struct TypeR
{
char& r; //把引用单列出来，不与具体的对像发生关系
};
struct TypeI
{
int i; //把引用单列出来，不与具体的对像发生关系
};
int main()
{
// int a;
// int &ra = &a;
// const int rb; //const 类型必须要初始化。
// printf("%d %d %d %d\n",sizeof(TypeP),sizeof(TypeC),sizeof(TypeR));


    int (*a)[6] = new int[5][6];
    cout<<sizeof(a)<<endl;
    cout<<sizeof(a[0])<<endl;
    cout<<sizeof(a[0][0])<<endl;
    int *b = new int[10];
    memset(b, int(1), sizeof(int[10]));
    cout<<b<<endl;
    cout<<*b<<endl;
    while(*b){
        
        cout<<b<<": "<<*b<<endl;
        b++;
    }


return 0;
}