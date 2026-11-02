class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int middle = n / 2;

        int total_moves = 0;

        for(int i=0; i<n; i++)
        {
            total_moves += abs(nums[i] - nums[middle]);
        }

        return total_moves;
    }
};