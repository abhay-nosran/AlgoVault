#include <bits/stdc++.h>
using namespace std ;
using state = pair<int,int> ;
#define F first 
#define S second 


void solve(){
        int a , b , xKing , yKing , xQueen , yQueen ; 
        cin >> a >> b >> xKing >> yKing >> xQueen >> yQueen ;

        state king = {xKing,yKing};
        state queen = {xQueen,yQueen} ;
        set<state> ans ;
         
        int dx[8] = {a,a,-a,-a,b,b,-b,-b};
        int dy[8] = {b,-b,b,-b,a,-a,a,-a};

        int solutions = 0 ;

        for (int i = 0; i < 8; i++)
        {   
            state knight ;
            knight.F =  king.F - dx[i] ;
            knight.S = king.S - dy[i] ;
            for (int j = 0; j < 8; j++)
            {
                state tempQueen ;
                tempQueen.F = dx[j] + knight.F ;
                tempQueen.S = dy[j] + knight.S ;

                if(tempQueen == queen){
                    ans.insert(knight);
                    solutions++;
                }
            }
            
        }

        cout << ans.size() << '\n' ;
        

}

int main(){
    int t ; cin >>t ;
    while (t--)
    {
        solve() ;
    }
    
}