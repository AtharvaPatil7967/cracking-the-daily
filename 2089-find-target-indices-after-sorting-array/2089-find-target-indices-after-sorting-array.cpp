class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> arr;

        for(int i=0; i<n; i++)
        {
            if(target == nums[i])
            {
                arr.push_back(i);
            }
        }

        return arr;
    }
};