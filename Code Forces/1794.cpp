#include <bits/stdc++.h>
using namespace std;

bool comp(string a , string b){
    if(a.size() < b.size()) return 1 ;
    return 0 ;
}
void solve(){
    int n ; cin >> n;
    vector<string> v ;

    for (int i = 0; i < (2*n-2); i++)
    {
        string s ; cin >> s;
        v.push_back(s) ;
    }

    sort(v.begin(),v.end(),comp);
    // for(auto it : v) cout << it << ' ' ;
    bool flag = 1 ;
    for (int i = 0; i < 2*n - 2; i=i+2)
    {
       string a = v[i] ;
       string b = v[i+1] ;
       reverse(b.begin(),b.end()) ;
       if(a != b){
        flag = 0 ;
        break ;
       }
    }

    if(flag) cout << "YES\n"  ;
    else cout << "NO\n" ;
    
    
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}