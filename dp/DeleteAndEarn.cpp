
/**
 * 
 * Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:

Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
 

Example 2:

Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
 

Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
*/

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        if(nums.size() == 0)return 0;
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> sum(mx+1, 0);
        for(auto num:nums) {
            sum[num] += num;
        }

        vector<int> dp(mx+1, 0);
        dp[0] = sum[0];
        dp[1] = max(sum[0], sum[1]);
        for(int i = 2; i <= mx; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+sum[i]);
        }
        
        return dp[mx];

    }
};

class Solution2 {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 0)return 0;
        int mx = *max_element(nums.begin(), nums.end());
    
        vector<int> sum(mx+1, 0);
        for(auto num:nums) {
            sum[num] += num;
        }
        
        int take = 0, skip = 0;
        for(int i = 0; i <= mx; ++i) {
            int takei = skip+sum[i];
            int skipi = max(take, skip);
        
            skip = skipi;
            take = takei;            
        }
        
        return max(skip, take);
    }
};