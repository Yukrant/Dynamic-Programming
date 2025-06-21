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

//