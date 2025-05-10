#include <bits/stdc++.h>
using namespace std ; 
void solve(){
    int n ; cin >> n ;
    string arr ; cin >> arr ;
    int find = 1 ;
    int ans = 0 ;
    int prefix[n+1];
    prefix[0] = 0 ;
    for (int i = 1; i <= n ; i++)
    {
        prefix[i] = prefix[i-1] + (arr[i-1] - '0');
    }
    
    for (int i = 0; i < n-1; i++)
    {   
        // cout << arr[i] << ' ';
        if (arr[i]-'0' == find)
        {
            int sum = prefix[n] - prefix[i] ;
            if(sum == find*(n-i)) break ;
            ans++;
            find = 1 - find ;
        }
        
    }
    
    cout << ans << '\n' ;
    
}
int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0);cout.tie(0);
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}