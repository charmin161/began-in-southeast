#include<iostream>

using namespace std;

int count = 0;

class Test{
    public:
        Test()
        {
            cout << "yongleyici"<<endl;

        }
};

int main(){
    Test A;
    cout << "A"<<endl;
    Test B[4];
    cout << "B"<<endl;
    Test* C = B;
    cout << "C"<<endl;

    int a[5];
    for(int i = 0; i < 5; i++){
        a[i] = i;
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    float b = 0.1;
    float c = 0.2;
    float d = 0.3;
    float m = b + c;
    if(m == d){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"shit"<<endl;
    }

    return 0;
}