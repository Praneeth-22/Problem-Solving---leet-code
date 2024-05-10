//1004. Max Consecutive Ones III
//Solved
//Medium
//Topics
//Companies
//Hint
//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
//
// 
//
//Example 1:
//
//Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
//Output: 6
//Explanation: [1,1,1,0,0,1,1,1,1,1,1]
//Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
//Example 2:
//
//Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
//Output: 10
//Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// 
//
//Constraints:
//
//1 <= nums.length <= 105
//nums[i] is either 0 or 1.
//0 <= k <= nums.length

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0; 
        int maxOnes = 0;
        int zeros = 0; 
        while (right < n) {
            if (nums[right] == 0) {
                zeros++;
            }
            while (zeros > k) { 
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            maxOnes = max(maxOnes, right - left + 1);
            right++;
        }
        return maxOnes;
    }
};

