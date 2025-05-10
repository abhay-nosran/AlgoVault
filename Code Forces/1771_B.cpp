#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n , m ; cin >> n >> m ;
    vector<int> last(n+1,n+1);

    for (int i = 0; i < m; i++)
    {
        int a , b ; cin >> a >> b ;
        int left = min(a,b) ;
        int right = max(a,b) ;
        last[left] = min(last[left],right) ;
    }
    
    for (int i = n-1; i >=0  ; i--)
    {
        last[i] = min(last[i+1],last[i]);
    }
    
    // for(auto it: last) cout << it << ' ' ;
    long long ans = 0 ;
    for (int i = 1; i <= n; i++)
    {
        ans += (last[i] - i) ;
    }
    
    cout << ans << '\n' ;
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}