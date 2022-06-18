#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {-2, 1 ,-3, 4, -1,2,1,-5,4};
    int numSub = nums[0];
    int s = 0;
    int f = 0;
    int ans = numSub;
    while(f < nums.size()-1){
        if(f > s && nums[f+1] < 0 && nums[f+1] > nums[s]){
            numSub -= nums[s];
            
            s++;
        }
        else{
            numSub += nums[++f];
            
        }
        ans = max(numSub, ans);
    } 
    cout<<ans;
    return 0;

}