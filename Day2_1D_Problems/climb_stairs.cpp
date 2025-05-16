// Identify a DP problem :
// - Problem asking for count the total number ways.
// - Given multiple ways of performing a task, it is asked which way
//   will yield the minimum or maximum output.

// If the question asks for either of the above two points mentioned earlier, 
// recursion can be applied to attempt solving the problem. Once the recursive solution is obtained, 
// it can be converted into a dynamic programming approach.

// How to write ruccurence relation:
// Once the problem has been identified, the following three steps comes handy in solving the problem:
// - Try to represent the problem in terms of indexes.
// - Try all possible choices/ways at every index according to the problem statement.
// - If the question states "count all the ways," then the sum of all choices/ways should be returned. 
//   If the question asks to find "the maximum/minimum", then the choice/way with the maximum/minimum output should be returned.

/*It is pseudocode and not tied to 
any specific programming language.*/
f(n){
      oneStep = f(n-1)
      twoStep = f(n-2)
      return oneStep + twoStep
}


// Memoization
class Solution {
private:
    int func(int n, vector<int> &dp) {
        if (n <= 1) { // edge case
            return 1;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        }
        
        return dp[n] = func(n-1, dp) + func(n-2, dp);
    }
    
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1); 
        
        return func(n, dp);
    }
};

// 