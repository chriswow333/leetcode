/***
 * 
 * 
 * 
 You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
 * 
 * 
 * 
 * */



#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
        int n = lists.size();
        return merge(lists, 0, n-1);        
        
    }
    
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if(left > right)return nullptr;
        if(left == right)return lists[left];
        
        int mid = left + (right-left)/2;
        
        
        ListNode* leftNode = merge(lists, left, mid);
        ListNode* rightNode = merge(lists, mid+1, right);
        
        return helper(leftNode, rightNode);
    }
    
    ListNode* helper(ListNode* left, ListNode* right){
        
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        
        while(left || right) {
            if(left && right){
                if(left->val < right->val) {
                    cur->next = left;
                    left = left->next;
                }else {
                    cur->next = right;
                    right = right->next;
                }
            }else if(left){
                cur->next = left;
                left = left->next;
            }else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        
        return dummy->next;
    }
};


