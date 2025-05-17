
// Memoization Solution

class Solution {
   private:
    int f(int ind, vector<int>& heights, vector<int>& dp) {
        if (ind == 0) return 0;  // Base Case

        if (dp[ind] != -1) return dp[ind];  // Memoized result

        int one =
            f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
        int two = INT_MAX;
        if (ind > 1)
            two =
                f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

        dp[ind] = min(one, two);
        return dp[ind];
    }

   public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);

        return f(n - 1, heights, dp);
    }
};


// Tabulation 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0; // Base case

        // Iterative calculation
        for (int ind = 1; ind < n; ind++) {
            int jumpOne = dp[ind - 1] + abs(heights[ind] - heights[ind - 1]);
            int jumpTwo = INT_MAX;
            // Store minimum energy for this stair
            if (ind > 1)
                jumpTwo = dp[ind - 2] + abs(heights[ind] - heights[ind - 2]);
            dp[ind] = min(jumpOne, jumpTwo); 
        }
        // Return the minimum energy required to reach the last stair
        return dp[n - 1]; 
    }
};

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    Solution sol;
    cout << sol.frogJump(heights) << endl; // Output the result
    return 0;
}

// Space Optimization
class Solution {
   public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        int prev = 0;
        int prev2 = 0;

        // Iterative calculation
        for (int ind = 1; ind < n; ind++) {
            int jumpOne = prev + abs(heights[ind] - heights[ind - 1]);
            int jumpTwo = INT_MAX;
            // Store minimum energy for this stair
            if (ind > 1) jumpTwo = prev2 + abs(heights[ind] - heights[ind - 2]);

            // Minimum energy for current stair
            int cur_i = min(jumpOne, jumpTwo);
            // Update previous values
            prev2 = prev;
            prev = cur_i;
        }
        // Return the minimum energy required to reach the last stair
        return prev;
    }
};
