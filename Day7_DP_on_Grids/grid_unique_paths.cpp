
// Recursive Solution

f(i,j){
    if (i == 0 && j == 0)  return 1; //Base case
    if (i < 0 || j < 0)  return 0; // out of bounds

    up = f(i-1, j)
    left = f(i, j-1)
    return up+left
}


// Memoization 

class Solution {
   private:
    int func(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;  // Base case
        if (i < 0 || j < 0) return 0;    // out of bounds

        if (dp[i][j] != -1) return dp[i][j];

        int up = func(i - 1, j, dp);
        int left = func(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

   public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(m - 1, n - 1, dp);
    }
};

/*
Time Complexity: O(M*N), where M is the number of row and N is the number of column in 2D array. At max, there will be M*N calls of recursion as the subproblems can go upto M*N.

Space Complexity: O((N-1)+(M-1)) + O(M*N), We are using a recursion stack space: O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.
*/

// Tabulation


Memo --> Tabulation

- Declare base cases.
- Express all steps in for loop
- Copy the recurance and write

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Base condition
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            /* Initialize variables to store the number
            of ways from cell above (up) and left (left)*/
            int up = 0;
            int left = 0;

            /* If we are not at first row (i > 0), update
            'up' with the value from the cell above.*/
            if (i > 0) up = dp[i - 1][j];

            /* If we are not at the first column (j > 0),
            update 'left' with value from the cell to left.*/
            if (j > 0) left = dp[i][j - 1];

            /* Calculate the number of ways to reach the
            current cell by adding 'up' and 'left'.*/
            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

// Space Optimization

int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> temp(
            n, 0);  // Create temporary vector to represent the current row.
        for (int j = 0; j < n; j++) {
            // Base condition
            if (i == 0 && j == 0) {
                temp[j] = 1;
                /* Skip the rest of the loop and
                continue with the next iteration.*/
                continue;
            }

            /* Initialize variables to store the number
            of ways from cell above (up) and left (left)*/
            int up = 0;
            int left = 0;

            /* If we are not at first row (i > 0), update
            'up' with the value from the cell above.*/
            if (i > 0) up = prev[j];

            /* If we are not at the first column (j > 0),
            update 'left' with value from the cell to left.*/
            if (j > 0) left = temp[j - 1];

            /* Calculate the number of ways to reach the
            current cell by adding 'up' and 'left'.*/
            temp[j] = up + left;
        }
        prev = temp;
    }

    return prev[n - 1];
}