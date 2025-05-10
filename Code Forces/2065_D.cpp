#include <bits/stdc++.h>
using namespace std ;
#define int long long
bool comp(vector<int> &a , vector<int> &b){
    int n = a.size() ;
    for (int i = n-1; i >= 0; i--)
    {
        if(b[i] > a[i]) return false;
        else if(b[i] < a[i]) return true ;
    }

    return false ;
    
}

void solve(){
    int n , m ; cin >> n >> m;
    vector<vector<int>> prefixSum(n,vector<int>(m+1,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int val ; cin >> val ;
            prefixSum[i][j] = prefixSum[i][j-1] + val ;
        }
        
    }
    

    sort(prefixSum.begin(),prefixSum.end(),comp);

    int last = 0 ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            prefixSum[i][j] += last;
        }
        last = prefixSum[i][m] ;
    }
    
    
    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += prefixSum[i][j] ;
        }
        
    }
    cout << ans << '\n' ;
    
    
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    
}