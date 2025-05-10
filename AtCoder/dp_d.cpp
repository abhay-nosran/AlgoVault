#include <bits/stdc++.h>
#define int long long
using namespace std;
int N , W ;
int weight[103];
int value[103];
int dp[103][10010] ;

int getSum(int level , int w){

    if(level == N){
        return 0 ;
    }

    if(dp[level][w] != -1) return dp[level][w] ;

    int ans = getSum(level+1, w);

    if(w >= weight[level]){
        ans = max(ans , getSum(level+1,w-weight[level]) + value[level]) ;
    }

    return dp[level][w] = ans ;
}


void solve(){
    cin >> N >> W ;

    for (int i = 0; i < N; i++)
    {
        int w , v ; cin >> w >> v;
        weight[i] = w ;
        value[i] = v ;
    }

    memset(dp,-1,sizeof(dp)) ;

    cout << getSum(0,W) ;

}

signed main(){
    // int t ; cin >> t; while(t--)
    solve();
}