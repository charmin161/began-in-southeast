#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums = {5,8,9};
    int l = 0;
    int r = nums.size()-1;
    int lnum = nums[l];
    int rnum = nums[r];

    while(l < r){
        if((nums[l] - lnum) > (rnum - nums[r])){
            r--;
        }
        else{
            l++;
        }
    }
    cout<<abs(lnum + rnum - 2*nums[r])<<endl;
    // int l = 0;
    // int r = nums.size()-1;
    // int lnum = nums[l];
    // int rnum = nums[r];
    // int i = lower_bound(nums.begin(), nums.end(), (lnum + rnum)/2) - nums.begin();
    // int ans = abs(lnum + rnum - 2*nums[i]);
    // while(i > l && nums[i] == nums[i-1]) i--;
    // int ans2 = abs(lnum + rnum - 2*nums[i]);
    // ans = min(ans, ans2);
    
}