class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }

        int numstring = strs.size();
        int first_word_len = strs[0].length();   

        for(int i=0; i<first_word_len; i++)
        {
            char c = strs[0][i];

            for(int j=1; j<numstring; j++)
            {
                if(i == strs[j].length() || strs[j][i] != c)
                {
                    return strs[0].substr(0,i);
                }
            }
        }

        return strs[0];


    }
};