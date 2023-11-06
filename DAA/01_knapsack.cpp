#include <bits/stdc++.h>
using namespace std;

//  01 knapsack problem
// recursive approach
// TC - O(2^n)
// TC after memoization - O(n*capacity)
// SC - O(n*capacity)

int func(int i, int capacity, vector<int> &weight, vector<int> &profit, vector<vector<int>> &memo){
    if (i >= weight.size())
        return 0;
    if (memo[i][capacity] != -1)
        return memo[i][capacity];
    int take = 0;
    if (capacity - weight[i] >= 0)
        take = func(i + 1, capacity - weight[i], weight, profit,memo) + profit[i];
    int notTake = func(i + 1, capacity, weight, profit,memo);
    return memo[i][capacity] = max(take, notTake);
}

void solve(){
    int n;
    cin >> n;
    vector<int> weight(n), profit(n);

    for (int i = 0; i < n; ++i) cin >> weight[i];
    for (int i = 0; i < n; ++i) cin >> profit[i];

    int capacity;
    cin >> capacity;

    // recursive approach

    vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1));
    cout << "recursive approach : " << func(0, capacity, weight, profit, memo) << endl;

    // iterative approach

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= capacity; ++j){
            if (j - weight[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + profit[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << "iterative approach : " << dp[n][capacity] << endl;
    // TC - O(n * capacity)
    // SC - O(n * capacity)
}
int main(){
    solve();
}
/*
4
3 4 6 5
2 3 1 4
8
*/
// output - recursive approach : 6
//          iterative approach : 6