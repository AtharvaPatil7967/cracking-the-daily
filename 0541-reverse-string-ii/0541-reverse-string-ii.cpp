class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();

        int i=0;
        int j=k-1;

        while(i < n)
        {
            if(j >= n)
            {
                j = n - 1;
            }

            int left = i;
            int right = j;

            while(left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            i += 2 * k;
            j = i + k - 1;
        }
        return s;
    }
};