/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// 先建立 adj list，再以 DFS 方式建立 clone graph
// 用 Hash map 紀錄新舊關係

class Solution {
private:
    unordered_map<Node*, Node*> nodemap;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(nodemap.find(node) != nodemap.end()) return nodemap[node];

        Node* newNode = new Node(node->val);
        nodemap[node] = newNode;
        for(Node* nei : node->neighbors){
            newNode->neighbors.push_back(cloneGraph(nei));
        }

        return newNode;
    }
};
