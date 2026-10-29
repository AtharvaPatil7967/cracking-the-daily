class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int i = 0;
        int j = 0;

        string res = "";

        while(i < n && j < m)
        {
            res += word1[i];
            i++;
            res += word2[j];
            j++;
        }

        while(j < m)
        {
            res += word2[j];
            j++;
        }

        while(i < n)
        {
            res += word1[i];
            i++;
        }

        return res;
    }
};