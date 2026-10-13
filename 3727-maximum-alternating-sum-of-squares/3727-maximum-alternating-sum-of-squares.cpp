class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long total_score = 0;

        int left = 0;
        int right = n-1;

        for(int i=0; i<n; ++i)
        {
            if(i % 2 == 0)
            {
                long long val = nums[right];
                total_score += val * val;
                right --;
            }
            else
            {
                long long val = nums[left];
                total_score -= val * val;
                left++;
            }
        }
        return total_score;
    }
};