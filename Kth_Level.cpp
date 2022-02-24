#include <iostream>
using namespace::std;
int arr[2][100];
int size, n;
int ans;
int main()
{

    int x;
    cin >> x;
    string s;
    cin >> s;
    
    int commit = 0, negative = 0, temp = 0, level = 0, size = 0;
    
    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == ')' || s[i] == '('){
            if(commit == 1){
                if (negative == 1){
                    temp = temp * (-1);
                    negative = 0;
                }
                arr[0][size] = level;
                arr[1][size] = temp;
                
                size++;
                temp = 0;
            }
            
            if(s[i] == '('){
                level++;
            }
            else if(s[i] == ')'){
                level--;
            }
        }
        
        else if (s[i] == '-'){
            negative = 1;
            commit = 1;
        }
        else{
            temp = temp * 10 + s[i] - 48;
            commit = 1;
        }
        
    }
    
    
    
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            
            if(arr[0][j] > arr[0][i]){
                int temp0 = arr[0][j];
                int temp1 = arr[1][j];
                arr[0][j] = arr[0][i];
                arr[1][j] = arr[1][i];
                arr[0][i] = temp0;
                arr[1][i] = temp1;
            }
        }
    }
    
    int sum = 0;
    
    for(int i = 0; i < size; i++){
        if(arr[0][i] == x + 1){
            sum += arr[1][i];
        }
    }
    
    cout<< sum << endl;
    
}
