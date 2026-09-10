class Solution {
public:
    int searchBound(vector<int>& nums, int target, bool isfirst) {
        int n = nums.size();

        int low = 0;
        int high = n-1;
        int bound = -1;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            if(nums[mid] == target)
            {
                bound = mid;

                if(isfirst)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return bound;
    }

    vector<int> searchRange (vector<int>& nums, int target)
    {
        int first = searchBound(nums,target,true);
        int second = searchBound(nums,target, false);

        return {first, second};
    }
};