class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if (total_gas < total_cost) return -1;

        int n = gas.size();
        if(n == 1) return 0;
        for(int i = 0; i < n; i++){
            int total = 0;
            for(int j = 0; j < n - 1; j++){
                if(total < 0) break;
                int index = (j + i) % n;
                total += gas[index] - cost[index];
            }
            if(total > 0) return i;
        }
        return -1;
    }
};
