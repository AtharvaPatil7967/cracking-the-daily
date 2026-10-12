class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();

        int max_product = INT_MIN;

        vector<int> result = {-1,-1};

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j) continue;

                if(nums[i] + nums[j] != target) continue;

                if(nums[i] <= nums[j]) continue;

                int current_prod = nums[i] * nums[j];

                if(current_prod > max_product)
                {
                    max_product = current_prod;
                    result = {i,j};
                }
            }
        }
        return result;
    }
};