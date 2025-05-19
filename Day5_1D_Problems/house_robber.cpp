#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    //Function to solve the problem using recursion
    int func(int ind, vector<int> &arr){
        
        //Base case
        if (ind == 0) 
            return arr[ind];
        if (ind < 0)  
            return 0;

        // Choosing the current element
        int pick = arr[ind] + func(ind - 2, arr);  
    
        // Skipping the current element
        int nonPick = 0 + func(ind - 1, arr);  

        // Return the maximum 
        return max(pick, nonPick);
    }
public:
    //Function to find the maximum money robber can rob
    int houseRobber(vector<int>& money) {
        int n = money.size();
        vector<int> arr1;
        vector<int> arr2;
       
        //If array has only one element, return that
        if(n==1)
           return money[0];
        
        for(int i=0; i<n; i++){
            /*Store every element in 
            arr1 except the last element*/
            if(i!=n-1) arr1.push_back(money[i]);
            
            /*Store every element in 
            arr2 except the first element*/
            if(i!=0) arr2.push_back(money[i]);
        }
    
        int ans1 = func(arr1.size()-1, arr1);
        int ans2 = func(arr2.size()-1, arr2);
    
        //Return the maximum of an1 and ans2
        return max(ans1,ans2);
    }
};

int main(){
    vector<int> arr{1,5,1,2,6};
 
    //Create an  instance of Solution class
    Solution sol;
    
    //Print the solution
    cout<<sol.houseRobber(arr);
}

// Memoization work same as previous problem