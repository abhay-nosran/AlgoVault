#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001] ;
long long dp[1001] ;
int mod = 1e9 + 7 ; 
void solve(){
    int n ; cin >> n ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j ++){
            cin >> grid[i][j] ;
        }
    }

    dp[1] = 1LL ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j ++){
            if(grid[i][j] == '*') dp[j] = 0LL ;
            else dp[j]= (dp[j] + dp[j-1])%mod ;
        }
    }

    cout << dp[n] ;
    
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}