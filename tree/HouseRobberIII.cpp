/**
 * 
 * 
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

**/

/**
 * Definition for a binary tree node.
 * */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return helper(root, m);
    }
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int>&m){
        
        if(!root)return 0;
        int out = 0;
        if(m.count(root))return m[root];
        if(root->left){
            out = helper(root->left->left, m)+helper(root->left->right, m);
        }
        if(root->right) {
            out += helper(root->right->left, m)+helper(root->right->right, m);
        }
        return m[root] = max(out+root->val, helper(root->left, m)+helper(root->right, m));
    }

};


class Solution2 {
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    
    vector<int> helper(TreeNode* root){
        
        if(!root)return vector<int>(2, 0);
        
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        vector<int> res(2, 0);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;

        return res;
     }
};


class Solution3 {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return helper(root, l, r);
    }

    int helper(TreeNode* root, int& l, int& r) {
        if(!root)return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;

        l = helper(root->left, ll, lr); // ??
        r = helper(root->right, rl, rr); // ??
        return max(root->val + ll + lr + rl + rr, l + r);

    }
};