#include <bits/stdc++.h>
using namespace std;

int dp(vector<int>A, int n){
    vector<int>dp(n,INT_MAX);
    stack<int> myStack;
    myStack.push()
    for(int i = n-1;i>=0;i--){
        if(A[i] + i >= n ) dp[i] = 1;
        else{
            dp[i] = dp[i+A[i]] + 1;
            for(int j = i; j < i+A[i] ;j++){
                dp[i] = min(dp[i], dp[j]+2);
            }
        }
    }
    return dp[0];
}
int main(){
    int m = 0;
    vector<int> A = {2,5,1,1,1};
    cout<<dp(A, 6)<<endl;
    return 0;
}