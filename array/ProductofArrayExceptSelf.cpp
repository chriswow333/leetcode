/**
 * 
 * 
 * Given an array nums of n integers where n > 1,  
 * return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of space complexity analysis.)
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> forward(n, 1), backward(n, 1);
        vector<int> res(n, 0);
        
        for(int i = 0; i < n-1; ++i) {
            forward[i+1] = forward[i]*nums[i];
        }
        for(int i = n-1; i > 0; --i) {
            backward[i-1] = backward[i]*nums[i];
        }
        for(int i = 0; i < n; ++i) {
            res[i] = forward[i]*backward[i];
        }
        return res;
    }
};



class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for(int i = 1; i < n; ++i) {
            res[i] = res[i-1]*nums[i-1];
        }
        int right = 1;
        for(int i = n-1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};