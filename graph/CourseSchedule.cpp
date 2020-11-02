/***
 * 
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
 * 
 * 
 **/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Topological sort
class SolutionTopological {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for(auto e:prerequisites) {
            graph[e[1]].push_back(e[0]);
            ++in[e[0]];
        }

        queue<int> q;

        for(int i = 0; i < numCourses; ++i) {
            if(in[i] == 0)q.push(i);
        }

        while(!q.empty()){
            for(int i = q.size()-1; i >= 0; --i) {
                int t = q.front();
                q.pop();
                for(auto e:graph[t]) {
                    --in[e];
                    if(in[e] == 0)q.push(e);
                }
            }            
        }

        for(int i = 0; i < numCourses; ++i) {
            if(in[i] != 0)return false;
        }

        return true;
    }
};



// DFS
class SolutionDFS {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visited(numCourses, 0);
        for(auto e:prerequisites) {
            graph[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < numCourses; ++i) {
            if(visited[i] == 1)continue;
            if(!helper(graph, i, visited))return false;
        }
        return true;       
    }

    bool helper(vector<vector<int>>& graph, int src, vector<int>& visited){

        if(visited[src] == -1)return false;
        visited[src] = -1;

        for(auto dst:graph[src]) {
            if(!helper(graph, dst, visited))return false;
        }

        visited[src] = 1;
        return true;
    }
};


int main(){

}