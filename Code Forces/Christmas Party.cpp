#include <bits/stdc++.h>
using namespace std ;
#define int long long
int mod = 1e9 + 7 ;




signed main(){
    int n ; cin >> n ;
    vector<int> dp(n+1,-1) ;

    dp[0] = 1 ; dp[1] = 0 ;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = ((i-1)*(dp[i-2] + dp[i-1])%mod)%mod ;
    }
    
    cout << dp[n] ;

}


