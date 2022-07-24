class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i = matrix.size();
        int j = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = j-1;
        
        while(rowIndex<i && colIndex>=0)
        {
            int element = matrix[rowIndex][colIndex];
            
            if(element == target)
            {
                return 1;
            }
            else if(element < target)
            {
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
            
        }
        return 0;
    }
};
