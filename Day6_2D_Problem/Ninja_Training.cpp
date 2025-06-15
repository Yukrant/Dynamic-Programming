// Greedy solution :

/*
The greedy solution imposes restrictions on our choices, we can lose activity with better points on the next day in the greedy solution. Therefore, it is more advantageous to explore all possible choices as our next solution. 
*/ 

// Recursive solution:

/*
- Express the problem in terms of indexes
- Try out all possible choices at a given index
- Take the maximum of all choices
*/

/* Pseudocode */
f(day,last){
    if(day == 0){
        maxi = 0
        for(int i = 0; i <= 2; i++){
            if(i != last)   maxi = max(maxi,points[0][i])
        }
        return maxi
    } 
    maxi = 0
    for(int i = 0; i <= 2; i++){
        if(i != last){
            activity = points[day][i] + f(day-1, i)
            maxi = max(maxi, activity)
        }
    }
    return maxi

}

// Time Complexity: O(3N), where N is the given size of 2D array. Exponential due to the recursive nature where each day can have up to 3 choices.

// Space Complexity:O(N), As the recursion depth is equal to the number of days (days).

/*=======================================================================================================*/

// Memoization

class Solution {
private:
    /* Recursive function to calculate the maximum points for the ninja training*/
    int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
        /* If the result for this day and last activity is already calculated, return it*/
        if (dp[day][last] != -1) return dp[day][last];
        
        // Base case
        if (day == 0) {
            int maxi = 0;
        
            /* Calculate the maximum points for first day by choosing an activity different from last one*/
            for (int i = 0; i <= 2; i++) {
                if (i != last)  maxi = max(maxi, points[0][i]);
            }
        // Store the result in dp array and return it
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    
    // Iterate through activities for the current day
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            
            /* Calculate the points for the current activity
            and add it to the maximum points obtained so far */
            int activity = points[day][i] + func(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }

    // Store the result in dp array and return it
    return dp[day][last] = maxi;
}
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int day = matrix.size();
        
        /* Create a memoization table to store intermediate results*/
        vector<vector<int>> dp(day, vector<int>(4, -1));
        
        int last = 3;
        return func(day-1, last, matrix, dp);
    }
};

// T => O(N*4*3)
// S => O(N) + O(N*4) =>>> O(N)

/*==============================================================================================*/

// Tabulation

class Solution {
public:
    /* Function to calculate the maximum
    points for the ninja training*/
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Create a 2D DP table to store the maximum points
        vector<vector<int>> dp(n, vector<int>(4, 0));

       // Initialize the DP table for the first day (day 0)
       dp[0][0] = max(matrix[0][1], matrix[0][2]);
       dp[0][1] = max(matrix[0][0], matrix[0][2]);
       dp[0][2] = max(matrix[0][0], matrix[0][1]);
       dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

       // Iterate through the days starting from day 1
       for (int day = 1; day < n; day++) {
           for (int last = 0; last < 4; last++) {
               dp[day][last] = 0;
               // Iterate through the tasks for the current day
               for (int task = 0; task <= 2; task++) {
                   if (task != last) {
                        /* Calculate the points for the current 
                        activity and add it to the maximum points
                        obtained on the previous day */
                        int activity = matrix[day][task] + dp[day - 1][task];
                   
                        /* Update the maximum points for 
                        the current day and last activity*/
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
       }

       /* The maximum points for the last day with 
       any activity can be found in dp[n-1][3]*/
       return dp[n - 1][3];
    }
};


/*============================================================================*/

// Space optimized

class Solution {
public:
    /* Function to calculate the maximum
    points for the ninja training*/
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        /* Initialize a vector to store the maximum
        points for the previous day's activities*/
        vector<int> prev(4, 0);

        // Initialize the prev array for the first day (day 0)
        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        // Iterate through the days starting from day 1
        for (int day = 1; day < n; day++) {
            /* Create a temporary vector to store the
            maximum points for the current day's activities*/
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++) {
                temp[last] = 0;
                // Iterate through the tasks for the current day
                for (int task = 0; task <= 2; task++) {
                    if (task != last) {
                    /* Calculate the points for the current activity
                    and add it to the maximum points obtained on the
                    previous day (stored in prev)*/
                    temp[last] = max(temp[last], matrix[day][task] + prev[task]);
                }
            }
        }
        // Update prev with maximum points for the current day
        prev = temp;
       }

        /* The maximum points for the last day with 
        any activity can be found in prev[3]*/
        return prev[3];
    }
};