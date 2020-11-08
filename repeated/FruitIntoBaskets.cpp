
/**
 * 
 * 
 * 
 * 
 * In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].
Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].
Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].
Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.


*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        unordered_map<int, int> m;
        int start = 0, res = 0;
        for(int i = 0; i < n; ++i) {
            
            ++m[tree[i]];
            while(m.size() > 2) {
                if(--m[tree[start]] == 0)m.erase(tree[start]);
                ++start;
            }
            
            res = max(res, i-start+1);
        }
        return res;
    }
};


class Solution2 {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        unordered_map<int, int> m;
        int start = 0, res = 0;
        for(int i = 0; i < n; ++i) {
            
            m[tree[i]] = i;
            while(m.size() > 2) {
                if(m[tree[start]] == start)m.erase(tree[start]);
                ++start;
            }
            
            res = max(res, i-start+1);
        }
        return res;
    }
};




class Solution3 {
public:
    int totalFruit(vector<int>& tree) {
        
        int left = 0, right = -1, res = 0;
        int n = tree.size();
        
        for(int i = 1; i < n; ++i) {
            
            if(tree[i-1] == tree[i])continue;
            
            if(right != -1 && tree[right] != tree[i]){
                res = max(res, i-left);
                left = right+1;
            }
            
            right = i-1;
            
        }
        
        
        return max(res, n-left);
    }
};


class Solution4 {
public:
    int totalFruit(vector<int>& tree) {
        
        int n = tree.size();
        int first = -1, second = -1;
        int cntSecond = 0, cur = 0, res = 0;
        
        for(int i = 0; i < n; ++i) {
            if(tree[i] == first || tree[i] == second){
                ++cur;
            }else {
                cur = cntSecond+1;
            }
            
            if(tree[i] == second){
                ++cntSecond;
                
            }else {
                cntSecond = 1;
                first = second;
                second = tree[i];
            }
         
            res = max(res, cur);
        }
        return res;
    }
};