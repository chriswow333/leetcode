/**
 * 
 * 
 * Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []

**/

/**
 * Definition for singly-linked list.
 **/

#include <iostream>
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
    ListNode* sortList(ListNode* head) {

        if(!head)return nullptr;
        if(!head->next)return head;

        ListNode *slow = head, *fast = head;
        ListNode *pre = nullptr;
        while(fast && fast->next){
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        pre->next = nullptr;

        helper(sortList(head), sortList(slow));

        
    }


    ListNode* helper(ListNode* left, ListNode* right){
        if(!left && !right)return nullptr;
        if(!right)return left;        
        if(!left)return right;        
        
        if(left->val < right->val){
            left->next = helper(left->next, right);
            return left;
        }else {
            right->next = helper(left, right->next);
            return right;
        }
    }
};