Multiple Buys and Sells

// Recursive solution:

class Solution {
   private:
    int func(int ind, int buy, int n, vector<int> &arr) {
        if (ind == n) {
            return 0;
        }

        int profit = 0;

        // We can buy the stock
        if (buy == 0) {
            profit = max(0 + func(ind + 1, 0, n, arr),
                         (-1) * arr[ind] + func(ind + 1, 1, n, arr));
        }

        // We can sell the stock
        if (buy == 1) {
            profit = max(0 + func(ind + 1, 1, n, arr),
                         arr[ind] + func(ind + 1, 0, n, arr));
        }

        return profit;
    }

   public:
    int stockBuySell(vector<int> arr, int n) {
        if (n == 0) return 0;

        return func(0, 0, n, arr);
    }
};

Time Complexity: O(2(N))
Space Complexity:O(N)

// Memoization

vector<vector<int>> dp(n, vector<int>(2, -1));

Time Complexity: O(N*2)
Space Complexity:O(N*2) + O(N)

// Tabulation 

int stockBuySell(vector<int> arr, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    dp[n][0] = dp[n][1] = 0;

    int profit;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            // We can buy the stock
            if (buy == 0) {
                profit =
                    max(0 + dp[ind + 1][0], (-1) * arr[ind] + dp[ind + 1][1]);
            }

            // We can sell the stock
            if (buy == 1) {
                profit = max(0 + dp[ind + 1][1], arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

// Space Optimization 

- Declare two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding).
- For the case condition, set ahead[0] and ahead[1] to 0, as when there are no stocks left, the profit is 0.
- Then, initiate two nested for loops to calculate the 'cur' column values. Replace dp[ind] with 'cur' and dp[ind+1] with 'ahead' in our memoization code.
- After the inner loop execution, set 'ahead' as 'cur' for the next outer loop iteration. At last, return cur[0] as our answer.

Time Complexity: O(N*2)
Space Complexity: O(1)