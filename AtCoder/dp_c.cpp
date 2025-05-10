#include <bits/stdc++.h>
using namespace std;
int N ;
int a[10010] ;
int b[10010] ;
int c[10010] ;
int dp[10010][4] ;

int help(int level , int prevTaken){

    if(level == N) return 0 ;

    if(dp[level][prevTaken] != -1) return dp[level][prevTaken] ;
    
    int ans = 0 ;
    if(prevTaken != 1){
        ans = max(ans,a[level] + help(level+1,1)) ;
    }
    if(prevTaken != 2){
        ans = max(ans,b[level] + help(level+1,2)) ;
    }
    if(prevTaken != 3){
        ans = max(ans,c[level] + help(level+1,3)) ;
    }

    return dp[level][prevTaken] = ans ;

}
void solve(){
    cin >> N ;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i] ;
        cin >> b[i] ;
        cin >> c[i] ;
    }
    memset(dp,-1,sizeof(dp)) ;
    cout << help(0,0) ;
}

signed main(){
    // int t ; cin >> t; while(t--)
    solve();
}