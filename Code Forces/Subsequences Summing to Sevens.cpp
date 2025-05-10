#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int input_num ;cin >> input_num ;
    vector<int> ids(input_num) ;
    for (int i = 0; i < input_num; i++)
    {   
        int element ; cin >> element ;
        ids[i] = element ;
    }

    unordered_map<int,int> mpp ;
    int maxi = 0 ;
    int ans = 0 ;
    for (int  i = 0; i < input_num; i++)
    {
        int element = ids[i] ;
        int num = 7 - (element%7) ;
        for(int j = num ; j <= maxi ; j+=7)
        {
            if (mpp.count(j) > 0 )
            {
              int len = i - mpp[j]  ;
              ans = max(ans,len) ;
            } 
        }
        maxi += element ;
        mpp[maxi] = i ;
    }
    
    cout << ans << endl ;
    return 0 ; 
    
}