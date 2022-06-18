#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void func(int a)
{
    cout<<a<<endl;
}
int main()
{
    vector<int> A;
    vector<char> B;
    vector<vector<int>> V;
    A.push_back(1);
    for(int i = 0; i < 128; i++){
        A.push_back(i);
    }
    cout<<A.capacity()<<"  "<<A.size()<<endl;
    A.pop_back();
    cout<<A.capacity()<<"  "<<A.size()<<endl;
    for(int i = 0; i < 100; i++){
        A.pop_back();
    }
    cout<<A.capacity()<<"  "<<A.size()<<endl;    
    return 0;
}