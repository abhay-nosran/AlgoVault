#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;
    int arr[n+1] ;

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ;
        arr[i]++ ;
    }

    for(int i = 2 ;i<=n ;i++ ){
        if(arr[i]%arr[i-1]==0){
            arr[i]++ ;
        }
    }

    for(int i = 1 ; i <= n ; i++) cout << arr[i] << ' ' ;
    cout << '\n' ;
}
signed main(){
    int t; cin >> t ; while(t--)
    solve();
}