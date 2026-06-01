// 建立無向 adj list，
class Solution {
private:
    bool ishascycle(int prev, int curr, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[curr]) return true;
        else{
            visited[curr] = true;
            for(int nei : adj[curr]){
                if(nei == prev) continue;
                else{
                    if(ishascycle(curr, nei, adj, visited)) return true;
                }
            }
            return false;
        }
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

        //dfs
        vector<int> visited(n, 0);
        if(ishascycle(-1, 0, adj, visited)) return false;

        //是否都有走過
        for(bool v : visited){
            if(!v) return false;
        }
        return true;
    }
};
