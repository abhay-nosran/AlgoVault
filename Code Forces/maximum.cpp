#include <bits/stdc++.h>
using namespace std;
void solve(){
   
   int a , b , c ; cin >> a >> b >> c ;
   int ans = c-(a&b) ;
   
   if(((a|ans)&(b|ans))==c)  cout << ans << '\n' ;
   else cout << -1 ;
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}

