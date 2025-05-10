#include <bits/stdc++.h>
using namespace std ;



void solve(){
    int n , m , k ; 
    cin >> n >> m >> k ;
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];

    sort(a.rbegin(),a.rend());
    int minimum = *min_element(b.begin(),b.end());

    for(int i = 0 ; i < n ; i++){
        if(a[i] > minimum && k > 0){
            a[i] = (a[i] & minimum) ;
            k--;
        }

    }

    int sum = 0 ;
    for(auto it : a) sum += it ;

    cout << sum <<'\n' ;

}
int main(){
    int t ; cin >> t ;
    while(t--){
        solve();
    }
}