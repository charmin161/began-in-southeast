#include <iostream>
#include <string.h>
using namespace std;
class A
{
public:
    A(char * ps)
        :name(ps),len(strlen(name.c_str())){}
    void dis()
    {
        cout<<len<<endl;
    }
private:

    string name;
    int len;
};
int main()
{
    char* cha ("chinczcza");
    A a(cha);
    a.dis();
    return 0;
}