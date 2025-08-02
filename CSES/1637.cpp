#include <bits/stdc++.h>
using namespace std;
int MAXI = 1e9 ;
int dp[1000100] ;

void solve(){
    int x ; cin >> x ;
    dp[0] = 0 ;

    for(int i = 1 ; i <= x ; i++){
        dp[i] = MAXI ;
        int temp = i ;
        while(temp){
            int digit = temp%10 ;
            dp[i] = min(dp[i],1+dp[i-digit]) ;
            temp/=10 ;
        }
    }

    cout << dp[x] ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}