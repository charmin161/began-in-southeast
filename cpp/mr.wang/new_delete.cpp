#include <iostream>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
using namespace std;
int main()
{
    int *p = new int(5);
    cout<<*p<<endl;
    delete p;
    char *pp = new char[10];
    strcpy(pp,"china");
    cout<<pp<<endl;
    delete []pp;
    string *ps = new string("china");
    cout<<*ps<<endl; 
    cout<<ps<<endl;
    delete ps;
    char **pa= new char*[5];
    cout<<(sizeof(pa));
    cout<<(sizeof(*pa));
    cout<<(sizeof(**pa));
    //为新申请的内存做初始化，直接操作内存空间，填充0
    memset(pa,0,sizeof(char*[5]));
    pa[0] = "china";
    pa[1] = "america";
    char **pt = pa;
    while(*pt)
    {
        cout<<*pt++<<endl;
    }
    delete []pt;
    int (*q)[3] = new int[2][3];
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            q[i][j] = i+j;
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<q[i][j];

        }
        cout<<endl;
    }
    delete []q;
    int (*qq)[3][4] = new int [2][3][4];
    delete []qq;
}