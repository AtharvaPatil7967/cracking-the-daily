class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int tr = target[0];
        int sc = source[1];
        int tc = target[1];

        int differnece_in_rows = abs(sr - tr);
        int differnece_in_col = abs(sc - tc);

        if(differnece_in_rows == 0 && differnece_in_col == 0)
        {
            return 0;
        }
        else if(differnece_in_rows == 0 || differnece_in_col == 0 || differnece_in_rows == differnece_in_col)
        {
            return 1;
        }

        return 2;
    }
};