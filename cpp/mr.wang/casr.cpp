#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x = 0x12345648;
    char *p = reinterpret_cast<char*>(&x);
//char*p = static_cast<char*>(&x);
    //printf("%x\n",*p);
    int a[5] = {1,1,3,4,5};
    printf("%x\n",reinterpret_cast<int>(a) +1);
    int *q = reinterpret_cast<int*>((reinterpret_cast<int>(a)+2));
    printf("%x\n",*q);
    string str = "dadafgfgfsdfd";
    //cout<<sizeof(string)<<endl;
    //cout<<sizeof(str)<<endl;


return 0;
}