class Solution {
public:
    bool canWEplace(vector<int>& position, int dist, int m)
    {
        int n = position.size();

        int current_basket = 1;
        int last_basket = position[0];

        for(int i=1; i<n; i++)
        {
            if(position[i] - last_basket >= dist)
            {
                current_basket ++;
                last_basket = position[i];
            }
        }
        if(current_basket >= m) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();

        sort(position.begin(), position.end());

        int maxi = position[n-1];
        int mini = position[0];

        int ans = -1;

        int low = 0;
        int high = maxi - mini;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            if(canWEplace(position, mid, m) == true)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
        
    }
};