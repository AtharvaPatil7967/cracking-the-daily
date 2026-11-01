class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int right = 0;

        while(right < n && word[right] != ch)
        {
            right++;
        }

        if(right < n)
        {
            int left = 0;

            while(left < right)
            {
                swap(word[left], word[right]);
                left++;
                right--;
            }
        }
        return word;
    }
};