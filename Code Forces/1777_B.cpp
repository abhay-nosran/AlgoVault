#include <bits/stdc++.h>
#define int long long 
using namespace std ;
int mod = 1e9 + 7 ;
int fact[100100] ;
void preCompute(){
    fact[0] = 1 ;
    for (int i = 1; i < 100100; i++)
    {
        fact[i] = (i*fact[i-1])%mod ;
    }
    
}
void solve(){
    int n ; cin >> n ;

    int ans = ((n*(n-1))%mod*fact[n])%mod ;
    cout << ((ans+mod)%mod) << '\n' ;
}

signed main(){
    int t ; cin >>t  ;
    preCompute() ;
    while (t--)
    {
        solve() ;
    }
    
}