#include <iostream>
#include <stdlib.h>
using namespace std;



int main()
{
    int a[5] = {1,2,3,4,5};
    cout<<a<<endl;
    cout<<&a[1]<<endl;
    int x = (reinterpret_cast<int>(a)+1);
    cout<<hex<<x<<endl;
    int *p = reinterpret_cast<int*>((reinterpret_cast<int>(a)+1));
    cout<<hex<<*p<<endl;
    return 0;
}


