class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length();

        int count_r = 0;
        int count_l = 0;
        int count = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == 'R')
            {
                count_r ++;
            }
            else if(s[i] == 'L')
            {
                count_l ++;
            }

            if(count_r == count_l)
            {
                count ++;
            }
        }
        return count;
    }
};