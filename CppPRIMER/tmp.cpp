#include<bits/stdc++.h>
using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

void dfs(vector<vector<int>> &minDis, vector<vector<int>> &ways, vector<vector<bool>> &visited, int i, int j, int M,int N, int dis, int tmpx){
        ways[i][j]++;
        minDis[i][j] = dis + 1;
        visited[i][j] = true;

        int tmpDis = 0;
        //上下左右
        if (i > 0){
            if(visited[i-1][j] && tmpx != 1){
                tmpDis = minDis[i-1][j];
                if(minDis[i][j] - 1 > tmpDis){
                    minDis[i][j] = tmpDis + 1;
                    ways[i][j] = 1;
                }
                else if(dis == tmpDis){
                    ways[i][j] += ways[i-1][j];
                }
            }
        }
        if (i < M-1){
            if(visited[i+1][j] && tmpx != 2){
                tmpDis = minDis[i+1][j];
                if(minDis[i][j] - 1 > tmpDis){
                    minDis[i][j] = tmpDis + 1;
                    ways[i][j] = 1;
                }
                else if(dis == tmpDis){
                    ways[i][j] += ways[i+1][j];
                }                
            }          
        }
        if (j > 0){
            if(visited[i][j-1] && tmpx != 3){
                tmpDis = minDis[i][j-1];
                if(minDis[i][j] - 1 > tmpDis){
                    minDis[i][j] = tmpDis + 1;
                    ways[i][j] = 1;
                }
                else if(dis == tmpDis){
                    ways[i][j] += ways[i][j-1];
                }                
            }           
        }
        if(j < N-1){
            if(visited[i][j+1] && tmpx != 4){
                tmpDis = minDis[i][j+1];
                if(minDis[i][j] - 1 > tmpDis){
                    minDis[i][j] = tmpDis + 1;
                    ways[i][j] = 1;
                }
                else if(dis == tmpDis){
                    ways[i][j] += ways[i][j+1];
                }                
            }           
        }

        int tmpway = ways[i][j];    
        if(i > 0 && !visited[i-1][j]) dfs(minDis, ways, visited, i-1, j, M, N, minDis[i][j], 2);
        if(i < M-1 && !visited[i+1][j]) dfs(minDis, ways, visited, i+1, j, M, N, minDis[i][j], 1);
        if(j > 0 && !visited[i][j-1]) dfs(minDis, ways, visited, i, j-1, M, N, minDis[i][j], 4);
        if(j < N-1 && !visited[i][j+1]) dfs(minDis, ways, visited, i, j+1, M, N, minDis[i][j], 3);
    
}
int main()
{
    int M = 5;
    int N = 5;

    int xS = 0;
    int yS = 1;
    int xE = 3;
    int yE = 3;

    int Lakes = 1;
    vector<vector<int>> minDis(M, vector<int>(N, 1000));
    vector<vector<int>> ways(M, vector<int>(N, 1));
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    for(int i = 0; i < Lakes; i++){
        int tmpX = 2;
        int tmpY = 2;
        minDis[tmpX][tmpX] = 100000;
        ways[tmpX][tmpX] = 0;
        visited[tmpX][tmpX] = true; 
    }
    
    dfs(minDis, ways, visited, xS, yS, M, N, -1, 0);
    
       
        
        
        
    
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    cout<<ways[xE][yE]<<" "<<minDis[xE][yE]<<endl;
    return 0;
}
