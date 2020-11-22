/**
 * 
 
 Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
 * 
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 2; i < n; i+=2) {
            swap(nums[i], nums[i-1]);
        }

    }
};

// parity.
class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)return;
        
        for(int i = 1; i < n; ++i) {
            if(
                (((i&1) == 1) && nums[i-1] > nums[i] )||
                (((i&1) == 0) && nums[i-1] < nums[i])
            ){
                swap(nums[i-1], nums[i]);
            }
        }
    }
};

int main(){

}

