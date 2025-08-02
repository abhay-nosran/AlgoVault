#include <bits/stdc++.h>
using namespace std;
long long dp[100010] ;
int mod = 1e9 + 7 ;
int binPow(int a ,int b){
    
    if(b == 0) return 1 ;

    if(b%2 == 1){
        // b odd 
        return (1LL*a*binPow(a,b-1))%mod ;
    }else{
        int x = binPow(a,b/2) ;
        return (1LL*x*x)%mod ;
    }
}
int inverse(int x){
    return binPow(x,mod-2) ;
}
void solve(){
    int n ; cin >>n ;

    int sum = (n*(n+1))/2 ;

    if(sum % 2 == 1){
        cout << 0 ;
        return ;
    }
    sum /= 2 ;
    dp[0] = 1LL ;

    for(int i = 1 ; i <= n ; i++){
        for(int x = sum ; x >= 1 ; x--){
            if(x>=i) dp[x] += dp[x-i] ;
            dp[x] %= mod ;
        }
    }
    cout << (dp[sum] * inverse(2))%mod ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}