//34. Find First and Last Position of Element in Sorted Array
//Solved
//Medium
//Topics
//Companies
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//
//If target is not found in the array, return [-1, -1].
//
//You must write an algorithm with O(log n) runtime complexity.
//
// 
//
//Example 1:
//
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//Example 2:
//
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//Example 3:
//
//Input: nums = [], target = 0
//Output: [-1,-1]
// 
//
//Constraints:
//
//0 <= nums.length <= 105
//-109 <= nums[i] <= 109
//nums is a non-decreasing array.
//-109 <= target <= 109

class Solution {
public:
    int lowerBound(vector<int> nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <=high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                n = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
         return n;
    }

     int upperBound(vector<int> nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <=high){
            int mid = (low+high)/2;
            if(nums[mid] > target){
                n = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
           
        }
         return n-1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        if(find(nums.begin(),nums.end(),target)== nums.end()) return ans;
        ans[0] = lowerBound(nums,target);
        ans[1] = upperBound(nums,target);
        return ans;
    }
};
