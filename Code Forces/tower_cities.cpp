#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int num_cities , num_towers ;
    cin >> num_cities >> num_towers ;
    vector<int> cites(num_cities);
    vector<int> towers(num_towers) ;
    for (int i = 0; i < num_cities; i++)
    {
        int element ; cin >> element ;
        cites[i] = element ;
    }
    for (int i = 0; i < num_towers; i++)
    {
        int element ; cin >> element ;
        towers[i] = element ;
    }

    vector<int> nearest_tower(num_cities);
    for (int i = 0; i < num_cities; i++)
    {   
        int nearest = INT_MAX;
        for (int j = 0; j < num_towers; j++)
        {
            nearest = min(nearest , abs(cites[i] - towers[j]));
        }
        
        nearest_tower[i] = nearest ;
    }
    
    int ans = *max_element(nearest_tower.begin(),nearest_tower.end()) ;
    
    cout << ans << endl ;
}