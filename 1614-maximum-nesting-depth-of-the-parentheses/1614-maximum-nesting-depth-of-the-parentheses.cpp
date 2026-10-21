class Solution {
public:

    int maxDepth(string s) {
        int n = s.size();
        int current_depth = 0;
        int max_depth = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                current_depth ++;
                max_depth = max(max_depth, current_depth);
            }
            else if(s[i] == ')')
            {
                current_depth--;
            }
        }

        return max_depth;
    }
};