class Solution{
private:
    /* Function to find the maximum cherries
    that can be collected recursively*/
    int func(int i, int j1, int j2, int n, int m, vector<vector<int>> &matrix) {
        // Base cases
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9; 

        if (i == n - 1) {
            if (j1 == j2)
                return matrix[i][j1];
            else
                return matrix[i][j1] + matrix[i][j2];
        }

        int maxi = INT_MIN;
    
        // Try all possible moves for both positions (j1, j2)
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;
            
                if (j1 == j2)
                    ans = matrix[i][j1] + func(i + 1, j1 + di, j2 + dj, n, m, matrix);
                else
                    ans = matrix[i][j1] + matrix[i][j2] + func(i + 1, j1 + di, j2 + dj, n, m, matrix);
            
                // Update the maximum result
                maxi = max(maxi, ans);
            }
        }
    
        //Return the maximum cherries collected
        return maxi;
    }
public:
    // Function to find maximum cherries that can be collected
    int cherryPickup(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //Return the maximum cherries collected
        return func(0, 0, m - 1, n, m, matrix);
    }
};


Time Complexity: O(3(N)*3(N)), where N is the number of row.
Space Complexity:O(N), at maximum the depth of the recursive stack can go upto N.

/// Memoization 

// Initialize a 3D DP array to store computed results
vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

Time Complexity: O(N*M*M) * 9. At max, there will be N*M*M calls of recursion to solve a new problem and in every call, two nested loops together run for 9 times.
Space Complexity:O(N) + O(N*M*M). 