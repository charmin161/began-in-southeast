#include <iostream>

using namespace std;

int &plus10(int &r) {
    r += 10;
    return r;
}
int main()
{
    int num1 = 10;
    int &num2 = num1;
    int *num3 = &num1;
    auto volue = "dasdsadabd"s;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << volue <<endl;
    return 0;
} 