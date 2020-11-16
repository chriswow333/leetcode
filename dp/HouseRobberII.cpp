/**
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed. 
 * All houses at this place are arranged in a circle. 
 * That means the first house is the neighbor of the last one. 
 * Meanwhile, adjacent houses have a security system connected, 
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1)return nums[0];
        return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }

    int helper(vector<int>& nums, int left, int right) {

        int rob = 0, notRob = 0;
        for(int i = left; i <= right; ++i) {
            int robi = notRob + nums[i];
            int notRobi = max(notRob, rob);
            rob = robi;
            notRob = notRobi;
        }
        return max(rob, notRob);
    }
};


class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1)return nums[0];
        
        return max(helper(nums, 0, n-1), helper(nums, 1, n));
    }

    int helper(vector<int>& nums, int left, int right) {

        if(right-left <= 1)return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left+1] = max(nums[left], nums[left+1]);

        for(int i = left+2; i < right; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp.back();
    }
};