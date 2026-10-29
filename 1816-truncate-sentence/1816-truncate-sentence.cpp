class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length();

        int count = 0;

        string res = "";

        for(int i=0; i<n; i++)
        {
            if(s[i] != ' ')
            {
                res += s[i];
            }
            else
            {
                count ++;
                if(count == k)
                {
                    break;
                }
                else
                {
                    res += ' ';
                }
            }
        }

        return res;
    }
};