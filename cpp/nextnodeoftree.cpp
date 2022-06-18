#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode():val(0), right(nullptr), left(nullptr){}
    TreeNode(int v):val(1), right(nullptr), left(nullptr){}
    TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r){}
};

TreeNode* nextNode(TreeNode* root)
{
    if(!root) return nullptr;
        
}  
int main(){
    

    return 0;
}