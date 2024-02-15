//386. Lexicographical Numbers
//Medium
//Topics
//Companies
//Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
//
//You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
//
// 
//
//Example 1:
//
//Input: n = 13
//Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
//Example 2:
//
//Input: n = 2
//Output: [1,2]
// 

class Solution {
public:
    void dfs(int curr, int n, vector<int> &ans) {
        if (curr > n) return;
        ans.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            if (curr * 10 + i <= n) {
                dfs(curr * 10 + i, n, ans);
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9 && i <= n; i++) {
            dfs(i, n, ans);
        }
        return ans;
    }
};

