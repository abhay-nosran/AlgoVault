#include <iostream>
#include <vector> 


using namespace std;

int main(){
    int n , t ; cin >> n >> t ;
    vector<int> v(n) ;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] ; 
    }

    int l = 0 , r = 0 , sum = 0 , max_len = 0 ;

    while (r < n)
    {
        sum += v[r] ;

        if(sum > t ){
            sum -= v[l] ;
            l++ ;
        }

        if(sum <= t) max_len = max(max_len,r-l+1) ;
        r++ ;
    }
    
    cout << max_len << endl ;
} 