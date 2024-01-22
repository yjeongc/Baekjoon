#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string s;
    cin >> s;

    //istringstream�� ���ڿ��� �Է� ��Ʈ������ �����ϴ� Ŭ����. ���ڿ����� �����͸� �о���� ���� �����.
    istringstream ss (s);

    //�ӽ÷� ���ڿ��� ������ ����.
    string strBuffer;

    //����� ������ ����.
    vector<int> v;
    v.clear();

    //"+"�� "-"�� �������� ���ڿ��� �и��Ͽ� tokens�� ������.
    while(getline(ss, strBuffer, '+')){  //��Ʈ�� ss���� +�� ã�� �� �������� ���ڿ��� strBuffer�� �����Ѵ�.
        istringstream plus_ss(strBuffer); //���ο� istringstream ����.

        while(getline(plus_ss, strBuffer, '-')){
            int number = stoi(strBuffer);
            v.push_back(number);
        }
    }
    
    // ������ ���� ���
    cout << "�и��� ���ڵ�:" << endl;
    for (auto i : v) {
        cout << i << endl;
    }

    

    //a[i]=s[i]-'0';

    return 0;
}