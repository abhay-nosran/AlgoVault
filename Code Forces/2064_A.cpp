#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n; 
    string s ; cin >> s ;
    bool prevOne = 0 ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
            prevOne = 1 ;
        }else{
            if(prevOne){
                ans += 2 ;
                prevOne = 0 ;
            }
        }
    }
    if(prevOne){
        ans++ ;
    }
    cout << ans << '\n' ;
}

signed main(){
    int t ; cin >> t ;
    while (t--) 
    {
        solve() ;
    }
    
}