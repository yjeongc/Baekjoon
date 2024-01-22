#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string s;
    cin >> s;

    //istringstream은 문자열을 입력 스트림으로 간주하는 클래스. 문자열에서 데이터를 읽어오기 위해 사용함.
    istringstream ss (s);

    //임시로 문자열을 저장할 버퍼.
    string strBuffer;

    //결과를 저장할 벡터.
    vector<int> v;
    v.clear();

    //"+"와 "-"를 기준으로 문자열을 분리하여 tokens에 저장함.
    while(getline(ss, strBuffer, '+')){  //스트림 ss에서 +를 찾아 그 전까지의 문자열을 strBuffer에 저장한다.
        istringstream plus_ss(strBuffer); //새로운 istringstream 생성.

        while(getline(plus_ss, strBuffer, '-')){
            int number = stoi(strBuffer);
            v.push_back(number);
        }
    }
    
    // 벡터의 값을 출력
    cout << "분리된 숫자들:" << endl;
    for (auto i : v) {
        cout << i << endl;
    }

    

    //a[i]=s[i]-'0';

    return 0;
}