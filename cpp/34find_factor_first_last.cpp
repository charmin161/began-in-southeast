#include <iostream>
#include<queue>
using namespace std;

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

*/



//双指针
class Solution1 {
public:
     vector<int> searchRange(vector<int>& nums, int target) {

        int i=0;
        int j=nums.size()-1;
        vector<int> ans(2,-1);
        if (j<0) return ans;
        while((nums[i]!=target||nums[j]!=target)&&i<j){
            if(nums[i]<target) i++;
            if(nums[j]>target) j--;
        }
        if (i>=j&&nums[i]!= target) return ans;
        ans[0] = i;
        ans[1] = j;
        return ans;
        
    }
};



int main(){

    Solution1 sol1;
    vector<int> num1 = {1,2,3,4,5,6,7,8,9,9,10};
    vector<int> ans = sol1.searchRange(num1,9);
    cout<<"ans="<<ans[0]<<","<<ans[1]<<endl;

    return 0;
}
