#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n ; 
vector<vector<int>> projects ;
bool comp(vector<int> a , vector<int> b){

    if(a[1] < b[1]) return true ;
    return false ;
}
void solve(){
    cin >> n ;
    for(int i = 0 ;i < n ; i++){
        int a , b, r ; cin >> a>> b>>r ;
        projects.push_back({a,b,r}) ;
    }

    sort(projects.begin(),projects.end(),comp) ;
    map<int,int> maxTill ;

    int maxi = 0 ;

    for(auto it : projects){

        int i = it[1] ;
        int value = -1e9 ;
        int k = it[0] ;
        auto lb = maxTill.lower_bound(k);
        int ans ;
        if(lb == maxTill.begin()){
            ans = it[2]; 
        }else{
            lb--;
            ans = it[2] + lb->second; 
        }
        value = max(value,ans);
        

        maxi = max(value,maxi) ;
        maxTill[i] = maxi ;
        
        // cout << i << maxTill[i] << '\n' ;
    }

    cout << maxi  ;
    

}
signed main(){
    //int t; cin >> t ; while(t--)
    solve();
}
