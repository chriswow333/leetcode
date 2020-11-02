
/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        unordered_map<char, int> m;
        int start = 0, mxLen = 0;
        for(int i = 0;i < n; ++i) {
            if(m.count(s[i])){
                start = max(start, m[s[i]]+1);
            }

            m[s[i]] = i;
            mxLen = max(mxLen, i-start+1);
        }
        return mxLen;
    }
};



class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
      
        int n = s.size();
        
        vector<int> vec(128, -1);
        int start = 0, mxLen = 0;
        for(int i = 0;i < n; ++i) {
            if(vec[s[i]] != -1) {
                start = max(start, vec[s[i]]+1);
            }
            vec[s[i]] = i;
            mxLen = max(mxLen, i-start+1);
        }
        return mxLen;
        
    }
};

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
      
        int n = s.size();
        unordered_set<char> st;
        int i = 0, start = 0, mxLen = 0;
        while(i < n) {
            if(!st.count(s[i])) {
                st.insert(s[i++]);
                mxLen = max(mxLen, (int)st.size());
            }else {
                st.erase(s[start++]);
            }
        }

        return mxLen;
        
    }
};





int main(){

}