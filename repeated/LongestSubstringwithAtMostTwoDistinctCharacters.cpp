/**
 * 
Given a string s , find the length of the longest substring t  
 * that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: tis "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: tis "aabbb" which its length is 5.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// count char numbers
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        unordered_map<char, int> m;
        int start = 0, res = 0;
        
        for(int i = 0; i < n; ++i) {
            ++m[s[i]];
            while(m.size() > 2) {
                if(--m[s[start]] == 0){
                    m.erase(s[start]);
                }
                ++start;
            }
            res = max(res, i-start+1);
        }
        cout << res << endl;
        return res;
    }
};

// mapping latest char position
class Solution2 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        unordered_map<char, int> m;
        int start = 0, res = 0;
        
        for(int i = 0; i < n; ++i) {
            m[s[i]] = i;
            
            while(m.size() > 2) {
                if(m[s[start]] == start){
                    m.erase(m[s[start]]);
                }    
                ++start;
            }

            res = max(res, i-start+1);
        }
        cout << res << endl;
        return res;
    }
};


//sliding window
class Solution3 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {

        int n = s.size();

        int left = 0, right = -1, res = 0;

        for(int i = 1; i < n; ++i) {
            if(s[i] == s[i-1])continue;
            if(right != -1 && s[i] != s[right]){
                res = max(res, i-left);
                left = right+1;
            }
            right = i-1;
        }
        
        return max(res, (int)s.size()-left);
    }
};


/**
 * 
 * 这里使用若干的变量，其中 cur 为当前最长子串的长度，
 * first 和 second 为当前候选子串中的两个不同的字符，
 * cntLast 为 second 字符的连续长度。遍历所有字符，
 * 假如遇到的字符是 first 和 second 中的任意一个，
 * 那么 cur 可以自增1，否则 cntLast 自增1，
 * 因为若是新字符的话，默认已经将 first 字符淘汰了，
 * 此时候选字符串由 second 字符和这个新字符构成，
 * 所以当前长度是 cntLast+1。然后再来更新 cntLast，
 * 假如当前字符等于 second 的话，cntLast 自增1，否则均重置为1，
 * 因为 cntLast 统计的就是 second 字符的连续长度。然后再来判断若当前字符不等于 second，
 * 则此时 first 赋值为 second， second 赋值为新字符。最后不要忘了用 cur 来更新结果 res，参见代码如下：
 * 
 * */
class Solution4 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int cur = 0, cntLast = 0, res = 0;
        char first, second;
        int n = s.size();
        
        for(int i = 0; i < n; ++i) {
            if(first == s[i] || second == s[i]){
                ++cur;
            }else {
                cur = cntLast + 1;
            }

            if(second == s[i]){
                ++cntLast;
            }else {
                first = second;
                second = s[i];
                cntLast = 1;
            }

            res = max(res, cur);
        }

        return res;
    }
};


class SolutionTest {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int n = s.size();
        vector<int> vec(128, 0);
        int start = 0, mxLen = 0;
        int i = 0, cnt = 0;

        while(i < n) {
            if(vec[s[i]]++ == 0) {
                ++cnt;
                while(cnt > 2) {
                    if(--vec[s[start++]] == 0){
                        --cnt;
                    }
                }
            }
            mxLen = max(mxLen, i-start+1);
            ++i;
        }
        cout << mxLen << endl;
        return mxLen;
    }
};


int main(){
    Solution4 solution;
    int res = solution.lengthOfLongestSubstringTwoDistinct("ece");
    cout << res << endl;
}