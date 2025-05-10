#include <bits/stdc++.h>
using namespace std ;

void solve(){

    int n , k ; cin >> n >> k ;
    int arr[n] ;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    
    if(k > 1 || is_sorted(arr,arr+n)) cout << "YES" << '\n';
    else cout << "NO" << '\n' ;
}

signed main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0) ;

    int t ; cin >> t ; while(t--) 
    solve() ;
}