class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        long long mini_sum = 0;
        if(k1 == 0 && k2 == 0)
        {
            for(int i=0; i<n; i++)
            {
                long long diff = (long long)nums1[i] - nums2[i];
                mini_sum += diff * diff;
            }
            return mini_sum;
        }

        vector<long long> diff(n);
        long long total_diff_sum = 0;
        long long max_diff = 0;

        for(int i=0; i<n; i++)
        {
            diff[i] = abs(nums1[i] - nums2[i]);
            total_diff_sum += diff[i];
            max_diff = max(max_diff, diff[i]);
        }

        long long total_k = (long long)k1 + k2;

        if(total_diff_sum <= total_k)
        {
            return 0;
        }

        long long low = 0;
        long long high = max_diff;
        long long best_T = max_diff;

        while(low <= high)
        {
            long long mid = low + ((high - low) / 2);
            long long ops_needed = 0;

            for(int i=0; i<n; i++)
            {
                if(diff[i] > mid)
                {
                    ops_needed += (diff[i] - mid);
                }
            }

            if(ops_needed <= total_k)
            {
                best_T = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        long long ops_used = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (diff[i] > best_T) 
            {
                ops_used += (diff[i] - best_T);
            }
        }

        long long leftover_k = total_k - ops_used;
        
        long long final_ans = 0;
        for (int i = 0; i < n; ++i) 
        {
            long long current_val = min(diff[i], best_T);
            
            if (current_val == best_T && leftover_k > 0 && current_val > 0) 
            {
                current_val--;
                leftover_k--;
            }
            
            final_ans += current_val * current_val;
        }
        
        return final_ans;
    }
};
