#include <bits/stdc++.h>
using namespace std;
int arr[1001] ;
int brr[1001] ;
int dp[1001][1001] ;
pair<int,int> parent[1001][1001] ;
vector <int> ans ;
void lcs(int i , int j){
    
    if(parent[i][j] == make_pair(i,j)) return ;

    if((parent[i][j].first == i-1) && (parent[i][j].second == j-1)) ans.push_back(arr[i]) ;

    lcs(parent[i][j].first , parent[i][j].second) ;

}
void solve(){
    int n , m ; cin >> n >> m ;
    
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ;
    }
    for(int i = 1 ; i <= m ; i++){
        cin >> brr[i] ;
    }

    brr[0] = 1 ;
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){

            parent[i][j] = {i,j} ;
            if(i == 0 || j == 0){
                dp[i][j] = 0 ;
            }else{
                dp[i][j] = dp[i-1][j] ;
                parent[i][j] = {i-1,j} ;

                if(dp[i][j-1] > dp[i][j]){
                    dp[i][j] = dp[i][j-1] ;
                    parent[i][j] = {i,j-1} ;
                }

                if(arr[i] == brr[j] && dp[i][j] < 1 + dp[i-1][j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                    parent[i][j]= {i-1,j-1} ;
                }
            }

           
        }
        cout << '\n' ;
        
    }


    cout << dp[n][m] ;
    lcs(n,m);
    cout <<  '\n' ;

    reverse(ans.begin(),ans.end());
    for(auto it : ans ) cout << it << ' ' ;
    
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}