class Solution {
public:
    bool binary_search(vector<int>& mat, int m, int target)
    {
        int low = 0;
        int high = m - 1;

        while(low <= high)
        {
            int mid = low + ((high - low)) / 2;

            if(mat[mid] == target)
            {
                return true;
            }
            else if(mat[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++)
        {
            if(binary_search(matrix[i], m, target))
            {
                return true;
            }
        }
        return false;
    }
};