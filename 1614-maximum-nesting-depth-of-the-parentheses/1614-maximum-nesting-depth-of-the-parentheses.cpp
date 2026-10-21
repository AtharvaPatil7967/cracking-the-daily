class Solution {
public:

    int maxDepth(string s) {
        stack<char> st;
        string ans = "";

        int max_depth = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                st.push(c);
                int n = st.size();
                max_depth = max(max_depth, n);
            }
            else if(c == ')')
            {
                st.pop();
            }
        }

        return max_depth;
    }
};