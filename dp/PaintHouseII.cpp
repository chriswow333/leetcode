/**
 * 
 * 
 * 
 * 
There are a row of n houses, each house can be painted with one of the k colors. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. 
Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. 
             Minimum cost: 3 + 2 = 5. 
Follow up:
Could you solve it in O(nk) runtime?

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size(), n = costs[0].size();
        vector<vector<int>> dp = costs;
        int mn1 = -1, mn2 = -1;
        
        for(int i = 0; i < m; ++i) {
            int last1 = mn1, last2 = mn2;
            mn1 = -1;
            mn2 = -1;
            for(int j = 0; j < n; ++j) {
                if(j != last1) {
                    dp[i][j] += last1 < 0 ? 0:dp[i-1][last1];
                }else {
                    dp[i][j] += last2 < 0 ? 0:dp[i-1][last2];
                }
                if(mn1 == -1 || dp[i][j] < dp[i][mn1]){
                    mn2 = mn1;
                    mn1 = j;
                }else if(mn2 == -1 || dp[i][j] < dp[i][mn2]){
                    mn2 = j;
                }
            }
        }

        return dp[n-1][mn1];
    }
};



class Solution2 {
public:
    int minCostII(vector<vector<int>>& costs) {
        
        if (costs.empty() || costs[0].empty()) return 0;

        int m = costs.size(), n = costs[0].size();
        vector<vector<int>> dp = costs;
        
        int mn1 = 0, mn2 = 0, idx = -1;
        for(int i = 0; i < m; ++i) {
            int last1 = INT_MAX, last2 = INT_MAX;
            int lastIdx = -1;
            for(int j = 0; j < n; ++j) {
                int cost = costs[i][j] += (j == idx) ? mn2:mn1;
                if(cost < last1) {
                    last2 = last1;
                    last1 = cost;
                    lastIdx = j;
                }else if(cost < last2) {
                    last2 = cost;
                }
            }
            mn1 = last1;
            mn2 = last2;
            idx = lastIdx;
        }

        return mn1;
    }
};