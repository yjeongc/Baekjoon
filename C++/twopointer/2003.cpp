#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, M, count = 0;
    int value;
    vector<int>A;

    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> value;
        A.push_back(value);
    }


    int start = 0, end = 0, sum = A[0];
    while (start < N && end < N){
        if(sum < M){
            if(end < N)
                sum += A[++end];
            else
                break;
        }else if(sum > M){
            sum -= A[start++];
        } else if(sum == M){
            count += 1;
            sum -= A[start++];
        } ; //start에 해당하는 값을 sum에서 빼고 start를 1 증가 시킴.
    }
    cout << count;

    return 0;
}