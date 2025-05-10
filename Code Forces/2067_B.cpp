#include<bits/stdc++.h>
using namespace std ;
void solve(){
    int n ; cin >> n ;
    vector<int> freq(1002,0);
    for (int i = 0; i < n; i++)
    {
        int x ; cin >> x ;
        freq[x]++;
    }

    string ans = "Yes" ;
    for (int i = 1; i <= 1001; i++)
    {
        if(freq[i] != 0 && freq[i] < 2){ 
            // cout << i << ' ';
            ans = "No" ;
            break ;
        }
        else{
            int number =0;
            if(freq[i] > 0) number = freq[i] - 2 ;
            freq[i+1] = freq[i+1] + number ;
        }
    }
    
    cout << ans << '\n' ;

    
    
}
int main(){
    int t ; cin >> t;
    while (t--)
    {
        solve();
    }
    
}