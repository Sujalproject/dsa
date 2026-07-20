class Solution {
public:
    int fun(vector<vector<int>>& matrix, int n,int m , int guess){
        int row = n-1;
        int col = 0;
        int ans = 0;
        while(row>=0 && col<m){
            if(matrix[row][col]<=guess){
                ans+= row+1;
                col++;
            }
            else{
                row--;
            }
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        int res = -1;
        while(low<=high){
            int guess = (low+high)/2;
            if(fun(matrix,n,m,guess)<k){
                low = guess+1;
            }
            else{
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};