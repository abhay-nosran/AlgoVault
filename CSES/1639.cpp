#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];

void solve(){
 
    // convert s to t
    string s , t ;
    cin >> s >> t ;
    int n = s.size() ; 
    int m = t.size() ;
    // for(int i = 0 ; i <= n ; i++) dp[i][m] = n-i+1 ; // i to n chars left 
    // for(int i = 0 ; i <= m ; i++) dp[n][i] = m-i+1 ; // i to m chars left
    // dp[n][m] = 0 ;

    for(int i = n ; i >= 0 ; i--){
        for(int j = m ; j >= 0 ; j--){

            if(i == n || j == m){
                dp[i][j] = n-i + m - j ;
            }else{
                dp[i][j] = min({
                1+dp[i+1][j],
                1+dp[i][j+1],
                dp[i+1][j+1] + (s[i]==t[j] ? 0 : 1)});
            }
            
        }
    }

    cout << dp[0][0] ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}