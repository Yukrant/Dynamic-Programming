f(ind, buy, cap){
    if (ind == n || cap == 0) {
        return 0;
    }
    if(buy == 0){
        op1 = 0 + f(ind + 1, 0, cap)
        op2 = -arr[ind] + f(ind + 1, 1, cap)
    }
    if(buy == 1){
        op1 = 0 + f(ind + 1, 1, cap)
        op2 = arr[ind] + f(ind + 1, 0, cap-1)
    }
    return max(op1, op2)    
}

vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)))

if (dp[ind][buy][cap] != -1) {
    return dp[ind][buy][cap];
}


// Tabulation
for (int ind = n - 1; ind >= 0; ind--) {
    for (int buy = 0; buy <= 1; buy++) {  
        for (int cap = 1; cap <= 2; cap++) {


The Steps to space optimize the tabulation approach are as follows:
- Declare a 2D vector 'ahead' initialized to 0 (base condition) and another 2D vector 'cur' also set to 0.
- Then initialize three nested loops to calculate the 'cur' array’s values. Replace dp[ind] with 'cur' and dp[ind+1] with ahead in our tabulation code.
- After the inner loop execution, set 'ahead' as 'cur' for the next outer loop iteration. At last, return ahead[0][2] as our answer.

vector<vector<int>> ahead(2, vector<int>(3, 0));
vector<vector<int>> cur(2, vector<int>(3, 0));