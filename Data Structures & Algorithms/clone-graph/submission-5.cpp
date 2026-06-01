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

// 使用 DFS 依序建立新的點，並用 hash map 紀錄新舊關係

class Solution {
private:
    unordered_map<Node*, Node*> nodeMap;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(nodeMap.find(node) != nodeMap.end()){
            return nodeMap[node];
        }

        Node* newNode = new Node(node->val);
        nodeMap[node] = newNode;
        for(Node* nei : node->neighbors){
            newNode->neighbors.push_back(cloneGraph(nei));
        }
        return newNode;
    }
};
