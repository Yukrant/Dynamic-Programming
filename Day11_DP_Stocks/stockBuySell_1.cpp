int stockBuySell(vector<int> &arr, int n) {
    int maxProfit = 0;
    int mini = arr[0];

    for (int i = 1; i < n; i++) {
        int curProfit = arr[i] - mini;

        maxProfit = max(maxProfit, curProfit);

        mini = min(mini, arr[i]);
    }
    return maxProfit;
}