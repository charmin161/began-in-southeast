#include <iostream>
using namespace std;

class Student
{
public:
    Student(string n, int nu):name(n),num(nu){}
    void dis()
    {
    cout<<"name "<<name<<" num "<<num<<endl;
    }
private:
    string name;
    int num;
};
int main()
{
    Student s("zhangsan",1002);
    Student s2("lisi",1001);
    // string *ps = &s.name;
    // cout<< *ps<<endl;
    // string Student::*ps = &Student::name;
    // cout<<s.*ps<<endl;
    // cout<<s2.*ps<<endl;
    // Student *pp = new Student("wangwu",1003);
    // cout<<pp->*ps<<endl;
    Student *ps = new Student("lisdai",1003);
    void (Student::*pf)() = & Student::dis;
    (s.*pf)();
    (s2.*pf)();
    (ps->*pf)();
    
    return 0;
}