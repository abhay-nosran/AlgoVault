#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;

    char element = s[0] ;
    string ans = "" ;
    for (int i = 1; i < n; i++)
    {
        if(s[i] == element){
            ans += s[i] ;
            if(i+1 < n) {element = s[i+1] ;i++;}
        }
    }
    
    cout << ans << '\n' ;
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}