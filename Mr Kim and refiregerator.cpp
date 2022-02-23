#include <iostream>
using  namespace::std;

int x[20], y[20], n,vis[20], ans;

int abs (int i){
    if(i > 0){
        return i;
    }
    return -i;
}

int dist(int i, int j){
    
    int x1 = x[i], x2 = x[j];
    int y1 = y[i] , y2 = y[j];
    
    return  (abs(x1 - x2) + abs(y1 - y2));
}

void findMinPath(int x, int nodes, int value)
{
    if (nodes == n){
        ans = min(ans, value + dist(x,  n + 1));
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            findMinPath(i, nodes + 1, value + dist(x, i));
            vis[i] = false;
        }
    }
}

int main()
{
    
    int tes = 10, o = 0;
    //cin >> tes;
    
    while(tes--){
        o++;
        ans = 99999999;
        cin >> n;
        for(int i = 0; i <= n + 2; i++){
            vis[i] = false;
        }
        cin >> x[n + 1] >> y[n + 1] >> x[0] >> y[0];
        
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> y[i];
        }
        findMinPath(0, 0, 0);
        cout<< "# " << o <<  " " << ans << endl;
        
    }
}
