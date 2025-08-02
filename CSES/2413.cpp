#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1000100][2] ;
int mod = 1e9 + 7 ;
void precompute(){

    dp[1][0] = 1 ;
    dp[1][1] = 1 ;
    for(int i = 2 ; i < 1000100 ; i++){
        
        dp[i][0] = (2*dp[i-1][0] + dp[i-1][1])%mod ;
        dp[i][1] = (dp[i-1][0] + 4*dp[i-1][1])%mod ;
    }
}
void solve(){
    int n ; cin >> n ;

    cout << (dp[n][0] + dp[n][1])%mod << '\n'; 
}
signed main(){
    precompute() ;
    int t; cin >> t ; while(t--)
    solve();
}