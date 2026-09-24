class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            int ans = nums[i];
            int sum = 0;

            while(ans > 0)
            {
                int last_digit = ans % 10;
                sum += last_digit;
                ans = ans / 10;
            }

            if(sum == i)
            {
                return i;
            }
        }
        return -1;
    }
};