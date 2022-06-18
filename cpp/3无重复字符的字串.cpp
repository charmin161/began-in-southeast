#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int  lenOflongestsubstring(string str){
    int n = str.size();
    if(n < 1) return 0;
    int l = -1;
    int r = 0;
    int ans = 0;
    unordered_map<char, int> myMap;
    while(r < str.size()){
        if(myMap.count(str[r])){
            l = max(l, myMap[str[r]]);
        }
        
        ans = max(ans, r-l);
        cout<<r<<l<<ans<<endl;
        myMap[str[r]] = r;
        r++;
    }
    return ans;
}



int main(){

    cout<<lenOflongestsubstring("abba");
    return 0;
}