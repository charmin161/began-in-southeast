// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案。

//  

// 示例 1：

// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//方案一：使用哈希表
class Solution1{
public:
    vector<int> twoSum(vector<int> nums, int target){
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> myMap;
        for(int i = 0; i < n; i++){
            int tmp = target - nums[i];
            if (myMap.count(tmp) && tmp*2 == target){ //如果是6 = 3+3的情况
                ans.push_back(i);
                ans.push_back(myMap[tmp]);
                return ans;
            }
            myMap[tmp] = i;
        }
        for(int i = 0; i < n; i++){
            if(myMap.count(nums[i])){
                ans.push_back(i);
                ans.push_back(myMap[nums[i]]);
                break;
            }
        }
        
        return ans;

    }
};
// 方案二 同样使用哈希表，但是边加边查
//使用count 会出现0位置默认搜索不到的情况

class Solution2{
public:
    vector<int> twoSum(vector<int> nums, int target){
        int n = nums.size();
        unordered_map<int, int> myMap;
        for(int i = 0; i < n; i++){
            int tmp = target - nums[i];
            if (myMap.count(tmp)){ 

                return {i, myMap[tmp]};
            }
            myMap[tmp] = i;
        }
        
        return {};

    }
};

//方案三 与方案二一样  写法不同
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main(){

    Solution1 s1;
    vector<int> test = {1,2,3,4,5};
    vector<int> ans = s1.twoSum(test, 5);
    cout<<ans[1]<<endl;
    
}