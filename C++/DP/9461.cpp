#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int T = 0, Big = 0;
    cin >> T;
    
    vector<int>TC(T);
    for (int i=0; i<T; i++){
        cin >> TC[i];  
    }

    Big = TC[0];
    for(int j = 1; j<T; j++){
        if(Big <TC[j]){
            Big = TC[j];
        }
    }
    
    vector<int>P(Big);

    if(Big == 1){
        P[0] = 1;
    }
    if(Big == 2){
        P[0] = 1, P[1] = 1;
    }
    if(Big == 3){
        P[0] = 1, P[1] = 1, P[2] = 1;
    }
    if(Big >=4){
        P[0] = 1, P[1] = 1, P[2] = 1;
        for(int k=3; k<Big; k++){
            P[k] = P[k-1] + P[k-2];
        }    
    }

    for(int r = 0; r<T; r++){
        cout << P[TC[r]] << endl;
    }
    
    return 0;
}