class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();

        for(char &c : s)
        {
            c = tolower(c);
        }

        return s;
    }
};