#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;


// R(뒤집기) 함수
void R(deque<int>& dq) {
    vector<int> temp;

    // 큐에서 모든 요소를 임시 벡터에 저장
    while (dq.size() > 0) {
        temp.push_back(dq.front());
        dq.pop_front();
    }

    // 임시 벡터에 저장된 요소를 역순으로 다시 큐에 넣기
    for (int i = temp.size() - 1; i >= 0; i--) {
        dq.push_back(temp[i]);
    }
}


// D(버리기) 함수
bool D(deque<int>& dq) {
    if (dq.empty()) {
        return false;
    }
    dq.pop_front();
    return true;
}



int main() {
    int N;
    deque<int> dq;
    cin >> N; 

    for (int i = 0; i < N; i++){
        vector <string> RD;
        string input;
        cin >> input;
        RD.push_back(input);

        int M;
        cin >> M;
        
        vector<string>TC;
        string input2;
        cin >> input2;
        for(unsigned i=0; i<RD.size(); i++){
            if(input2[i] != '[' && input2[i] != ']' && input2[i] !=','){
                TC.push_back(input2);
            }
        }


        if(TC.size()!=0){
            for(unsigned i=0; i<TC.size(); i++){
            if(TC[i]=="R"){
                R(dq);
            }
            else if(TC[i] == "D"){
                D(dq);
            }            
            }
            for(unsigned i=0; i<TC.size(); i++){
                cout << TC[i];  
            }
        }
        else if(TC.size()==0){
            for(unsigned i=0; i<TC.size(); i++){
            if(TC[i]=="D"){
                cout << "error" << endl;
            }
            }
        }
    }
    return 0;
}