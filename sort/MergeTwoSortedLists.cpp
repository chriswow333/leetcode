/**
 * 
 * 
 
 Merge two sorted linked lists and return it as a new sorted list. 
 The new list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
 * 
 * 
 * */

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1), *cur = head;

        while(l1 || l2) {
            if(l1 && l2){
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }else {
                    cur->next = l2;
                    l2 = l2->next;
                }
            }else if(l1){
                cur->next = l1;
                l1 = l1->next;
            }else if(l2){
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        return head->next;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)return NULL;
        if(!l2)return l1;
        if(!l1) return l2;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 || (l2 && l1->val > l2->val))swap(l1,l2);
        
        if(l1) l1->next = mergeTwoLists(l1->next, l2);
    
        return l1;
    }
};