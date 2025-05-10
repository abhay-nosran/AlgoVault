#include <bits/stdc++.h>
#include <stack>
using namespace std ;
void solve(){
    int n ; cin >> n ;
    int oddCnt = 0 ;
    int evenCnt = 0 ;

    for(int i = 0 ; i < n ; i++){
        int element ; cin >> element ;
        if(element%2 == 1) oddCnt++;
        else evenCnt++;
    }
    int ans = 0 ;
    if(evenCnt != 0){
        ans++;
    }else{
        ans--;
    }
    ans += oddCnt ;

    cout << ans << '\n' ;
    
}
int main(){
    int t ; cin >> t ;

    while(t--){
        solve() ;
    }
}