// 照著 dfs 的順序印出，有 cycle 便回傳空陣列
class Solution {
private:
    vector<int> result;
    bool isHasCycle(int curr, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[curr] == 1) return true;
        if(visited[curr] == 2) return false;
        visited[curr] = 1;
        for(int nei : adj[curr]){
            if(isHasCycle(nei, adj, visited)) return true;
        }
        visited[curr] = 2;
        result.push_back(curr);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build adj list
        vector<vector<int>> adj(numCourses);
        for(auto& edge : prerequisites){
            int course = edge[0];
            int prev = edge[1];
            adj[prev].push_back(course);
        }

        // dfs
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(isHasCycle(i, adj, visited)){
                    return {};
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
