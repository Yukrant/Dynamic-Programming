// Rercursion can be used when the problem is asking for minimum/maximum of something

// To generate all the subsequences, we can use the pick/non-pick technique.

// At every index of the array, we have two options:
// - First, to pick the array element at that index and consider it in our subsequence.
// - Second, to leave the array element at that index and not to consider it in our subsequence.


/* Pseudocode */
f(ind, arr[]){
    //base condition {}
    pick = arr[ind] + f(ind-2, arr)
    notPick = 0 + f(ind - 1, arr)
    return max(pick, notPick)
}

// Function to solve the problem using memoization

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int func(int ind, vector<int> &arr, vector<int> &dp) {
    // Base cases
    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;
    
    if(dp[ind] != -1){
        return dp[ind];
    }
    // Choosing the current element
    int pick = arr[ind] + func(ind - 2, arr, dp);  
    
    // Skipping the current element
    int nonPick = 0 + func(ind - 1, arr, dp);  

    /* Store the result in dp 
    array and return the maximum */
    return dp[ind] = max(pick, nonPick);
}
public:
    /*Function to calculate the maximum
    sum of nonAdjacent elements d*/
    int nonAdjacent(vector<int>& nums) {
        int ind = nums.size()-1;
        
        //Initialize the dp array with -1
        vector<int> dp(ind+1, -1);
        
        //Return the maximum sum
        return func(ind, nums, dp);
    }
};

int main() {
    vector<int> arr{2, 1, 4, 9};
    
    //Create an instance of Solution class
    Solution sol;
    
    // Call the solve function and print the result
    cout << sol.nonAdjacent(arr);

    return 0;
}


// Tabulation

int nonAdjacent(vector<int> &nums) {
    int ind = nums.size();
    vector<int> dp(ind, 0);        
        // Base case
        dp[0] = nums[0];

        // Iterate through the elements of the array
        for (int i = 1; i < ind; i++) {
            
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int no_pick = dp[i - 1];

            // Store the maximum value in dp array
            dp[i] = max(pick, no_pick);
        }

        /* The last element of the dp array
        will contain the maximum sum*/
        return dp[ind-1];
    }


// Space Optimization

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int nonAdjacent(vector<int> &nums) {
        int n = nums.size();
        int prev = nums[0];   
        int prev2 = 0;       
    
        for (int i = 1; i < n; i++) {
            // Maximum sum if we pick current element
            int pick = nums[i];  
            
            if (i > 1){
                //Add the maximum sum two elements ago
                pick += prev2;  
            }
            // Maximum sum if we don't pick current element
            int nonPick = 0 + prev;  
            
            // Maximum at the current element
            int cur_i = max(pick, nonPick); 
            
            prev2 = prev;   
            prev = cur_i;    
        }
        // Return the maximum sum
        return prev;  
    }
};
