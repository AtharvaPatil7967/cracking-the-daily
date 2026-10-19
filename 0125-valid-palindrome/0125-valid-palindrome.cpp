class Solution {
public:
    bool is_alpha_numeric(char ch)
    {
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
        {
            return true;
        }
        return false;

    }

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;

        while(start < end)
        {
            if(!is_alpha_numeric(s[start]))
            {
                start ++;
                continue;
            }
            if(!is_alpha_numeric(s[end]))
            {
                end --;
                continue;
            }  

            if(tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }

            start ++;
            end --;
        }

        return true;
    }
};