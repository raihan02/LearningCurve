#include <iostream>
using namespace::std;
int color[101];
int arr[100][100];
int n;

bool dfs(int u)
{
    bool flag = true;
    
    for(int i = 0; i < n; i++){
        if(arr[u][i] == 1){
            if(color[i] == -1){
                color[i] = 1 - color[i];
                flag = flag & dfs(i);
            }
            
            if(color[u] == color[i]){
                return false;
            }
        }
    }
    
    return  flag;
}


int main()
{
    cin >> n;
//    for(int i = 0; i < n; i++){
//        color[i] = -1;
//        for(int j = 0; j < n; j++){
//
//            cin >> arr[i][j];
//        }
//    }
//
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i = 0; i < n; i++){
        if(!dfs(i)){
            cout<<-1<<endl;
            return 0;
          
        }
    }
    
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            cout<<i << " ";
        }
    }
    
    cout<< endl;
}
