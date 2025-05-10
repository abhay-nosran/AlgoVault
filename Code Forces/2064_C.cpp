// #include <bits/stdc++.h>
// using namespace std ;
// vector<int> arr ;
// vector<vector<int>> dp ;
// int help(int i , int j){
//     if(i > j) return 0 ;
//     int gain = 0 ;

//     if(dp[i][j] != -1) return dp[i][j] ;
//     for(int x = i ; x <= j ; x++){

//         int left, right ; 
//         if(arr[x] < 0){
//             left = i ;
//             right = x - 1;
//         }else{
//             left = x+1 ;
//             right = j ;
//         }
//         gain = max(gain,help(left,right)+abs(arr[x])); 
//     }

//     return dp[i][j] = gain ;
// }
// void solve(){
//    int n ; cin >> n ;
//     arr.resize(n+1);
//     dp.resize(n+1,vector<int>(n+1,-1));

//     for(int i = 1 ; i <= n  ;i++){
//         cin >> arr[i] ;
//     }
//     int ans = help(1,n);
//     cout << ans << '\n' ;
// }

// signed main(){
//     int t ; cin >> t ;
//     while (t--) 
//     {
//         solve() ;
//         arr.clear() ;
//         dp.clear() ;
//     }
    
// }

#include <bits/stdc++.h> 
using namespace std ; 

void solve(){
    int n ; cin >> n ;

    vector<int> arr(n+1);
    vector<int> negativePrefix(n+1,0);
    vector<int> positivePrefix(n+1,0);
    vector<pair<int,int>> container;

    for (int i = 1 ; i <= n; i++){
        cin >> arr[i] ;
        negativePrefix[i] = abs(arr[i]) + negativePrefix[i-1] ;
    }

    positivePrefix[n] = arr[n] ;

    for(int i = n-1 ; i >= 1 ;i--){
        positivePrefix[i] = abs(arr[i]) + positivePrefix[i+1] ;
    }

    for(int i  = 1 ; i  <= n ; i++){
        if(arr[i] < 0){
            container.push_back({negativePrefix[i],i}) ;
        }else{
            container.push_back({positivePrefix[i],i}) ;
        }
    }
    

    sort(container.rbegin(),container.rend());

    // for(auto it : container){
    //     cout << it.first << ' ' << it.second << '\n' ;
    // }


    int i = 1 , j = n ;
    int gain = 0 ;

    for (int x = 0; x < n ; x++)
    {
        int node = container[x].second ;

        if(node >= i && node <= j){
            // cout << node << '\n' ;
            gain += abs(arr[node]) ;
            if(arr[node] < 0){
                j = node - 1;
            }else{
                i = node + 1;
            }
        }
    }
    cout << gain << '\n' ;
    
}
int main(){
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}