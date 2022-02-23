#include <iostream>
using namespace::std;

int A[25];
int n;
int sz = 0, mx = -1;
int dp[100][100] = {0};

int maxSum (int n){
    
    sz = 1;
    int ans[25] = {0};
    for(int i = 0; i < n; i++){
        if(A[i] > 0){
           
            ans[sz] = A[i];
            sz++;
        }
    }
    
    ans[0] = 1, ans[sz] = 1;
    sz++;
    
   
    for(int j = 2; j < sz; j++){
        for(int left = 0; left < sz - j; left++){
            int right = left + j;
            
            for(int i = left + 1; i < right; i++){
                if(left == 0 and right == sz - 1){
                    dp[left][right] = max(dp[left][right], ans[left] * ans[i] * ans[right] + dp[left][i] + dp[i][right]);
                }
                else{
                    dp[left][right] = max(dp[left][right], ans[left] * ans[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
    }
    
    
//    for(int i = 0; i < sz; i++){
//        for(int j = 0; j < sz; j++){
//            cout<< dp[i][j] << " ";
//        }
//        
//        cout<< endl;
//    }
    
    return dp[0][sz-1];
    
}

int main()
{
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    cout<<maxSum(n) << endl;
}
