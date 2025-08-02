    #include <bits/stdc++.h>
    using namespace std;
    int mod = 1e9 + 7 ;
    long long dp[1000100] ;
    void solve(){
        int n , W ; 
        cin >> n >> W ;

        int coins[n] ;
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        dp[0] = 1LL ;
        for(int i = 1 ; i <= W ; i++){

            for(auto &it : coins){
                if(i >= it){
                    dp[i] = (dp[i] + dp[i - it])%mod ;
                }
            }
        }
        cout << dp[W] ;
    }
    signed main(){
        //int t; cin >> t ; while(t--)
        ios_base::sync_with_stdio(0) ;
        cin.tie(0); cout.tie(0) ;
        solve();
    } 