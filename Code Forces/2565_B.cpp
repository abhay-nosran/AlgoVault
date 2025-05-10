#include <bits/stdc++.h>
using namespace std ;
void solve(){
    string s ; cin >>s ;
    bool found = 0 ;
    int n = s.size() ;

    for (int i = 1; i < n; i++)
    {
        if(s[i-1] == s[i]){
            found = 1 ;
            break ;
        }
    }

    if(found) cout << 1 << '\n'; 
    else cout << n << '\n' ;
    
}
int main(){
    int t ; cin >>t ;
    while (t--)
    {
        solve() ;
    }
    
}