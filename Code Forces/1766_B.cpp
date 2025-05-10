#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;

    if(n == 2 || n == 1){
        cout << "NO\n" ;
        return ;
    }

    set<string> st;
    string prev = "";
    prev += s[0];
    prev+=s[1] ;
    for (int i = 2; i < n-1; i++)
    {   
        st.insert(prev) ;
        string a = "" ;
        a+= s[i] ;
        a+=s[i+1] ;
        // cout << a << ' ';
        if(st.find(a) != st.end()){
            cout << "YES\n"  ;
            return ;
        }
        prev.erase(prev.begin());
        prev += s[i];
        
    }

    cout << "NO\n" ;
    
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}