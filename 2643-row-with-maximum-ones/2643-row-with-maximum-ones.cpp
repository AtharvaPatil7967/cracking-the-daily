class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0;
        int high = n-1;

        int ans = n;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            if(arr[mid] >= x)
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
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int max_count = -1;
        int index = -1;

        for(int i=0; i<n; i++)
        {
            sort(mat[i].begin(), mat[i].end());
            
            int count_ones = m - lowerBound(mat[i] , m, 1);

            if(count_ones > max_count)
            {
                max_count = count_ones;
                index = i;
            }
        }
        return {index, max_count};
    }
};