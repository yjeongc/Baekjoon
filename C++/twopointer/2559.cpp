#include <iostream>
#include <vector>
//using namespace std;

int main(){
    int N, K;
    int start = 0, end = 0, sum = 0, largest_sum = 0, value = 0;
    std::vector<int> H;
    
    std::cin >> N >> K;

    for(int i = 0; i<N; i++){
        std::cin >> value;
        H.push_back(value);
    }

    
    for(int j=0; j<K; j++)
        sum += H[j];

    largest_sum = sum;    
    end = start + K -1;


    while(end < N){
        if(largest_sum < sum){
            largest_sum = sum;
        } 
            sum -= H[start++];
            end++;
        sum += H[end];
    }

    std::cout << largest_sum;

    return 0;
}