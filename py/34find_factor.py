from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        i=0
        j= len(nums)-1
        ans= [-1,-1]
        if j<0 :return ans
        while ((nums[i]!=target or nums[j]!=target) and i<j):
            if nums[i]<target : i+=1
            if nums[j]>target : j-=1
        
        if i>=j and nums[i]!= target: return ans
        ans[0] = i
        ans[1] = j
        return ans
        

nums = [5,7,8,8,8,10]
target = 8
sol = Solution
print (sol.searchRange(sol,nums=nums,target=8))
