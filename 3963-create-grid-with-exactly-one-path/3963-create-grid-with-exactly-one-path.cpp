class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> mat(m, vector<char>(n,'#'));
        
        int i = 0; 
        int j = 0;

        mat[i][j] = '.';

        while(i < m-1 || j < n-1)
        {
            if(j < n - 1)
            {
                j++;
                mat[i][j] = '.';
            }
            if(i < m - 1)
            {
                i++;
                mat[i][j] = '.';
            }
        }
        
        vector<string> result;
        for(int i=0; i<m; i++)
        {
            result.push_back(string(mat[i].begin(), mat[i].end()));
        }

        return result;
    }
};