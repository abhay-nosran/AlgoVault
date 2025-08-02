#include <bits/stdc++.h>
using namespace std;
int arr[101] ;
int n ;
void solve(){
    cin >> n ; 

    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;

    set<int> st ; 
    st.insert(0) ;

    for(int i = 0 ; i < n ; i++){
        set<int> temp ; 

        for(auto it : st){
            temp.insert(it + arr[i]) ; 
        }

        for(auto it : temp){
            st.insert(it) ;
        }
    }

    st.erase(0) ;
    cout << st.size() << '\n'; 
    for(auto it : st){
        cout << it << ' ' ;
    }
}
void solve2(){
    bitset<100001> temp ;

    int n ; cin >> n ;
    temp[0] = 1 ;
    for(int i = 0 ; i < n ;i++){
        int x ; cin >> x ;
        temp |= temp << x ;
    }

    vector<int> ans ;
    for(int i = 1 ; i < 100001 ; i++){
        if(temp[i]) ans.push_back(i) ;
    }
    cout << ans.size() << '\n' ;
    for(auto it : ans) cout << it << ' ' ;
}
signed main(){
    //int t; cin >> t ; while(t--)
    // solve();
    solve2() ;
}