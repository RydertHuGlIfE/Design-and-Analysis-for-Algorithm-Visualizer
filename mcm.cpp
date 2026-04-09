#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

string parens(vector<vector<int>>& s, int i, int j) {
    if (i == j) return "M" + to_string(i);
    return "(" + parens(s, i, s[i][j]) + parens(s, s[i][j]+1, j) + ")";
}

int main() {
    int n = 4;
    vector<int> p = {10, 30, 5, 60, 5};

    cout << "CONFIG " << n << endl;
    for (int i = 1; i <= n; i++)
        cout << "DIM " << i << " " << p[i-1] << " " << p[i] << endl;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<vector<int>> sp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++)
        cout << "CELL " << i << " " << i << " 0" << endl;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n-len+1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if (cost < dp[i][j]) { dp[i][j] = cost; sp[i][j] = k; }
            }
            cout << "CELL " << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    cout << "OPTIMAL " << dp[1][n] << " " << parens(sp, 1, n) << endl;
    return 0;
}
