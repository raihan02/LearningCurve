#include <iostream>
using namespace std;
int arr[20][20];
bool visited[20][20];
int n, m;
int f = 0;
int level;

void dfs(int i, int j)
{
    if(i <0 || j < 0 || i >= n || j >= m){
        return;
    }
    
    if(visited[i][j]){
        return;
    }
    visited[i][j] = true;
    if(arr[i][j] == 3){
        
        f = 1;
        return;
    }
    
    if(j + 1 < m && (arr[i][j + 1] == 1 || arr[i][j + 1] == 3) && !visited[i][j + 1]){
        dfs(i, j+1);
    }
    
    
    if(j - 1 >= 0 && (arr[i][j - 1] == 1 || arr[i][j - 1] == 3) && !visited[i][j - 1]){
        dfs(i, j-1);
    }
    
    int h = 1;
    for( h = 1; h <= level; h++){
        if(h <= level && h + i < n && (arr[i + h][j] == 1 || arr[i + h][j] == 3) && !visited[i + h][j])
        {
            dfs(i + h, j);
        }
    }
    
    for(h = 1; h <= level; h++){
        if(h <= level && i - h >= 0 && (arr[i - h][j] == 1 || arr[i - h][j] == 3) && !visited[i - h][j])
        {
            dfs(i - h, j);
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(level = 0; level < n; level++){
        
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                visited[i][j] = false;
            }
        }
        
        f = 0;
        dfs(n - 1, 0);
        
        if(f){
            cout<<level<<endl;
            break;
        }
    }
}
