class Solution {
public:

    int total_days(vector<int>& weights, int capacity)
    {
        int n = weights.size();

        int day = 1;
        int load = 0;

        for(int i=0; i<n; i++)
        {
            if((load + weights[i]) > capacity)
            {
                day++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int maxi_element = 0;

        for(int i=0; i<n; i++)
        {
            maxi_element = max(maxi_element, weights[i]);
        }
        int total_weight = 0;

        for(int i=0; i<n; i++)
        {
            total_weight += weights[i];
        }

        int low = maxi_element;
        int high = total_weight;

        int ans = high;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            int days_required = total_days(weights, mid);

            if(days_required <= days)
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