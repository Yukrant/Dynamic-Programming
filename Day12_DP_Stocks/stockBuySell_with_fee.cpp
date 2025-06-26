class Solution{
private:
    //Function to find the maximum profit earned using recursion
    int func(int ind, int buy, int fee, int n, vector<int> &arr) {
        // Base case 
        if (ind == n) {
            return 0;
        }

        int profit;
        
        // We can buy the stock
        if (buy == 0) { 
            profit = max(0 + func(ind + 1, 0, fee, n, arr), (-1)*arr[ind] + func(ind + 1, 1, fee, n, arr));
        }
        
        //We can sell the stock
        if (buy == 1) { 
            profit = max(0 + func(ind + 1, 1, fee, n, arr), arr[ind]-fee + func(ind + 1, 0, fee, n, arr));
        }

        // Return the calculated profit
        return profit;
    }
public:
    //Function to calculate the maximum profit earned 
    int stockBuySell(vector<int> &arr, int n, int fee) {
        if (n == 0) 
            return 0;

        int ans = func(0, 0, fee, n, arr);
        
        //Return the maximum profit
        return ans;
    }
};


/////////////

Memoization

vector<vector<int>> dp(n, vector<int>(2, -1));

if (dp[ind][buy] != -1) {
    return dp[ind][buy];
}

///////////////////

Tabulation

vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    /* Base case: dp array is already initialized
    to 0, covering the base case.*/

    // Iterate backwards through the prices array
    for (int ind = n - 1; ind >= 0; ind--) {
        // buy can be 0 (buying) or 1 (selling)
        for (int buy = 0; buy <= 1; buy++) {