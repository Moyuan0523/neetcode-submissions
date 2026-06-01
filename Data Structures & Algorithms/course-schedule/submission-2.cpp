//『 此題為有向圖，用 DFS 來偵測是否存在 cycle 
//   (visited = {0, 未訪問} {1, 正在 DFS 探索中} {2, 確認這堂課沒有 cycle}) 』
class Solution {
private:
    bool ishascycle(int curr, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[curr] == 1) return true;
        if(visited[curr] == 2) return false;
        visited[curr] = 1;
        for(int nei : adj[curr]){
            if(ishascycle(nei, adj, visited)) return true;
        }
        visited[curr] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build adj list
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        for(auto& edge : prerequisites){
            int prev = edge[0];
            int course = edge[1];
            adj[prev].push_back(course);
        }
        // dfs 有沒有 cycle
        for(int num = 0; num < numCourses; num++){
            if(visited[num] == 0){
                if(ishascycle(num, adj, visited)) return false;
            }
        }
        return true;
    }
};
