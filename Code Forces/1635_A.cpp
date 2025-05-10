#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;
    int ans = 0 ;

    for (int i = 0; i < n; i++)
    {
        int element ; cin >> element ;
        ans |= element ;
    }

    cout << ans << '\n' ;
    
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}