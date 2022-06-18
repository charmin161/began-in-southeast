#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

*/

int sum(vector<int>& nums){
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        return sum;
    }

int findTargetSumWays(vector<int> nums, int target) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    if ((sum(nums)<target)||(target+sum(nums)<0)) return 0;
    if ((sum(nums)==target)||(target+sum(nums)==0)) return 1;
    int backnum=nums[n-1];
    nums.pop_back();
    cout<<nums.size()<<";"<<target-backnum<<";"<<target+backnum<<endl;
    int ans=(findTargetSumWays(nums,target-backnum))+(findTargetSumWays(nums,target+backnum));
    cout<<"target:"<<target<<"ans:"<<ans<<endl;
    return ans;
}

int main(){


    vector<int> nums={1,1,1,1,1};
    
    int ans=findTargetSumWays(nums,3);
    cout<<ans;

    return 0;

}
