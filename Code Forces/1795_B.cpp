#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int arr[52] ;
    memset(arr,0,sizeof(arr));
    int n , k ; cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        int l , r ; cin >> l >> r ;
        if(l <= k && k <= r){
                arr[l] += 1;
                arr[r+1] -= 1 ;
        }
    }

    for(int i = 1 ; i <= 51; i++){
        arr[i] += arr[i-1] ;
    }

    int val = arr[k] ;

    for(int i = 1 ; i < 52 ; i++){
        if(i==k) continue; 
        if(arr[i] == val){
            cout << "NO" << '\n' ;
            return ;
        }
    }

    cout << "YES" << '\n' ;
}
signed main(){
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}