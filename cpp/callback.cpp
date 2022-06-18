#include<iostream>

using namespace std;

void nothing (int & i)
{
    while(1){
        cout<<"shit"<<endl;
        cout<<i<<endl;
        i++;
    }
}

int main()
{
    int i = 0;
    void (*callback)(int &);
    callback = nothing;
    (*callback)(i);
    for(int j = 0; j < 1000000; j++);
    {
        cout<<i<<endl;
        cout<<"fuckhihdhshahodhoaihiodhaihdoahiodh"<<endl;
    }
    return 0;
}