#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> kingdom, int i, int j,int n, int m,  vector<vector<bool>> visited, int nums, int &ans){
    visited[i][j] = true;
    if (kingdom[i][j] == 'T'){
        ans = min(ans, nums);
        return;
    }
    vector<pair<int,int>> ways = {{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};
    for (pair<int, int> way: ways )
    {
        int dx = way.first;
        int dy = way.second;
        int nx = i + dx;
        int ny = j + dy;
        int bx = i + dx/2;
        int by = j + dy/2;
        if (nx >= 0 && nx <= n-1 && ny <= m-1 && ny >= 0)
        {
            if (!visited[nx][ny] && kingdom[bx][by]!= '0')//可以走
            {   
                dfs(kingdom, i, j,n, m, visited, nums+1, ans);
            }
        }
    }
   
    visited[i][j] = false;
    
    
}

int main(){
    int T=0;
    cin>>T;
    for(int t = 0; t < T; t++){
        int n;
        int m;
        cin>>n;
        cin>>m;
        vector<vector<char>> kingdom(n, vector<char>(m));
        int o_i = 0;
        int o_j = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char tmp = 'a';
                cin>>tmp;
                kingdom[i][j] = tmp;
                if(tmp == 'K'){
                    o_i = i;
                    o_j = j;    
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = INT_MAX;
        dfs(kingdom, o_i, o_j,n, m, visited, 0, ans);
        if(ans!=INT_MAX){
            cout<<ans;}
        else cout<<-1;
        
              
    }

    return 0;
}