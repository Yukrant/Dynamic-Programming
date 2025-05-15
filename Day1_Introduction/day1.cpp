// Introduction To Dynamic Programming

// Approaches :

// Memoization: Known as “top-down” dynamic programming, it usually solves the problem from 
//              the main problem to the base cases.

// Steps to Memoize a Recursive Solution =>
// - Create a dp[n+1] array initialized to -1.
// - Check if the answer is already calculated using the dp array (dp[n] != -1). If yes, return the value.
// - If not, compute the value and store it in the dp array before returning.



// Tabulation: Known as “bottom-up” dynamic programming, it solves the problem from 
//             the base cases to the main problem.

// Steps to Convert Recursive Solution to Tabulation =>
// - Declare a dp[] array of size n+1.
// - Initialize base condition values, i.e.(for Fibonacci Numbers), i=0 and i=1 of the dp array 
//   as 0 and 1 respectively.
// - Use an iterative loop to traverse the array (from index 2 to n) and 
//   set each value as dp[i-1] + dp[i-2].