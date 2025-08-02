#include <bits/stdc++.h>
using namespace std;
int dp[501][501] ;
void solve(){
    int x , y ; cin >> x >> y ;

    for(int i = 0 ; i <= x ; i++){
        for(int j = 0 ; j <= y ; j++){

            if(i == j) dp[i][j] = 0 ;
            else {
                dp[i][j] = 1e9 ;
                for(int a = 1 ; a < i ; a++){
                    dp[i][j] = min(dp[i][j],1+dp[i-a][j]+dp[a][j]);
                }
                for(int b = 1 ; b < j ; b++){
                    dp[i][j] = min(dp[i][j],1+dp[i][j-b]+dp[i][b]) ;
                }
            }
            
        }
    }

    cout << dp[x][y] ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}