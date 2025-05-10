#include <bits/stdc++.h> 
using namespace std ;

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;

    
    int numDistinct = 0 ;
    int maxDistinct = 0 ;
    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        // start with i 
        vector<int> freq(10,0) ;
        numDistinct = 0 ;
        maxDistinct = 0 ;
        for (int j = i; j < i+100 && j < n; j++)
        {
            int digit = s[j]-'0' ;
            // cout << i << ' ' << j << '\n' ;
            // string from i to j
            if(freq[digit] == 0) numDistinct++;
            freq[digit]++;
            maxDistinct = max(maxDistinct,freq[digit]);

            if(numDistinct >= maxDistinct){
                ans++ ;
            }

        }

        
    }

    cout << ans << '\n';
    
}

signed main(){
    int t ; cin >> t ; 
    while (t--) 
    {
        solve() ;
    }
    
}