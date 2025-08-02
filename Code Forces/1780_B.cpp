#include <bits/stdc++.h>
using namespace std ;
#define int long long

int gcd(int a , int b){

    if(a == 0) return b ;
    return gcd(b%a,a) ;

}
void solve(){
    int n ; cin >> n ;
    int arr[n+1]; 
    arr[0] = 0 ;

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i] ;
        arr[i] += arr[i-1] ;
    }

    int ans = INT_MIN ;
    for(int i = 1 ; i < n ; i++){

        int a = arr[i] - arr[0] ;
        int b = arr[n] - arr[i] ;

        ans = max(ans,gcd(a,b)) ;
    }

    cout << ans << '\n' ;
}
signed main(){
    int t ; cin >> t ;
    while(t--) solve() ;
}