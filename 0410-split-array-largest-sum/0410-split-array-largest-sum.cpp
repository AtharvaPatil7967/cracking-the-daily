class Solution {
public:

    int func(vector<int>& nums, int k)
    {
        int n = nums.size();
        int count_subarray = 1;
        int sum_subarray = 0;
        for(int i=0; i<n; i++)
        {
            if((sum_subarray + nums[i]) <= k)
            {
                sum_subarray += nums[i];
            }
            else
            {
                count_subarray ++;
                sum_subarray = nums[i];
            }

        }
        return count_subarray;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int min_num = 0;
        for(int i=0; i<n; i++)
        {
            min_num = max(min_num, nums[i]);
        }

        int sum_num = 0;
        for(int i=0; i<n; i++)
        {
            sum_num += nums[i];
        }

        int low = min_num;
        int high = sum_num;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            int count_num = func(nums, mid);

            if(count_num > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};