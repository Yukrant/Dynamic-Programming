int func(int i, int j, vector<vector<int> > &triangle, int n) {
    // If we're at bottom row, return value of current cell
    if (i == n - 1)
        return triangle[i][j];

    // Calculate the sum of two possible paths
    int down = triangle[i][j] + func(i + 1, j, triangle, n);
    int diagonal = triangle[i][j] + func(i + 1, j + 1, triangle, n);

    // Return the minimum of the two paths
    return min(down, diagonal);
}

Time Complexity: O(2^N)
Space Complexity:O(N)

<===================================================================>

// Memoization

Simple as prev problems just to create dp vector
int n = matrix.size();
vector<vector<int>> dp(n, vector<int>(n, -1));

Time Complexity: O(N)
Space Complexity:O(N) + O(N*N)

// Tabulation 

int minTriangleSum(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    /* Initialize the bottom row of dp with the values from the triangle*/
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }

    // Top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

Time Complexity: O(N*N)
Space Complexity:O(N*N)

==================================================================================

// Space Optimaization

int minTriangleSum(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    /* Create two arrays to store the current and previous row values*/

    // Represents the previous row
    vector<int> front(n, 0);

    // Represents the current row
    vector<int> cur(n, 0);

    /* Initialize the front array with values from the last row of the triangle*/
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }

    // Iterate through triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate minimum path sum for current cell
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            /* Store the minimum of the two
            possible paths in the current row*/
            cur[j] = min(down, diagonal);
        }
        /* Update the front array with
        the values from the current row*/
        front = cur;
    }

    /* The front array now contains the minimum path
    sum from the top to the bottom of the triangle*/
    return front[0];
}

Time Complexity: O(N*N)
Space Complexity:O(N)+O(N)