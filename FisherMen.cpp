#include <iostream>
using namespace::std;

int mn = 99999999;
int f[3], g[3], arr[20];
int n;

int abs (int i){
    if(i > 0){
        return i;
    }
    
    return -i;
}
void solve(int l, int r)
{
    if(l == r){
        
        int i, dist = 0;
        
        for (i = 0; i < f[0]; i++){
            dist = dist + abs(arr[i] - g[0]);
        }
        
        for (int j = 0; j < f[1]; j++){
            dist = dist + abs(arr[i] - g[1]);
            i+= 1;
        }
        
        for (int j = 0; j < f[2]; j++){
            dist = dist + abs(arr[i] - g[2]);
            i+= 1;
        }
        
        dist += i;
        
        if(dist < mn){
            mn = dist;
        }
        
        return;
    }
    
    for(int i = l; i <= r; i++){
        
        swap(arr[i], arr[l]);
        solve(l + 1, r);
        swap(arr[i], arr[l]);
    }
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++){
        arr[i] = i+1;
    }
    
    for(int i = 0;i < 3; i++){
        cin >> g[i];
    }
    
    for(int i = 0; i < 3; i++){
        cin >> f[i];
    }
    
    mn = 9999999;
    solve(0, n-1);
    cout<< mn << endl;

}
