#include <bits/stdc++.h>
using namespace std ;
void solve(){
    string s ; cin>>s ;
    s.pop_back();
    s.pop_back();

    s = s + "i" ;
    cout <<s << '\n' ;
}
int main(){
    int t ; cin >>t ;
    while (t--)
    {
        solve() ;
    }
    
}