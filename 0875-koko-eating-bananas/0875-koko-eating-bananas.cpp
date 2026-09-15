class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxi_piles = 0;

        for(int i=0; i<n; i++)
        {
            maxi_piles = max(maxi_piles, piles[i]);
        }
        int low = 1;
        int high = maxi_piles;
        int ans = INT_MAX;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            long long total_hours = 0;

            for(int i=0; i<n; i++)
            {
                total_hours += ((piles[i] + mid - 1) / mid);
            }

            if(total_hours <= h)
            {
                ans = mid;
                high = mid - 1;
                
            }
            else if(total_hours > h)
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};