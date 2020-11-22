/***
 * 
 * 
 * 
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

 **/

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;



class Solution2 {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -1;
        int res = INT_MAX;
        for(int i = 0;i  < words.size(); ++i) {
            if(words[i] == word1 || words[i] == word2) {
                if(idx != -1 && words[idx] != words[i]){
                    res = min(res, abs(idx-i));
                }
                idx = i;
            }
        }
        return res;
    }
};


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int p1 = INT_MAX, p2 = INT_MAX;
        int res = INT_MAX;
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1)p1 = i;
            else if(words[i] == word2) p2 = i;
            if(p1 != INT_MAX && p2 != INT_MAX){
                res = min(res, abs(p1-p2));
            }
        }
        return res;
    }
};
