class Solution {
public:

    bool possible(vector<int>& bloomDay, int days, int m, int k)
    {
        int n = bloomDay.size();
        int count = 0;
        int no_of_bloom = 0;

        for(int i=0; i<n; i++)
        {
            if(bloomDay[i] <= days)
            {
                count++;
            }
            else
            {
                no_of_bloom += (count / k);
                count = 0;
            }
        }
        no_of_bloom += (count / k);
        if(no_of_bloom >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m * k > n) return -1;

        int mini = bloomDay[0];
        int maxi = bloomDay[0];

        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;
        int ans = high;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);
            if(possible(bloomDay, mid, m, k) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};