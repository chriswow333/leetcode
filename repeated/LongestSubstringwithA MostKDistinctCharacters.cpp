/***
 * 
 * Given a string, find the length of the longest substring T that contains 
 * at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.

*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        unordered_map<char, int> m;
        int n = s.size();
        int start = 0, res = 0;
        for(int i = 0; i < n; ++i) {
            ++m[s[i]];
            while(s.size() > k) {
                if(--m[s[start]] == 0)m.erase(s[start]);
                ++start;
            }
            res = max(res, i-start+1);
        }
        return res;
    }
};


class Solution2 {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        unordered_map<char, int> m;
        int n = s.size();
        int start = 0, res = 0;
        
        for(int i = 0; i < n; ++i) {
            m[s[start]] = i;
            while(m.size() > k) {
                if(m[s[start]] == start) m.erase(s[start]);
                ++start;
            }
            res = max(res, i-start+1);
        }
        return res;
    }
};