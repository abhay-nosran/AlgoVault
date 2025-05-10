#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n , s , k ; cin >> n >> s >> k ;
    int maxDistance = min(n-1,1000);
    set<int> st ;
    for (int i = 0; i < k; i++)
    {   
        int element ; cin >> element ;
        st.insert(element) ;
    }
    int ans ;
    for (int i = 1; i <= maxDistance; i++)
    {
        int left = s-i , right = s+i;
        if(st.find(s) == st.end()){
            ans = 0 ;
            break ;
        }
        if((right <= n && st.find(right) == st.end()) || (left > 0 && st.find(left) == st.end())){
            ans = i ;
            break;
        }
        
    }

    cout << ans << '\n' ;
    
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0) ;
    int t ; cin >> t; while(t--)
    solve();
}