#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
    int n , q ; cin >> n >> q ;
    
    vector<int> v(n+1) ;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] ;
    }

    vector<long long> freq(n+1,0) ;
    for (int i = 0; i < q; i++)
    {
        int l , r ; 
        cin >> l >> r ;
        freq[l]++ ;
        if(r+1 <= n) freq[r+1]-- ;
    }

    for (int i = 1; i <= n; i++)
    {
        freq[i] = freq[i-1] + freq[i] ;
    }
    
    sort(v.begin()+1,v.end());
    sort(freq.begin()+1,freq.end());

    unsigned long long  sum = 0 ;
    for (int i = 1; i <= n; i++)
    {
        sum += v[i] * freq[i] ;
    }
    
    cout << sum << endl ;

}