class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        map <int, int> mpp;

        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
        }

        while(!mpp.empty())
        {
            auto it = mpp.begin();

            while(it != mpp.end())
            {
                ans.push_back(it -> first);
                it -> second --;

                if(it -> second == 0)
                {
                    it = mpp.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }
        return ans;
    }
};