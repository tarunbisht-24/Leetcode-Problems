class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        if(mat.size() == 0 || mat.size() == 1 || mat[0].size()==1)
            return mat;
        int rows = mat.size(); 
        int cols = mat[0].size();
        
        
        for(int i = rows-1; i >= 0; i--) { 
            int k = 0; 
            vector <int> v; 
            for(int j = i; j < rows; j++) {
                if(k >= cols)  
                    break;
                v.push_back(mat[j][k]);
                k++;
            }
            sort(v.begin(), v.end());
            int l = 0;
            k = 0;
            
            
            for(int j = i; j < rows; j++) {
                if(k >= cols)
                    break;
                mat[j][k] = v[l];
                l++;
                k++;
            }
        }
        
        for(int i = 1; i < cols; i++) {
            int k = 0;
            vector<int> v;
            
            for(int j = i; j < cols; j++) {
                if(k >= rows) 
                    break;
                v.push_back(mat[k][j]);
                k++;
            }
            sort(v.begin(), v.end());
            int l = 0;
            k = 0;
            
            for(int j = i; j < cols; j++) {
                if(k >= rows)  
                    break;
                mat[k][j] = v[l];
                l++;
                k++;
            }
        }
        
        return mat;
    }
};
