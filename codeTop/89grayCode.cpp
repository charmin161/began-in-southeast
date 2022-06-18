#include <bits/stdc++.h>
using namespace std;

// n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
// 每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
// 第一个整数是 0
// 一个整数在序列中出现 不超过一次
// 每对 相邻 整数的二进制表示 恰好一位不同 ，且
// 第一个 和 最后一个 整数的二进制表示 恰好一位不同
// 给你一个整数 n ，返回任一有效的 n 位格雷码序列 

//方法一 暴力深度学习，直接遍历，到10就超时了
class Solution1 {
public:
    int Hanming(int A, int B){
        int Hanm = A^B;
        int countN = 0;
        while(Hanm){
            countN ++;
            Hanm &= (Hanm -1);
        }
        return countN;
    }
    vector<int> ans;
    vector<int> tmp;
    bool flag = false;

    void dfs(int n, int i, vector<bool> & visited){
        if(flag) return;
        ans.push_back(i);
        visited[i] = true;
        if (ans.size() == n){
            if(Hanming(ans[0], ans[n-1]) == 1) {
                flag = true;
                tmp = ans;
            }
            ans.pop_back();
            visited[i] = false;
            return;
        }
        
        for(int j = 0; j < n; j++){
            if(flag) break;
            if(!visited[j] && Hanming(i, j) == 1){
                dfs(n, j, visited);
            }
        }
        visited[i] = false;
        ans.pop_back();
    }
    vector<int> grayCode(int n) {
        vector<bool> visited(2^n-1, false);
        dfs(2^n-1, 0, visited);
        return tmp;
    }
};

//方法2 翻转
//n-1 -> n
//反转之后，加上2^n;
class Solution2 {
public:

    vector<int> grayCode(int n) {
        if(n == 0){
            return vector<int>(1, 0);
        }
        vector<int> G = grayCode(n-1);
        vector<int> Gr = G;
        reverse(Gr.begin(), Gr.end());
        int j = (1 << (n-1));
        for(int i = 0; i < Gr.size(); i++){
            G.push_back( Gr[i] + j);
        }
        return G;
    }
};

int main(){
    Solution2 sol;
    vector<int> ans = sol.grayCode(4);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}