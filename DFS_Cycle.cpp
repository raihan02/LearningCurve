#include <iostream>
#include <algorithm>
using  namespace::std;
int stack[100], g[100][100], top = -1, mx = 99999999;

int ans[105];
int vis[105];
int ansSize = -1;
int n,m;


void dfs(int current){
    
    // First check top not equal -1 and curentNode Already visied
    
    if (vis[current] == 1 && top != -1 ){
        
        int localSum = stack[top], i;
        
        for( i = top - 1; stack[i] != current; i--){
            localSum += stack[i];
        }
        
        if (i != -1 && localSum < mx){
            mx = localSum;
            ansSize = -1;
            ans[++ansSize] = stack[top];
            
            for( i = top - 1; stack[i] != current; i--){
                ans[++ansSize] = stack[i];
            }
            
        }
    }
    else{
        vis[current] = 1;
        
        for(int i = 1;i <= n; i++){
            if(g[current][i] == 1){
                stack[++top] = i;
                dfs(i);
                top--;
            }
        }
    }
    
    vis[current] = 0;
}


int main()
{
    
    cin >> n >> m;
    
    while(m--){
        int a,b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    
    vis[n+1] = {0};
    for(int i = 1; i <= n; i++){
        
        if(vis[i] == 0){
            stack[++top] = i;
            dfs(i);
            top--;
        }
    }
    
    sort(ans, ans + ansSize + 1);
    
    for(int i = 0; i <= ansSize; i++){
        cout<< ans[i] << " ";
    }
    
    cout<< endl;
}
