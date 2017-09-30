#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n,m,k;
    double input;
    double max = 0;

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input;
            if(input > max){
                max = input;
            }
        }
    }
    cout << fixed << setprecision(k);
    cout << max <<endl;
    return 0;
}
