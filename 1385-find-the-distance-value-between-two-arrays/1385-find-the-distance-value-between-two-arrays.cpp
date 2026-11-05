class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //sort(arr1.begin(), arr1.end());
        //sort(arr2.begin(), arr2.end());
        

        int n = arr1.size();
        int m = arr2.size();

        int first = 0;
        int second = 0;

        int count = 0;

        for(int i=0; i<n; i++)
        {
            bool is_safe = true;
            for(int j=0; j<m; j++)
            {
                int val = abs(arr1[i] - arr2[j]);
                if(val <= d)
                {
                    is_safe = false;
                    break;
                }
            }
            
            if(is_safe)
            {
                count++;
            }
        }
        return count;
    }
};