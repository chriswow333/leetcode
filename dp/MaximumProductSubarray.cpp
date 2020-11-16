/**
 * 
 * 

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * */


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        vector<int> mn(n, 0), mx(n, 0);
        mn[0] = nums[0];
        mx[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; ++i) {
            mn[i] = min(mn[i-1]*nums[i], min(mx[i-1]*nums[i], nums[i]));
            mx[i] = max(mn[i-1]*nums[i], max(mx[i-1]*nums[i], nums[i]));
            res = max(res, mx[i]);
        }
        return res;
    }
};


class Solution2 {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int mx = nums[0], mn = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; ++i) {
            int mni = min(mn*nums[i], min(mx*nums[i], nums[i]));
            int mxi = max(mn*nums[i], max(mx*nums[i], nums[i]));
            mn = mni;
            mx = mxi;
            res = max(res, mx);
        }
        return res;
    }
};



class Solution3 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], mn = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; ++i) {
            if(nums[i] < 0) {
                int t = mx;
                mx = max(mn*nums[i], nums[i]);
                mn = min(t*nums[i], nums[i]);
            }else {
                mx = max(mx*nums[i], nums[i]);
                mn = min(mn*nums[i], nums[i]);
            }
            res = max(res, mx);
        }
        return res;
    }
};

class Solution4 {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
        int res = nums[0];
        for(int i = 0; i < n; ++i) {
            prod *= nums[i];
            res = max(res, prod);
            if(nums[i] == 0)prod = 1;
        }

        prod = 1;
        for(int i = n-1; i >= 0; --i) {
            prod *= nums[i];
            res = max(res, prod);
            if(nums[i] == 0)prod = 1;
        }
        return res;
    }
};