#include <iostream>
using namespace std;

int main(){
    int n =10;
    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < n; i++){
        ans2 |= i;
        for(int j = 0; j < n; j++){
            ans1 += (i|j);
            
                
        }
    }
    cout<<ans1<<endl<<ans2<<endl;

    return 0;
}