class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count = 0;
        int start = 0;
        vector<string> ans;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                count ++;
            }
            else
            {
                count--;
            }

            if(count == 0)
            {
                string primitive = s.substr(start, i - start + 1);

                string stripped = primitive.substr(1, primitive.length()-2);

                ans.push_back(stripped);

                start = i + 1;
            }
        }

        string result = "";

        for(const string &str : ans)
        {
            result += str;
        }

        return result;

    }
};