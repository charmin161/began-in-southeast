#include<bits/stdc++.h>
using namespace std;

void dfs(string &s, string &tmpS,string & tmpi, vector<string> &ans, int i, int j){
    if((j > 3 )|| (!tmpi.empty() && stoi(tmpi) > 255)) return;
    if(i == s.size()){
        if(j != 3) return;
        ans.push_back(tmpS + tmpi);
        return;
    }
    if(tmpi.empty()){
        
        tmpi.push_back(s[i]);
        dfs(s, tmpS, tmpi, ans, i+1, j);
    }
    else if(tmpi == "0"){
        tmpS += ("." + tmpi);
        tmpi = "";
        dfs(s, tmpS, tmpi, ans, i, j+1);
    }
    else{
        tmpi.push_back(s[i]);
        dfs(s, tmpS, tmpi, ans, i+1, j);
        tmpi.pop_back();
        tmpS += ("."+tmpi);
        tmpi = "";
        dfs(s, tmpS, tmpi, ans, i, j+1);
    }
    

    
}
vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    vector<string> ans;
    if(n < 4 || n > 12) return ans;
    string tmpS;
    string tmpi; 
    dfs(s,tmpS, tmpi, ans, 0, 0);
    return ans;
}

int main(){
    vector<string> ans = restoreIpAddresses("25525511135");
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}