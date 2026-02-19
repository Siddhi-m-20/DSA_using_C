#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> knapsack(vector<int>& wt,
                                 vector<int>& val,
                                 int W) {

    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Build DP table
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(wt[i-1] <= w) {
                dp[i][w] = max(
                    dp[i-1][w],
                    val[i-1] + dp[i-1][w - wt[i-1]]
                );
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // Backtrack to find selected items
    vector<int> chosen;
    int w = W;

    for(int i = n; i > 0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            chosen.push_back(i-1);
            w -= wt[i-1];
        }
    }

    reverse(chosen.begin(), chosen.end());

    return {dp[n][W], chosen};
}

int main() {
    vector<int> weights  = {3, 4, 6};
    vector<int> values   = {3, 2, 2};
    int capacity = 6;

    auto [maxVal, chosen] = knapsack(weights, values, capacity);

    cout << "Max value   : " << maxVal << "\n";
    cout << "Items chosen: ";
    for (int i : chosen) cout << "Item" << (i + 1) << " ";
    cout << "\n";

    int totalW = 0;
    for (int i : chosen) totalW += weights[i];
    cout << "Total weight: " << totalW << " / " << capacity << "\n";

    return 0;
}

/*
$ ./a.exe
Max value   : 3
Items chosen: Item1 
Total weight: 3 / 6
*/
