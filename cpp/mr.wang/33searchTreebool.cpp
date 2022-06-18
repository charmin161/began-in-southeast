#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
unordered_map<int, int>myMap;
    bool verifyPI(vector<int>& postorder, vector<int>& inorder, int lp, int rp, int li, int ri){
        cout<<"lp"<<endl;
        
        if ((rp - lp) != (ri - li)) return false;
        if(lp == rp) return (postorder[rp] == inorder[ri]);
        
        if(rp < lp) return true;
        int pval = postorder[rp];
        int mi = myMap[pval];
        if(mi > ri || mi < li) return false;
        int lefN = mi - li;
        return verifyPI(postorder, inorder, lp, lp + lefN -1, li, mi -1) &&
        verifyPI(postorder, inorder, lp + lefN, rp - 1, mi+1 , ri);
        
    }
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> inorder = postorder;
        sort(inorder.begin(), inorder.end());
        
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            myMap[inorder[i]] = i;
        }
        return verifyPI(postorder, inorder, 0, n-1, 0, n-1);
    }
};

int main(){
    vector<int> A({4,8,6,12,16,14,10});
    Solution sol1;
    if(sol1.verifyPostorder(A)){
        cout<<"yes"<<endl;

    }
    else{
        cout<<"np"<<endl;
    }
    return 0;

}