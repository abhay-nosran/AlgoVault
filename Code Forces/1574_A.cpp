// #include <bits/stdc++.h>
// using namespace std;
// int maxDepth ;
// int n ;
// void rec(int level , int depth , string & s ,vector<string> & ans){
//     // cout << level << ' ' << depth <<'\n' ;
//     if(ans.size() == 3) return ;
//     if(level == 2*n){
//         if(depth == 0){
//             ans.push_back(s) ;
//         }
//         return ;
//     }

//     // (
//     if(depth < maxDepth){
//         depth++;
//         s +="(" ;
//         rec(level+1,depth,s,ans);
//         s.pop_back();
//         depth--;
//     }
    

//     if(depth > 0){
//         depth--;
//         s+=")";
//         rec(level+1,depth,s,ans);
//         s.pop_back() ;
//         depth++;
//     }
// }
// void solve(){
//     cin >> n ;
//     string s = "";
//     maxDepth = n ;
//     vector<string> ans ;
//     rec(0,0,s,ans);
//     for(auto it : ans){
//         cout << it << '\n' ;
//     }
    
// }

// int main(){
//     int t ; cin >> t; while(t--)
//     solve();
// }


#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ; 
    vector<string> ans ;
    string s ; 

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            s +="(";
        }
        for (int j = 0; j < i; j++)
        {
            s +=")";
        }
        
        for (int j = 0 ; j < n-i ; j++)
        {
            s += "()";
        }
        
        ans.push_back(s);
        s= "";

    }

    for(auto it : ans) cout << it << '\n' ;
    
}

int main(){
    int t ; cin >> t; while(t--)
    solve();
}