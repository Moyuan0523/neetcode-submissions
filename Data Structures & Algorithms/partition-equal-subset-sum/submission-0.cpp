class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 2) return false;
        
        set<int> dp;
        dp.insert(0);
        for(int num : nums){
            set<int> tempDP;
            for(int t : dp){
                tempDP.insert(t + num);
                tempDP.insert(t);
            }
            dp = tempDP;
        }
        
        return dp.count(sum/2);
    }
};