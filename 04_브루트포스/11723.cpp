#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//중복 검사 
bool checkdouble(vector<int>& v, int k){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == k){
            return false; //중복 존재 
        }
    }
    return true; //중복 없음 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력 
    int m; //수행해야 하는 연산의 수
    cin >> m; 

    string cmd; //명령어 

    vector<int> v; 

    //연산
    while(m--){
        cin >> cmd; 
        if (cmd == "all"){
            v.assign({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}); 
        }
        else if (cmd == "empty"){
            v.clear(); 
        }
        else if (cmd == "add"){
            int c; 
            cin >> c;
            if (checkdouble(v, c)){
                v.push_back(c);
            }
            continue; 
        }
        else if (cmd == "remove"){
            int c; 
            cin >> c;
            if (!checkdouble(v, c)){
                v.erase(remove(v.begin(), v.end(), c), v.end()); 
            }
            continue;
        }
        else if (cmd == "check"){
            int c; 
            cin >> c;
            if (checkdouble(v, c)){
                cout << 0 << '\n';
            }
            else
                cout << 1 << '\n';
        }
        else if (cmd == "toggle"){
            int c; 
            cin >> c;
            if (checkdouble(v, c)){ //중복이 없으면
                v.push_back(c);
            }
            else{ //중복이 있으면 
                v.erase(remove(v.begin(), v.end(), c), v.end()); 
            }
        }
    }
}