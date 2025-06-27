#include <bits/stdc++.h>
using namespace std ;
#define int long long

signed main(){
    int n , k , x ,a , b , c; 
    cin >> n >> k >> x >> a >> b >> c ;

    vector<int> v(n+1,0) ;
    v[1] = x ;

    int ans  = 0 ;
    int sum = v[1] ; 

    for(int i = 2 ; i <= n ; i++){
        v[i] = (a*v[i-1]+b) % c; 
        sum += v[i] ;
        if(i-k >= 0){
            sum -= v[i-k] ;
            ans = ans ^ sum ;
        }
    }
    cout << ans ;
}