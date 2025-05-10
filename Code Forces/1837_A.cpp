#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int x , k ; cin >> x >> k ;

    if(x%k != 0){
        cout << 1 << '\n' ;
        cout << x << '\n' ;
    }else{
        cout << 2 << '\n' ;
        cout << 1 << ' ' <<x-1 << '\n' ;
    }
}

int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0);
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}

 