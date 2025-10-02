#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;

    pair<int,int> arr[n] ; // {duration,deadline}

    for(int i = 0 ; i < n ; i++){
        int a , b ; cin >> a >> b ;

        arr[i] = {a,b} ;
    }

    sort(arr,arr+n) ;

    long long T = 0 ; 
    long long ans = 0 ; 

    for(int i = 0 ; i < n ; i++){
        T+= 1LL*(arr[i].first) ;
        ans += 1LL*(arr[i].second )- T;
    }

    cout << ans ; 
}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}   