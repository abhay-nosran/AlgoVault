#include<bits/stdc++.h>
// #define int long long   --> this is is a trick to convert every int to long long
using namespace std;
int INF = 1e9 ;
vector<vector<int>> mainGraph ;
map<int,int> mpp ;
void solve(){
    int n ; cin >> n ;
    mainGraph.resize(n+1,vector<int>(n+1));
    for(int i = 1 ; i <= n ; i++){
        mpp[i] = 0 ;
        for(int j = 1 ; j <= n ; j++){
            cin >> mainGraph[i][j] ;
        }
    }

    vector<int> arr(n);
    vector<int> ans(n);
    for(int i = 0 ; i < n ;i++){
        cin >> arr[i] ;
    }
    for(int i = n-1 ;  i >= 0 ; i--){
        //add to graph 
        int sum = 0 ;
        int node = arr[i] ;
        mpp[node] = 1 ;
        for(int j = 1 ; j <= n ; j++){
            if(mpp[j] == 0) continue ;
            
            for(int k = 1 ; k <= n ; k++){
                if(mpp[k] == 0) continue ;
                mainGraph[j][k] = min(mainGraph[j][k] , mainGraph[j][node] + mainGraph[node][k]);
                
                sum += mainGraph[j][k] ;
            
            }
        }
        ans[i] = sum;
        cout << endl ;
    }

    for(auto it : ans) cout << it << ' ';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve() ;
}