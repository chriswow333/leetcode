/**
 * 
 Design a class which receives a list of words in the constructor, 
 and implements a method that takes two words word1 and word2 
 and return the shortest distance between these two words in the list. 
 Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 * 
 * 
 * */


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;
// O(mn)
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            parameter[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> c1 = parameter[word1], c2 = parameter[word2];
        int mn = INT_MAX;
        for(int i = 0; i < c1.size(); ++i){
            for(int j = 0; j < c2.size(); ++j) {
                mn = min(mn, abs(c1[i]-c2[j]));
            }
        }
        return mn;
    }

private:
    unordered_map<string, vector<int>> parameter;
};



// O(m+n)
class WordDistance2 {
public:
    WordDistance2(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            parameter[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        
        int p1 = 0, p2 = 0;
        int m = parameter[word1].size(), n = parameter[word2].size();
        int mn = INT_MAX;
        while(p1 < m && p2 < n) {
            
            mn = min(mn, abs(parameter[word1][p1]-parameter[word2][p2]));
            if(parameter[word1][p1] < parameter[word2][p2])++p1;
            else ++p2;
        }

        return mn;
    }

private:
    unordered_map<string, vector<int>> parameter;
};



int main(){
    vector<string> input{"practice", "makes", "perfect", "coding", "makes"};
    WordDistance2 wordDistance(input);
    cout << wordDistance.shortest("coding", "practice") << endl;
}

