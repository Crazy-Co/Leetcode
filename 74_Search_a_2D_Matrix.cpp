class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row-1;
        int mid;

        while(low<=high){
            mid = (low+high)/2;

            if(matrix[mid][0] == target || matrix[mid][col-1] == target) return true;
            else if(matrix[mid][0] < target && target < matrix[mid][col-1]){
                int r = mid;
                low = 1;
                high = col-2;
                
                while(low<=high){
                    mid = (low+high)/2;

                    if(matrix[r][mid] == target) return true;
                    else if(matrix[r][mid] < target){
                        low = mid+1;
                    }
                    else if(matrix[r][mid] > target){
                        high = mid-1;
                    }
                }
                break;
            }
            else if(matrix[mid][col-1] < target){
                low = mid+1;
            }
            else if(matrix[mid][0] > target){
                high = mid-1;
            }
        }

        return false;

        // linear searching

        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;
    }
};