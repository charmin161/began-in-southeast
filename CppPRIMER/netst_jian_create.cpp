#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &ans, int n ,int k,int x,int i, 
            int curSum,vector<int> tmp, bool &founded)
{
    if(n == 0){
        //cout<<tmp[0]<<endl;
        if(curSum == x){
            ans = tmp;
            founded = true;
        } 
        return;
    }
    for(int j = i; j <= k; j++){
        if(j + curSum <= x){
            
            tmp.push_back(j);
            dfs(ans, n-1, k, x, j+1, curSum+j,tmp, founded);
            if(founded) return;
            tmp.pop_back();
        }
        else{
            return;
        }
    }
}
int main(){
    int n = 4;
    int k = 6;
    int x = 15;
    cin>>n;
    cin>>k;
    cin>>x;
    if(k < n){
        cout<<-1<<endl;
        return 0;
    }
    if((2*k-n+1)*n/2 < x){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> ans;
    vector<int> tmp;
    int cursum = 0;
    bool founded = false;
    dfs(ans, n, k, x, 1, cursum, tmp, founded);
    
    if(!founded){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

