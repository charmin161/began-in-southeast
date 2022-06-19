#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

//设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整个棋盘的那两条对角线。

//方法一 维护四个哈希 暴力dfs
class Solution {
public:
    vector<vector<string>> ans;
    void dfs(vector<vector<int>> tmp, int i, int j, unordered_set<int> &col,
    unordered_set<int> &row, unordered_set<int> &xiel, unordered_set<int> &xier){
        if(col.count(i) || row.count(j) || xiel.count(i - j)||xier.count(i+j)) return;
        if(i == tmp.size()-1){
            tmp[i][j] = 1;
            vector<string> tmpVS;
            for(int a = 0; a < tmp.size(); a++){
                string tmpS;
                for(int b = 0; b < tmp.size(); b++){
                    if(tmp[a][b] == 0){
                        tmpS.push_back('.');
                    }
                    else{
                        tmpS.push_back('Q');
                    }
                }
                tmpVS.push_back(tmpS);
            }
            ans.push_back(tmpVS);
            tmp[i][j] = 0;
            return;
        }
        col.insert(i);
        row.insert(j);
        xiel.insert(i-j);
        xier.insert(i+j);
        tmp[i][j] = 1;
        for(int a = 0; a < tmp.size(); a++){
            dfs(tmp, i+1, a, col, row, xiel, xier);
        }
        tmp[i][j] = 0;
        col.erase(i);
        row.erase(j);
        xiel.erase(i-j);
        xier.erase(i+j);
    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> col;
        unordered_set<int> row;
        unordered_set<int> xiel;
        unordered_set<int> xier;
        vector<vector<int>> tmp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dfs(tmp, 0, i, col, row, xiel, xier);
        }

        return ans;

    }
};
//方法二 用位运算替代哈希表


int main(){
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(8);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<endl;
        }
    }
    return 0;
}