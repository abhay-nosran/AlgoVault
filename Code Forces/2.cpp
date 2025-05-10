#include <bits/stdc++.h>
#include <stack>
using namespace std ;
void solve(){
    map<int,int> freq ;

    int n ; cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int element ; cin >> element ;
        freq[element]++;
    }

    vector<int> base ;
    vector<int> sides ;
    
    for(auto it : freq){
        if(it.second >= 2){
            sides.push_back(it.first);
            int temp = (it.second)-2 ;
            while(temp--){
                base.push_back(it.first);
            }
        }else{
            base.push_back(it.first);
        }
    }

    // for(auto it : base) cout << it << ' ';
    // cout << '\n';
    // for(auto it : sides) cout << it << ' ';
    // cout << '\n';

    if(sides.size() == 0){
        cout << -1 << '\n' ;
        return ;
    }

    if(sides.size() > 1){
        int a = *sides.begin();
        int b = *sides.rbegin();

        cout << a << ' ' << a << ' ' << b << ' ' << b << '\n' ;
        return ;
    }

    sort(base.begin(),base.end());

    int mainSide = sides[0] ;

    for(int i = 1 ; i < base.size() ; i++){
        int diff = (base[i] - base[i-1])/2;
        if(mainSide > diff) {
            cout << mainSide << ' ' << mainSide << ' ' << base[i-1] << ' '<< base[i] << '\n';
            return ;
        }
    }
    // cout << mainSide << ' ' << diff << '\n' ;
        cout << -1 << '\n' ;

}
int main(){
    int t ; cin >> t ;

    while(t--){
        solve() ;
    }
}