#include <bits/stdc++.h>
using namespace std ;
void solve(){
    int t1 , t2 , t3 , t4 ; 
    cin >> t1 >> t2 >> t3 >> t4 ;

    if(t1 == 0){ cout << 1 << '\n' ; return ;}
    int jokes = 0 ;
    
    jokes = t1 + 2*min(t2,t3) + min(t1+1,abs(t2-t3)+t4) ;
    
    cout << jokes << '\n' ;
}
signed main(){
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}