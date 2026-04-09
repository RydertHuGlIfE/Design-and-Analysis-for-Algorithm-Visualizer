#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 4, W = 5;
    vector<int> wt  = {2, 3, 4, 5};
    vector<int> val = {3, 4, 5, 6};

    cout << "CONFIG " << n << " " << W << endl;
    for (int i = 1; i <= n; i++)
        cout << "DEF " << i << " " << wt[i-1] << " " << val[i-1] << endl;

    // Build DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
            cout << "CELL " << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    // Backtrack to find selected items
    int i = n, j = W;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            cout << "PICK " << i << endl;
            j -= wt[i-1];
        }
        i--;
    }

    cout << "MAX " << dp[n][W] << endl;
    return 0;
}
