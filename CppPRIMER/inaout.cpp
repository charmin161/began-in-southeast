#include <bits/stdc++.h>
using namespace std;
int main(){
    int m = 0;
    int n = 0;
    int x = 0;
    cin>>m;
    cin>>n;
    cin>>x;
    vector<int> nums(m,0);
    for(int i = 0; i < m; i++){
        int tmp = 0;
        cin>>tmp;
        nums[i] = tmp;   
    }
    sort(nums.begin(), nums.end());
    cout<<x+nums[m-1]<<endl;
    return 0;
}