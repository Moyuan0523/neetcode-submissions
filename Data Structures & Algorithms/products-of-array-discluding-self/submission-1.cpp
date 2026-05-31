// result[i] = prefix[i] * suffix[i]
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        // suffix
        for(int i = 0; i < n; i++){
            int curr = 1;
            for(int j = i + 1; j < n; j++){
                curr *= nums[j];
            }
            suffix[i] = curr;
        }
        for(int num : suffix) std::cout << " " << num;
        std::cout << std::endl;
        // prefix
        for(int i = 1; i < n; i++){
            int curr = 1;
            for(int j = 0; j < i; j++){
                curr *= nums[j];
            }
            prefix[i] = curr;
        }
        for(int num : prefix) std::cout << " " << num;
        // result
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};
