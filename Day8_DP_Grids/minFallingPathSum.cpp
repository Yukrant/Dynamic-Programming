// Recursive Solution

/*It is pseudocode  and it is not tied to 
any specific programming  language*/

f(i,j){
    //Base case
    if(j < 0 || j > M)   return   INT_MAX
    if(i == 0)   return mat[0][j]
    
    //code
    down =  mat[i][j] + f(i+1, j)
    diagonalRight = mat[i][j] + f(i+1, j+1)
    diagonalLeft = mat[i][j] + f(i+1, j-1)
    return min(down, diagonalLeft, diagonalRight)
}

Time Complexity: O(3^N)
Space Complexity : O(N)


// Memoization

class Solution {
   public:
    int func(int i, int j, int m, vector<vector<int>> &matrix,
             vector<vector<int>> &dp) {
        if (j < 0 || j >= m) return 1e9;
        if (i == 0) return matrix[0][j];

        if (dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + func(i - 1, j, m, matrix, dp);
        int leftDiagonal = matrix[i][j] + func(i - 1, j - 1, m, matrix, dp);
        int rightDiagonal = matrix[i][j] + func(i - 1, j + 1, m, matrix, dp);

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }

    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int mini = INT_MAX;

        /* Iterate through each cell in the first row
        to find minimum path sum starting from each of them*/
        for (int j = 0; j < m; j++) {
            int ans = func(n - 1, j, m, matrix, dp);
            mini = min(mini, ans);
        }
        return mini;
    }
};


// Tabulation

class Solution{
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 

        vector<vector<int>> dp(n, vector<int>(m, 0));

        /* Initialize the first row of dp with values from the matrix */
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        /* Iterate through the matrix rows starting from the second row*/
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                /* Calculate the minimum path sum for the
                current cell considering three possible 
                directions: up, left diagonal, and right diagonal*/

                // Up direction
                int up = matrix[i][j] + dp[i - 1][j];

                // Left diagonal direction (if it's a valid move)
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += 1e9; 
                }

                // Right diagonal direction 
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += 1e9;  
                }

                // Store the minimum of the three paths in dp
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        /* Find the minimum value in the last row of dp, which
        represents the minimum path sums ending at each cell*/
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        // Minimum path sum is the minimum value in last row
        return mini;
    }
};

