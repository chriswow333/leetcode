/**
 * 
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.

 * 
 * 
 * 
 * 
 * 
 * */


#include <iostream>
#include <set>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        q.insert(x);
        st.push(x);
    }
    
    void pop() {
        
        int num = st.top();
        q.erase(q.find(num));
        // cout << num << endl;
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *q.begin();
    }
    
private:
    stack<int> st;
    multiset<int> q;
};


class MinStack2 {
public:
    /** initialize your data structure here. */
    MinStack2() {
        mn = INT_MAX;
    }
    
    void push(int x) {
        if(x <= mn){
            st.push(mn);
            mn = x;
        }
        
        st.push(x);
        
    }
    
    void pop() {
        int t = st.top(); st.pop();
        if(t == mn) {
            mn = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn;
    }
    
private:
    int mn;
    stack<int> st;
};


class MinStack3 {
public:
    /** initialize your data structure here. */
    MinStack3() {
    }
    
    void push(int x) {
        
        st1.push(x);
        if(st2.empty() || x <= st2.top())st2.push(x);
    }
    
    void pop() {
        if(st1.top() == st2.top()) st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
    
private:
    stack<int> st1, st2;
};
