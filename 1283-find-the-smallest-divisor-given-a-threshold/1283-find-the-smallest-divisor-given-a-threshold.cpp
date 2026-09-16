class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        if(n == 0) return -1;

        int maxi = 0;

        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
        }

        int low = 1;
        int high = maxi;
        int ans = high;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            // FIX: Changed int to long long to prevent accumulation overflow
            long long total_sum = 0;

            for(int i = 0; i < n; i++)
            {
                // FIX: Cast elements to long long during addition to prevent intermediate overflow
                total_sum += ((1LL * nums[i] + mid - 1) / mid);
            }

            if(total_sum <= threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else if(total_sum > threshold)
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
