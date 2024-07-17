#include <iostream>
#include <vector>
#define N 10001

using namespace std;

//생성자를 만드는 함수.
int makeNum(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}


int main(){
    vector<int>res;
    vector<bool> Cache(N,false);

    res.push_back(1);
    
    Cache[1] = true;
    int trueNumber = 1;

    while(trueNumber < 10001){
        trueNumber = makeNum(trueNumber);
        Cache[trueNumber] = true;
    }

    for(int i = 1; i < 10001; i++){
        if(Cache[i] == false){
            res.push_back(i);

            int temp = i;

            while(i < 10001){
                i = makeNum(i);
                Cache[i] = true;
            }

            i = temp;
        }
    }

    cout << 1 << "\n";
    
    for(size_t j = 1; j < res.size(); j++){
        cout << res[j] << "\n";
    }
    

    return 0;
}
