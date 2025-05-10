#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n ;

    int oddCnt = 0 ;
    int evenCnt = 0 ;
    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        int num ; cin >> num ;

        if(num%2 == 0){
            //reset odd
            if(oddCnt > 0){
                ans+= oddCnt-1;
            }
            oddCnt = 0 ; 
            evenCnt++;
        }else{
            if(evenCnt > 0){
                ans+=evenCnt - 1;
            }
            evenCnt = 0;
            oddCnt++;
        }
    }

    if(evenCnt > 0){
        ans += evenCnt -1 ;
    }
    if(oddCnt > 0){
        ans += oddCnt - 1;
    }

    cout << ans << '\n' ;
    
}

int main(){
    int t ; cin >> t ; 
    while(t--){
        solve() ;
    }
}