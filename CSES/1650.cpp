#include <bits/stdc++.h>
using namespace std ;
int arr[200100];
int prefix[200100];
signed main(){
    int n , q ; cin >> n >> q ;
    prefix[0] = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ; 
        prefix[i] = prefix[i-1] ^ arr[i] ;
    }

    while (q--)
    {
        int l , r ; cin >> l >> r ;

        int ans = prefix[r]^prefix[l-1] ;
        cout << ans << '\n' ;
    }
    
}