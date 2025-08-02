#include <bits/stdc++.h>
using namespace std;
long long dp[3001][3001];
pair<int, int> parent[3001][3001];
string grid[3001];

string ans;
void getParent(int i, int j)
{

    if (parent[i][j].first == i && parent[i][j].second == j){
        ans += grid[i][j] ;
        return ;
    }  
    getParent(parent[i][j].first, parent[i][j].second);
    ans += grid[i][j];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            dp[i][j]= 1e9 ;
            parent[i][j] = {i,j} ;
            if (i == 0 && j == 0)
            {
                dp[i][j] = 0;
                // cout << dp[i][j] << ' ';
                continue;
            }

            int cost = (int)(grid[i][j] - 'A') * abs((n - i)+(n-j));
            if (i > 0)
            {
                dp[i][j] = dp[i - 1][j] + cost;
                parent[i][j] = {i - 1, j};
            }
            if (j > 0 && dp[i][j] > dp[i][j - 1] + cost)
            {
                dp[i][j] = dp[i][j - 1] + cost;
                parent[i][j] = {i, j - 1};
            }
            // cout << dp[i][j] << ' ';
            // cout << cost << ' ' ;
        }
        // cout << '\n';
    }

    getParent(n-1, n-1);
    // ans.reserve();
    cout << ans;
}
signed main()
{
    // int t; cin >> t ; while(t--)
    solve();
}