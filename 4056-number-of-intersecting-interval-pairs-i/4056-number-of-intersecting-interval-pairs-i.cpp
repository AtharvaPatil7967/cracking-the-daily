class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int total_pairs = 0;
        int n = intervals.size();

        for(int i=0; i<n; i++)
        {
            int end_A = intervals[i][1];
            for(int j=i+1; j<n; j++)
            {
                int start_B = intervals[j][0];

                if(start_B > end_A)
                {
                    break;
                }
                else
                {
                    total_pairs++;
                }
            }
        }
        return total_pairs;
    }
};