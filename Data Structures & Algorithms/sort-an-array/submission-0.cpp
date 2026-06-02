class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num : nums){
            minHeap.push(num);
        }
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};