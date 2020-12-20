/**
 * 
 * 
 * 
 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.
 * 
 * */


#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
		
		int p1 = -1, p2 = -1, t = -1;
		int res = words.size();

		for(int i = 0; i < words.size(); ++i){
		
			t = p1;
			if(words[i] == word1) p1 = i;
			if(words[i] == word2) p2 = i;
			
			if(word1 != word2 && p1 != -1 && p2 != -1) {
				res = min(res, abs(p1-p2));
			}else if(word1 == word2 && t != -1 && t != p1) {
				res = min(res, abs(p1-t));
			}	
		}
		return res;
	}

	int shortestWordDistance2(vector<string>& words, string word1, string word2) {

		int p1 = words.size(), p2 = -words.size();
		int res = words.size();

		for(int i = 0; i < words.size(); ++i) {
			
			if(words[i] == word1) {
				p1 = (word1 == word2) ? p2 : i;
			}
			
			if(words[i] == word2) p2 = i;
			
			if(p1 != -1 && p2 != -1) {
				res = min(res, abs(p1-p2));
			}
		}

		return res;

	}

	int shortestWordDistance3(vector<string>& words, string word1, string word2){
		int idx = -1, res = words.size();
		for(int i = 0; i < words.size(); ++i) {
			if(words[i] == word1 || words[i] == word2){
				
				if (idx != -1 && (words[i] != words[idx] || word1 == word2)) {
					res = min(res, abs(idx - i));
				}
				idx = i;
			}
		}
		return res;
	} 
};


int main(){

	vector<string> vec{"practice","makes", "perfect", "coding", "makes"};
	Solution solution;
	int res = solution.shortestWordDistance2(vec, "makes", "coding");
	cout << "The answer is " << res << endl;

}
