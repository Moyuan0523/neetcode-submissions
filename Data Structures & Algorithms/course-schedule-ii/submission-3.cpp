// 按照 dfs 順序依序輸出
class Solution {
private:
    bool isHasCycle(int curr,vector<vector<int>>& adj, vector<int>& visited, vector<int>& result){
        if(visited[curr] == 1) return true;
        if(visited[curr] == 2) return false;
        visited[curr] = 1;
        for(int nei : adj[curr]){
            if(isHasCycle(nei, adj, visited, result)){
                return true;
            }
        }
        visited[curr] = 2;
        result.push_back(curr);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //build adj list
        vector<vector<int>> adj(numCourses);
        for(auto& edge : prerequisites){
            int course = edge[0];
            int prev = edge[1];
            adj[prev].push_back(course);
        }

        //dfs
        vector<int> result;
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(isHasCycle(i, adj, visited, result)){
                    return {};
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
