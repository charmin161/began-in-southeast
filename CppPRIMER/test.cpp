//
#include<bits/stdc++.h>
using namespace std;
string minStr(string s, int n){
    if(n > s.size()) return " wrong";
    string ans;
    int tmpi;
    int tmpj;
    int nCG = 0;
    int maxN = 0;
    for(int i = 0; i < n; i++){
        ans.push_back(s[i]);
        if(s[i] == 'C' || s[i] == 'G') nCG++;
    }
    maxN = nCG;
    tmpi = 1;
    tmpj = n;
    while(tmpj < s.size()){
        if(s[tmpi-1] == 'C' || s[tmpi-1] == 'G') nCG--;
        if(s[tmpj] == 'C' || s[tmpj] == 'G') nCG++;

        if(nCG > maxN){
            ans = "";
            for(int i = tmpi; i <tmpi+ n; i++){
                ans.push_back(s[i]);
            }
            maxN = nCG;
        }
        
        tmpj++;
        tmpi++;
    }
    return ans;
}
int main(){
    
    string s = "AACTGTGCACGACCTGA";
    //cin>>s;
    int n = 5;
    //cin>>n;
    string ans;
    ans = minStr(s, n);
    cout<<ans;
    return 0;

}
