/**
 * 
 * 
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
 

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].

**/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * 

∅  b  d
∅  0 -1 -1
d  1 -1 -1
b  2  1 -1
d  3  1  1

transfer function is 

**/
class Solution {
public:
    string minWindow(string S, string T) {

        int m = S.size(), n = T.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int start = -1;
        int mnLen = INT_MAX;

        for(int i = 0; i < n; ++i)dp[i][0] = i;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= min(i, n); ++j) {
                if(S[i-1] == T[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = dp[i-1][j];
                }
            }
            if(dp[i][n] != -1){
                if(i - dp[i][n] < mnLen){
                    mnLen = i-dp[i][n];
                    start = dp[i][n];
                }
            }
        }
        return start == -1? "":S.substr(start, mnLen);
    }
};



// 2 pointers 
class Solution2 {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), i = 0, j = 0;
        int start = -1, mnLen = INT_MAX;
        while(i < m) {
            if(S[i] == T[j]){
                if(++j == n){
                    int end = i + 1;
                    while(--j >= 0){
                        while(S[i--] != T[j]);
                    }

                    ++i;
                    ++j;
                    
                    if(end - i < mnLen){
                        mnLen = end - i;
                        start = i;
                    }
                }
            }
            ++i;
        }
        return start == -1?"":S.substr(start, mnLen);        

    }
};