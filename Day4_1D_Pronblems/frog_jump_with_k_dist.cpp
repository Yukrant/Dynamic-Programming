// Memoization

class Solution {
   private:
    int func(int ind, vector<int>& heights, int k, vector<int>& dp) {
        if (ind == 0) return 0;
        int mmStep = INT_MAX;

        if (dp[ind] != -1) return dp[ind];
        for (int j = 1; j <= k; j++) {
            if (ind - j >= 0) {
                int jump = func(ind - j, heights, k, dp) +
                           abs(heights[ind] - heights[ind - j]);

                mmStep = min(jump, mmStep);
            }
        }

        return dp[ind] = mmStep;
    }

   public:
    int frogJump(vector<int>& heights, int k) {
        int ind = heights.size() - 1;
        vector<int> dp(ind + 1, -1);

        return func(ind, heights, k, dp);
    }
};


// Tabulation -> T : O(N*k)

int frogJump(vector<int> &heights, int k) {
        int ind = heights.size();

        /*Initialize a memoization array
        to store calculated results*/
        vector<int> dp(ind + 1, -1);

        dp[0] = 0;

        // Loop through the array 
        for (int i = 1; i < ind; i++) {
            int mmSteps = INT_MAX;

            // Loop to try all possible jumps from '1' to 'k'
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    
                    //Update the Minimum energy
                    mmSteps = min(jump, mmSteps);
                }
            }
            dp[i] = mmSteps;
        }
        //Result is stored in the last element of dp
        return dp[ind - 1]; 

    }


    // For space Optimization -> No need as in worst case we need O(N)