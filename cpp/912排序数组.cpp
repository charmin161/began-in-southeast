#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
void quickSort(vector<int> &nums, int l, int r){
    if (r - l < 2){
        if(nums[l] > nums[r]) swap(nums[l], nums[r]);
        return;
    }
    int m = l + rand()%(r-l);
    swap(nums[r], nums[m]);
    int i = l;
    int j = l;
    while(j < r){
        if(nums[j] < nums[m]){
            swap(nums[j], nums[i]);
            i++;
        }
        j++;
    }
    swap(nums[i], nums[r]);
    quickSort(nums, l, i-1);
    quickSort(nums, i, r);
}

vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    srand(time(0));
    if(n < 2) return nums;
    quickSort(nums, 0, n-1);
    //heapSort(nums);
    return nums;

    
}


int main(){
    vector<int> tmp({2,3,45,1,6,7,8,653,3});
    vector<int> ans = sortArray(tmp);
    for(auto num:ans){
        cout<<num<<endl;
    }
    return 0;
}

