#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    int i = 0;
    vector<vector<int>> ans;

    vector<int> tSum;
    int n = nums.size();
    if(n < 3) return ans;
    while(i < n-2){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j =i+1;
        int k = nums.size() - 1;
        int t = target - nums[i];
        while(j < k){
            int tmp = nums[j] + nums[k];
            if(tmp == t){
                ans.push_back({nums[i], nums[j], nums[k]});
                while(j < k &&nums[j+1] == nums[j]) j++;
                k--;
            }
            else if(tmp < t){
                    j++;
                
            }
            else{
                k--;
            }
        }

        i++;
    }
    return ans;

}

int main(){
    vector<int> va({1, 2, 4, 6, 7, 8, 3, -1, 9});
    vector<vector<int>> ans = threeSum(va, 11);
    for(int i = 0; i < ans.size(); i++){
        
        for(auto num:ans[i]){
            cout<<num<<" ";
        }
        cout<<endl;
    }




}