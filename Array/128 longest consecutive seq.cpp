//128. Longest Consecutive Sequence
//Solved
//Medium
//Topics
//Companies
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//
//You must write an algorithm that runs in O(n) time.
//
// 
//
//Example 1:
//
//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//Example 2:
//
//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
// 
//
//Constraints:
//
//0 <= nums.length <= 105
//-109 <= nums[i] <= 109


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        unordered_set<int>st;
        int long_cnt = 1;
        for(auto it : nums) st.insert(it);
        for(auto it :st){
            if(st.find(it-1)==st.end()){
                int x = it;
                int cnt =1;
                while(st.find(x+1)!=st.end()){
                    x+=1;
                    cnt+=1;
                }
                long_cnt = max(long_cnt,cnt);
            }
        }
        return long_cnt;
    }
};

int main(){
	vector<int> v = {1,2,3,4,1,6,7,8,9,10};
	Solution s;
	cout<<s.longestConsecutive(v);
}
