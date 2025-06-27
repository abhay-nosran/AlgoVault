#include<bits/stdc++.h>
// #define int long long   --> this is is a trick to convert every int to long long
using namespace std;
#define int long long
int n ;
int parent[200011] ;
int depth[200011] ;
vector<int> graph[200011];
int cnt ;
int diameter ;
void dfs(int node , int par , int d){
    parent[node] = par ;
    depth[node] = d ;
    if(d == (diameter/2)) cnt++ ;
    for(auto neigh : graph[node]){
        if(neigh != par){
            dfs(neigh,node,d+1);
        }
    }
}

int allPairSum(vector<int> nums){
    if(nums.size() == 0) return 1 ;
    int sum = 0 ;
    int squareSum = 0 ;
    for(int i = 0  ; i < nums.size() ; i++ ){
        sum += nums[i] ;
        squareSum += nums[i]*nums[i] ;
    }

    int ans = (sum*sum - squareSum)/2 ;
    return ans ;
}
int oneCenter(int center){

    vector<int> cntArray ;
    for(auto neigh : graph[center]){
        cnt = 0 ;
        dfs(neigh,center,1) ;
        cntArray.push_back(cnt) ;
    }
    return allPairSum(cntArray);
}
int twoCenter(int center1 , int center2){
    int ans = 1 ;
    cnt = 0 ;
    dfs(center1,center2,0) ;
    ans *= cnt ;
    cnt = 0 ;
    dfs(center2,center1,0) ;
    ans *= cnt ;
    return ans ;
}
void solve(){
    cin >> n ;
    // if(n == 1){
    //     cout << "1" ;
    //     return ;
    // }
    for(int i = 1 ; i < n ; i++){
        int u , v ; cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ; 
    }

    // center finding
    int random = 1 ;
    dfs(random,0,0);
    int b = 1 ;
    for(int i = 1 ; i <= n ; i++){
        if(depth[b] < depth[i]){
            b = i ;
        }
    }

    dfs(b,0,0) ;
    int c = 1 ;
    for(int i = 1 ; i <= n ; i++){
        if(depth[c] < depth[i]){
            c = i ;
        }
    }

    diameter = depth[c] ;
    int back_steps = diameter/2 ;
    int center = c;

    for(int i = 0 ; i < back_steps ; i++){
        center= parent[center] ;
    }

    if(diameter%2 == 0){//1 center
        // cout << "Center : "<< center << '\n' ;
        cout << oneCenter(center) ;
    }else{// 2 center
        int center2 = parent[center] ;
        // cout << "Centers : " << center << ' ' << center2 << '\n' ;
        cout << twoCenter(center,center2) ;
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    solve() ;
}