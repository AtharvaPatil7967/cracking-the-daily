class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();
        int sum = 0;
        
        for(int i=0; i<n-1; i++)
        {
            int first = s[i] - '\0';

            int second = s[i+1] - '\0';

            sum += abs(first - second);
        }

        return sum;



        
    }
};