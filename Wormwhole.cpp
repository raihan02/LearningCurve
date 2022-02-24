#include <iostream>
using namespace::std;

int mn = 99999999;
int f[3], g[3], arr[20];
int w[20][20];
int n;
int mask[20];
int abs (int i){
    if(i > 0){
        return i;
    }
    return -i;
}
int minx(int x, int y){
    return (x>=y) ? y : x;
}

int dist(int sx, int sy, int tx, int ty){
  
    return abs(sx - tx) + abs(sy - ty);
}
void wormHole (int sx, int sy, int tx, int ty, int value)
{
    mn = minx(mn, (dist(sx, sy, tx, ty) + value));
    
    
    for(int i = 0; i < n; i++){
        if (mask[i] == 0){
            
            mask[i] = 1;
            
            int temp = dist(sx, sy, w[i][0], w[i][1]) + w[i][4] + value;
            wormHole(w[i][2], w[i][3], tx,ty, temp);
            
            temp = dist(sx, sy, w[i][2], w[i][3]) + w[i][4] + value;
            wormHole(w[i][0], w[i][1], tx, ty, temp);
            mask[i] = 0;
        }
    }
    
}

int main()
{
    
    int tes;
    cin >> tes;
    
    while(tes--){
        cin >> n;
        int sx,sy,tx,ty;
        cin >> sx >> sy >> tx >> ty;
        for(int i = 0; i < n; i++){
            mask[i] = 0;
            
            for(int j = 0; j < 5; j++){
                cin >> w[i][j];
            }
        }
        
        mn = 99999999;
        wormHole(sx, sy, tx, ty, 0);
        
        cout<< mn << endl;
    }
}
