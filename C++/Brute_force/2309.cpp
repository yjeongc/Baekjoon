#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int>Height(9);

    for(int i = 0; i < 9; i++){
        cin >> Height[i];
    }

    sort(Height.begin(), Height.end());

    int start = 0, end = 1, sum = 0;

    while(start < 9){
        sum = 0;

        for(int j = 0; j < 9; j++){
            if(j != start && j != end) sum += Height[j];
        }

        if(sum == 100){
            for(int k = 0; k < 9; k++){
                if(k !=start && k != end) cout << Height[k] << "\n";
            } break;
        }
        
        if(end < 9){
            end++;
        } else {
            start++;
            end = start + 1;
        }
    }

    return 0;
}