#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//중복 확인 함수 
bool is_available(char b, const vector<char>& v){
    if (b == '*'){
        return false; 
    }
    for (char c : v){
        if (c == b){
            return true; 
        }
    }
    return false; 
}

string chain(int n, int k, vector<char>& v){
    int index = 0; 

    for (int i = 0; i < k; i++){
        int a;
        char b; 
        cin >> a >> b; 
        index = (index + a) % n;

        //이미 b 값으로 해당 칸이 채워져 있는 경우 
        if (v[index] == b){
            continue; 
        }

        //다른 값이 이미 채워져있거나, 해당 input이 이미 사용된 알파벳인 경우 
        if (v[index] != '*' || is_available(b, v)){
            return "!";
        }
        
        v[index] = b; 
    }

    //출력: 마지막 index에서 반시계 방향으로 
    string output; 
    output.reserve(n); 
    for (int i = 0; i < n; i++){
        int h = (index + i + 1) % n;
        output.push_back(v[h] == '*' ? '?': v[h]);
    }
    reverse(output.begin(), output.end());
    return output; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //n: 바퀴 칸 수, k: 회전 횟수 
    int n, k;
    cin >> n >> k;

    //바퀴 칸 수 = 벡터 사이즈, *로 초기화 
    vector<char> v(n, '*');

    string result = chain(n, k, v);
    cout << result; 
}