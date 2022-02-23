
#include <iostream>
using namespace::std;

int arr[20][20];
int n, ans, mn = 9999999;
int prr[20];

void findPath()
{
    int res = 0;
    res += arr[0][prr[0]];
    res += arr[prr[n - 2]][0];
    
    for(int i = 0; i < n - 2; i++){
        res += arr[prr[i]][prr[i + 1]];
    }
    
    mn = min(mn, res);
}

void permute(int i, int j){
    if(i == j){
        findPath();
        return;
    }
    
    for(int q = i; q <= j; q++){
        swap(prr[q], prr[i]);
        permute(i + 1, j);
        swap(prr[q], prr[i]);
    }
    
}
int main()
{
    int tes;
    cin >> tes;
    while(tes--){
        cin >> n;
        for(int i = 0; i < n - 1; i++){
            prr[i] = i + 1;
        }
        
        
        mn = 999999999;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        
        permute(0, n - 2);
        
        cout<< mn << endl;
    
    }
}

