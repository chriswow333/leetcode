/**
 * 
 * 
 * 
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 * 
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> q;
        vector<int> res;
        
        for(int i = 0; i < n; ++i) {
            if(!q.empty() && i-q.front() == k)q.pop_front(); 
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);

            if(i >= k-1){
                res.push_back(nums[q.front()]);
            }
            
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        multiset<int> st;
        for(int i = 0; i < n; ++i) {
            if(i>=k)st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            if(i >= k-1)res.push_back(*st.rbegin());
        }
        
        return res; 
    }
};


class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
        
        for(int i = 0; i < n; ++i) {

            while(!q.empty() && i - q.top().first >= k)q.pop();
            q.push({i, nums[i]});
            if(i >= k-1)res.push_back(q.top().second);
        }
        
        return res; 
    }
};