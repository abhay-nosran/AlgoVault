#include <bits/stdc++.h>
using namespace std ;
using ii =  pair<int,int> ;
#define MP make_pair  
int main(){
    int n , m ; cin >> n >> m ;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> monstersDistance(n,vector<int>(m,1e9));
    vector<vector<int>> personDistance(n,vector<int>(m,1e9));
    vector<vector<ii>> parent(n,vector<ii>(m));

    queue<ii> monstersQueue ; //{x,y}
    queue<ii> personQueue ; // {x,y}
    queue<ii> boundaries ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j] ;
            if(grid[i][j] == 'M'){
                 monstersQueue.push(MP(i,j));
                 monstersDistance[i][j] = 0 ;
            }
            else if(grid[i][j] == 'A'){
                personDistance[i][j] = 0 ;
                personQueue.push(MP(i,j)) ;
                parent[i][j] = MP(i,j) ;
            }

            if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] != '#'){
                boundaries.push(MP(i,j)) ;
            }
        }
    }

    int dx[4] = {-1,0,+1,0} ;
    int dy[4] = {0,1,0,-1} ;

    while (!monstersQueue.empty())
    {
        ii node = monstersQueue.front() ;
        monstersQueue.pop() ;

        for(int i = 0 ; i < 4 ; i++){
            int nrow = node.first + dx[i] ;
            int ncol = node.second + dy[i] ;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && monstersDistance[nrow][ncol] > monstersDistance[node.first][node.second] + 1 ){
                monstersDistance[nrow][ncol] = monstersDistance[node.first][node.second] + 1 ;
                monstersQueue.push({nrow,ncol}) ;
            }
        }
    }
    while (!personQueue.empty())
    {
        ii node = personQueue.front() ;
        personQueue.pop() ;

        for(int i = 0 ; i < 4 ; i++){
            int nrow = node.first + dx[i] ;
            int ncol = node.second + dy[i] ;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && personDistance[nrow][ncol] > personDistance[node.first][node.second] + 1 ){
                personDistance[nrow][ncol] = personDistance[node.first][node.second] + 1 ;
                parent[nrow][ncol] = node ;
                personQueue.push({nrow,ncol}) ;
            }
        }
    }

    bool isPossible = 0 ;
    vector<char> ans ;
    while (!boundaries.empty())
    {
        ii node = boundaries.front() ;
        boundaries.pop() ;

        if(personDistance[node.first][node.second] < monstersDistance[node.first][node.second]){
            isPossible = 1 ;
            ii temp = node ;
            
            while (temp != parent[temp.first][temp.second])
            {
                
                for(int i = 0 ; i < 4 ; i++){
                    int nrow = temp.first + dx[i] ;
                    int ncol = temp.second + dy[i] ;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && parent[temp.first][temp.second] == MP(nrow,ncol)){
                        if(dx[i] == 1){
                            ans.push_back('U') ;
                        }
                        if(dx[i] == -1){
                            ans.push_back('D') ;
                        }
                        if(dy[i] == 1){
                            ans.push_back('L') ;
                        }
                        if(dy[i] == -1){
                            ans.push_back('R') ;
                        }
                    }
                }

                temp = parent[temp.first][temp.second] ;
            }
            for(int i = 0 ; i < 4 ; i++){
                    int nrow = temp.first + dx[i] ;
                    int ncol = temp.second + dy[i] ;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && parent[temp.first][temp.second] == MP(nrow,ncol)){
                        if(dx[i] == 1){
                            ans.push_back('U') ;
                        }
                        if(dx[i] == -1){
                            ans.push_back('D') ;
                        }
                        if(dy[i] == 1){
                            ans.push_back('L') ;
                        }
                        if(dy[i] == -1){
                            ans.push_back('R') ;
                        }
                    }
                }
            reverse(ans.begin(),ans.end()) ;
            break ;
        }
    }
    
    if(isPossible){
        cout << "YES\n" ;
        cout << ans.size() << '\n' ;
        for(auto it : ans){
            cout << it << ' ' ;
        }
    }else{
        cout << "NO\n" ;
    }
    



}