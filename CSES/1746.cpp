#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7 ;
int arr[100010] ;
int dp[100010] ;
int n , m ;
int rec(int index){

    if(index == n) return 1 ;

    if(dp[index] != -1) return dp[index] ;
    long long cnt = 0LL ; 
    if(arr[index] == 0){

        
        for(int i = -1 ; i < 2 ; i++){
            arr[index] = arr[index-1] + i ;
            if(1 <= arr[index] && arr[index] <= m) cnt = (cnt + rec(index+1))%mod ;
            arr[index] = 0 ;
        }

        return dp[index] = (int)cnt ;
    }else{
        // fixed 
        if(abs(arr[index-1] - arr[index]) <= 1) cnt = rec(index+1) ;
        return dp[index] = (int)cnt ;
    }
}
void solve(){
    cin >> n>> m ;
    memset(dp,-1,sizeof(dp))  ; 
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    long long ans = 0LL; 
    if(arr[0] == 0){    
        for(int i = 1 ; i <= m ; i++){
            arr[0] = i ;
            ans = (ans + rec(1))%mod ;
            arr[0] = 0 ;
        }
    }else{
        ans = rec(1) ;
    }

    cout << ans ;

}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}