#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ; 
    int lengths[n] ;

    for(int i = 0 ; i < n ; i++){
        cin >> lengths[i] ;
    }

    // get median 
    sort(lengths,lengths+n) ;
    int median = lengths[n/2] ;

    long long cost = 0LL ;

    for(int i = 0 ; i < n ; i++){
        cost += abs(lengths[i]-median) ;
    }

    cout << cost ; 
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}