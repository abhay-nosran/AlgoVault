#include <bits/stdc++.h> 
using namespace std ; 
void solve(){
    int maxi , mini ; cin >> maxi >> mini ;

    int nth = maxi - 1 ;
    int ans = abs(maxi-mini) + abs(nth - mini) + 1;

    cout << ans << '\n' ;
    for(int i = maxi ; i >= mini ; i--){
        cout << i << ' ' ;
    }
    for(int j = mini + 1 ; j <= nth ; j++){
        cout << j << ' '  ;     
    }

    cout << '\n' ;
}
signed main(){
    int t ; cin >> t ;
    while(t--) solve() ;
}