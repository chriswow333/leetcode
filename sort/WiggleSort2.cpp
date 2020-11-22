/***
 * 
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
 * 
 * **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> tmp = nums; 
        sort(tmp.begin(), tmp.end());    
        
        int i = (n+1)/2;
        int j = n;
        for(int k = 0; k < n; ++k) {
            if((k & 1) == 0){
                nums[k] = tmp[--i];
            }else {
                nums[k] = tmp[--j];
            }
        }
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)return;
        vector<int> tmp = nums; 
        
        sort(tmp.begin(), tmp.end());    
        int i = n-1;
        int j = ((nums.size()+1)/2)-1; 
        int k = 0;
        while(k < n) {
            nums[k++] = tmp[j--];
            nums[k++] = tmp[i--];
        }
       
        
    }
};