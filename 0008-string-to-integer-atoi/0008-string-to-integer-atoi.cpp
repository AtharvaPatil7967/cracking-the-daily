class Solution {
public:
    int myAtoi(string s) {
        int og_len = s.length();
        if(og_len == 0) return 0;
        int i = 0;

        while(i < og_len && s[i] == ' ')
        {
            i++;
        }
        s = s.substr(i);

        int n = s.length();
        i=0;
        int sign = +1;
        long ans = 0;

        int maxi = INT_MAX;
        int mini = INT_MIN;

        if(i < n && (s[0] == '-' || s[0] == '+'))
        {
            sign = (s[0] == '-') ? -1 : 1;
            i++;
        }

        while(i < n)
        {
            if(s[i] == ' ' || !isdigit(s[i])) break;

            ans = ans * 10 + (s[i] - '0');
            if(sign == -1 && -ans < mini) return mini;
            if(sign == 1 && ans > maxi) return maxi;

            i++;
        }

        return (int)(sign * ans);
    }
};