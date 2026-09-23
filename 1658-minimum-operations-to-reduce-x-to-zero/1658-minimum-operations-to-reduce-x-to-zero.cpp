class Solution {
public:

    int binary_search(vector<pair<int, int>>& suffix_sum, int target)
    {
        int n = suffix_sum.size();
        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            if(suffix_sum[mid].first == target)
            {
                return suffix_sum[mid].second;
            }
            else if(suffix_sum[mid].first < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<pair<int, int>> suffix_sum;
        
        suffix_sum.push_back({0,0});

        int current_suffix_sum = 0;

        for(int i=n-1; i>=0; i--)
        {
            current_suffix_sum += nums[i];

            int suffix_length = n-i;

            suffix_sum.push_back({current_suffix_sum, suffix_length});
        }

        int min_ops = 1e9;
        int current_prefix_sum = 0;

        for(int prefix_len = 0; prefix_len <= n; prefix_len++)
        {
            if(prefix_len > 0)
            {
                current_prefix_sum += nums[prefix_len - 1];
            }

            if(current_prefix_sum > x) break;

            int target_suffix = x - current_prefix_sum;

            int suffix_length = binary_search(suffix_sum, target_suffix);

            if(suffix_length != -1 && (prefix_len + suffix_length <= n))
            {
                min_ops = min(min_ops, prefix_len + suffix_length);
            }
        }

        return (min_ops >= 1e9) ? -1 : min_ops;
    }
};