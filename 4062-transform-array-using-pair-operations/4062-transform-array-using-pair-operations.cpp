class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size();
        int m = target.size();
        vector<int> temp_source = source;

        long long sum_source = 0;
        long long sum_target = 0;

        for(int i=0; i<n; i++)
        {
            sum_source += source[i];
        }

        for(int i=0; i<m; i++)
        {
            sum_target += target[i];
        }
        
        return sum_source == sum_target;
    }
};