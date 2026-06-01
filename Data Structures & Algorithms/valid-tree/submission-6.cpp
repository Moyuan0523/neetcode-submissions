// edge == node - 1，同樣從 0 開始 dfs 檢查 cycle，最後一定要全部聯通
class Solution {
private:
    bool isHasCycle(int curr, int prev, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[curr]) return true;
        visited[curr] = true;
        for(int nei : adj[curr]){
            if(nei == prev) continue;
            else{
                if(isHasCycle(nei, curr, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        if(n == 1) return true;

        // build adj list
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // dfs
        vector<bool> visited(n, false);
        if(isHasCycle(0, -1, adj, visited)){
            return false;
        }
        for(bool v : visited){
            if(!v) return false;
        }
        return true;
    }
};
