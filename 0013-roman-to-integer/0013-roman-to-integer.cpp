class Solution {
public:
    int get_val(char ch)
    {
        switch(ch)
        {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int n =s.length();
        int count = 0;

        for(int i=0; i<n-1; i++)
        {
            int current_val = get_val(s[i]);
            int next_val = get_val(s[i+1]);

            if(current_val < next_val)
            {
                count -= current_val;
            }
            else
            {
                count += current_val;
            }
        }

        count += get_val(s[n-1]);

        return count; 
        
    }
};