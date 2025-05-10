#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n ;
    string s = "";

    for(int i = 0 ; i < n-2  ;i++){
        string a ; cin >> a ;
        s+= a;
    }
    int res = s.find("101") ;

    if (res == string::npos)
          cout << "YES\n";
      else
          cout << "NO\n";
}
int main(){
    int t ; cin >>t  ; 
    while (t--)
    {
        solve() ;
    }
    
}