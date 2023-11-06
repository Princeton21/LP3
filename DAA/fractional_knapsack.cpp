#include <bits/stdc++.h>
using namespace std;

// fractional knapsack
// greedy approach
// TC - O(nlogn)
// SC - O(n)
void solve()
{
    int n;
    cin >> n;

    vector<vector<double>> v;
    for (int i = 0; i < n; ++i){
        double weight, profit;
        cin >> weight >> profit;

        double ratio = (double)profit / weight;
        v.push_back({ratio, profit, weight});
    }
    sort(v.rbegin(), v.rend());

    // for (int i = 0; i < n; ++i)
    //     cerr << v[i][2] << " " << v[i][1] << " " << v[i][0] << endl;

    double capacity;
    cin >> capacity;

    double totalProfit = 0;
    for (int i = 0; i < n; ++i){
        if (capacity - v[i][2] >= 0){
            capacity -= v[i][2];
            totalProfit += v[i][1];
        }
        else{
            totalProfit += v[i][0] * capacity;
            break;
        }
    }
    cout << "Final profit = " << totalProfit << endl;
}
int main(){
    solve();
}

/*
4
10 8
5 10
15 8
20 10
33
*/
// output - Final profit = 27.5
