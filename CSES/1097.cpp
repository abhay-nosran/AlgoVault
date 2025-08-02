#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n ; 
pair<int,int> dp[5001][5001];
int arr[5001] ;

void solve(){
    cin >> n ; 

    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;

    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j <= n-1 ; j++){

            if(i > j) continue; 

            if(i == j){
                dp[i][j].first = arr[i] ;
                dp[i][j].second = 0 ; 
                
            }else{


                dp[i][j].first = arr[i] + dp[i+1][j].second ;
                dp[i][j].second =  dp[i+1][j].first ;

                if(dp[i][j].first < arr[j]+dp[i][j-1].second){
                    dp[i][j].first = arr[j] + dp[i][j-1].second ;
                    dp[i][j].second =  dp[i][j-1].first ;
                }

                if(dp[i][j].first == arr[j]+dp[i][j-1].second){
                    dp[i][j].second = min(dp[i+1][j].first , dp[i][j-1].first);
                }

            }

            // cout << "(" << dp[i][j].first << ',' << dp[i][j].second << ")" << ' ' ;
        }

        // cout << '\n' ;
    }

    cout << dp[0][n-1].first ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}