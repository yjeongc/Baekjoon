#include <iostream>
#include <vector>
#include <cmath>
#define INF 200000

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int>Card(N);

    for(int i=0; i<N; i++){
        cin >> Card[i];
    }

    int left = 0, mid = 1, right = 2, sum = 0, absSum = 0, minSum = INF, result = 0;

    while(left < N-2){
        sum = Card[left] + Card[mid] + Card[right];

        absSum = abs(M-sum);
        if(sum <= M && absSum < minSum) {
            minSum = absSum;
            result = sum;
        }
        
        if(mid == N-2){
            left++;
            mid = left + 1;
            right = mid + 1;
        }else if(right < N-1){
            right++;
        }else if(right >= N-1) {
            mid++;
            right = (mid+1);
        }
        
    }

    cout << result;

    return 0;
}