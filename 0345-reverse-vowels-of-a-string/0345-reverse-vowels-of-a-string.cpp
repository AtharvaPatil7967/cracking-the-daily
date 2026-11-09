class Solution {
public:

    string reverseVowels(string s) {
        int n = s.length();
        string vowelsList = "aeiouAEIOU";

        int i=0;
        int j=n-1;

        while(i < j)
        {
            while(i < j && vowelsList.find(s[i]) == string::npos)
            {
                i++;
            }
            while(i < j && vowelsList.find(s[j]) == string::npos)
            {
                j--;
            }

            if(i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};