/**
 * 
 * 
 Find the kth largest element in an unsorted array. 
 Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// using priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for(int i = 0; i < k-1; ++i)q.pop();
        return q.top();
    }
};

// quick sort
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partition(nums, 0, nums.size()-1, k);
        return nums[k-1];
        
    }

    void partition(vector<int>&nums, int left, int right, int k){
        if(left > right)return;
        int idx = helper(nums, left, right);
        if(idx == k-1)return;
        partition(nums, left, idx-1, k);
        partition(nums, idx+1, right, k);

    }

    int helper(vector<int>&nums, int left, int right){

        int pivot = right;
        int idx = left - 1;

        for(int i = left; i < right; ++i) {
            if(nums[i] >= nums[pivot]){
                swap(nums[i], nums[++idx]);
            }
        }
        swap(nums[pivot], nums[++idx]);
        return idx;
    }

};

// using sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int a, int b){
            return a > b;
        };
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};