#include <bits/stdc++.h>
#define int long long 
using namespace std;
int arr[10010] ; 
int dp[3002][3002][2] ;
int dp2[3002][3002][2] ;
int rec(int i , int j , int player){

    if(i == j){
        if(player == 0) return arr[i] ;
        else return -arr[i] ;
    }
    
    if(dp[i][j][player] != -1 || dp2[i][j][player] == 1){ 
        return dp[i][j][player] ;
    }
    dp2[i][j][player] == 1 ;
    if(player == 0){
        return dp[i][j][player] = max(rec(i+1,j,1) + arr[i],rec(i,j-1,1)+arr[j]);
    }else{
        return dp[i][j][player] = min(rec(i+1,j,0) - arr[i],rec(i,j-1,0)-arr[j]);
    }
    
}
void solve(){
    int n ; cin >> n ;
    memset(dp,-1,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    cout << rec(0,n-1,0)  << '\n' ;
}

signed main(){
    solve();
}