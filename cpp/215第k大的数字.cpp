#include <iostream>
#include <vector>

using namespace std;
class Solution{

public:
    int randm(int j){
        return rand()%j; 
    }
    int kThbigist(vector<int> &nums, int k){
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            int i = l;
            int j = l;
            int m = randm(r-l) + l;
            swap(nums[m], nums[r]);
            while(j < r){
                if(nums[j] <= nums[r]){
                    swap(nums[i], nums[j]);
                    i++;
                }

                j++;
            }
            swap(nums[r], nums[i]);
            if (i == k) return nums[i];
            else if(i < k){
                l = i + 1;
            }
            else {
                r = i - 1;

            }

        }
        
    }


};