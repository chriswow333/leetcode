/**
 * 
 * 
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.
 * 
 * 
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
     
        int i0 = 0, i1 = 0, i2 = 0;

        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0)++i0;
            if(nums[i] == 1)++i1;
            if(nums[i] == 2)++i2;
        }
    
        for(int i = 0; i < n; ++i) {
            if(i0 != 0){
                nums[i] = 0;
                --i0;
            }else if(i1 != 0){
                nums[i] = 1;
                --i1;
            }else {
                nums[i] = 2;
            }
        }
    }
};


class Solution2 {
public:
    void sortColors(vector<int>& nums) {
     
        
        // 2 pointers
        int n = nums.size();
        int color0 = 0, color2 = n-1;
        for(int i = 0; i <= color2; ++i) {
            if(nums[i] == 2){
                swap(nums[i--], nums[color2--]);
            }else if(nums[i] == 0){
                swap(nums[color0++], nums[i]);
            }
        }
    }
};

int main(){

}
