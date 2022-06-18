#include <iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        string tmps1;
        vector<string> tmp;
        huisu(s, tmp, 0, tmps1);
        return ans;
    }
    void huisu(const string &s, vector<string> tmp, int i, string tmps1){
        if(i >= s.size()) return;
        cout<<"tmps:"<<tmps1<<endl;
        cout<<"tmpsize:"<<tmp.size()<<endl;
        if(tmp.size() == 3){
            if(trans(s, i, s.size()-1) > 0){
                string tmps = tmp[0] + "." + tmp[1] + "." + tmp[2]+ ".";
                    while(i < tmps.size()){
                        tmps.push_back(s[i]);
                    }
                cout<<"its in"<<endl;
                ans. push_back(tmps);
                
            }
            return;
        }
        if (tmps1.size() == 0){
            tmps1.push_back(s[i]);
            huisu(s, tmp, ++i, tmps1);
        } 
        else if(tmps1[tmps1.size()-1] == '0' || tmps1.size()==3){
            if(trans(tmps1, 0, tmps1.size()-1) > 0){
                tmp.push_back(tmps1);
                tmps1 = "";
                huisu(s, tmp, i, tmps1);
            }
            else return;
            
        }
        else{
            tmps1.push_back(s[i]);
            huisu(s, tmp, ++i, tmps1);
            tmps1.pop_back();
            tmp.push_back(tmps1);
            tmps1 = "";
            huisu(s, tmp, i, tmps1);
            
        }
        
        
    }
    int trans(string s, int i, int j){
        if (j - i > 3) {
            cout<<"j - i > 3"<<i<<j<<endl;
            return -1;
        }
        int ans = 0;
        if(s[i] == 0 && i < j) {
            cout<<"s[i]=0"<<i<<j<<endl;
            return -1;
        }
        for(int w = i; w <=j; w++){
            
            ans = ans*10 + (s[w]-'0');
        }
        if (ans > 255) {
            cout<<"ans>255"<<ans<<endl;
            return -1;
        }
        return ans;
    }
};


int main(){

    Solution sol1;
    string s1 = "25525511135";
    vector<string> s2 = sol1.restoreIpAddresses(s1);
    cout<<s2.size()<<endl;
    return 0;
}