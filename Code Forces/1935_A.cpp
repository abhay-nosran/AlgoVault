#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    int length = s.size();
    int i = 0 , j = length - 1 ;
    bool leftGreater = 0 ;

    while (i < j)
    {
        if(s[i] == s[j]){
            i++;j--;
            continue;
        }

        leftGreater = s[i] > s[j] ? 1 : 0 ;
        break; 
    }

    // if leftGreater is 1 need to reverse 
    string ans ;
    if(leftGreater){
        ans = s ;
        reverse(ans.begin(),ans.end()) ;
        ans += s ;
        
    }else{
        ans = s ;
    }
    
    cout << ans << '\n' ;
}

int main(){
    int t ; cin >> t ;
    while (t--)
    {
        solve();
    }
    
}