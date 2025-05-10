#include <bits/stdc++.h>
#define int long long 
using namespace std;

int getPower(int x){
    int k = ceil(log2(x));
    
    return binPow(2,k) ;
}
void solve(){
    int n ; cin >> n ;
    int arr[n] ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    vector<pair<int,int>> ans ;
    for (int i = 0; i < n; i++)
    {
        int change = getPower(arr[i]) - arr[i] ;
        if(change == 0) continue; 
        ans.push_back({i,change}) ;
    }
    
    cout << ans.size() << '\n' ;
    for(auto it : ans) cout << it.first << ' ' << it.second << '\n' ;


}

signed main(){
    int t ; cin >> t; while(t--)
    solve();
}