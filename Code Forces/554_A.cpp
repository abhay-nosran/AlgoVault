#include <bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n == 0 || n == 1) return 1 ;
    return n*fact(n-1) ;
}
void solve(){
    string s ; cin >> s ;
    int n = s.size() ;
    int arr[26] ;
    memset(arr,0,sizeof(arr)) ;

    for(int i = 0 ; i < n ; i++){
        arr[s[i] - 'a']++;
    }

    int val = fact(n+1) ;
    cout << val << ' ';

    for (int i = 0; i < 26; i++)
    {
        val = val/fact(arr[i]) ;
    }

    cout << val << ' ';
    int ans = 0 ;
    for (char i = 'a'; i <= 'z' ; i++)
    {   
        if(arr[i-'a'] > 0){
            ans += (val/(arr[i-'a']+1)) ;
        }else{
            ans += val ;
        }
        
    }
    
    cout << ans ;
}

int main(){
    // int t ; cin >> t; while(t--)
    solve();
}