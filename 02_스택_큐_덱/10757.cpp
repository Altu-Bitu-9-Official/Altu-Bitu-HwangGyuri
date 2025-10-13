#include <iostream>
#include <algorithm>
#include <string> 
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력값 
    string A, B;
    cin >> A >> B; 
    
    //각 자릿수 숫자로 변환하여 스택에 넣고, 일의 자리부터 꺼내며 연산 
    stack<int> a, b;
    for (char c : A){
        a.push(c - '0');
    }
    for (char c : B){
        b.push(c - '0');
    } 

    //출력값
    string result;
    //올림값 정의 
    int carry = 0; 

    //스택 둘 다 empty 돼도 carry 존재할 수 있음 
    while(!a.empty() || !b.empty() || carry){
        int xa = 0;
        int yb = 0;

        if (!a.empty()){
            xa = a.top();
            a.pop();
        }
        if (!b.empty()){
            yb = b.top();
            b.pop();
        }
        //각 자릿수끼리 더해줌 
        int k = xa + yb + carry;
        //숫자 다시 문자로 변환 -> result 문자열에 붙임 
        result.push_back(char('0' + (k%10)));
        carry = k / 10; //올림값 갱신 
    }
    //result 순서 바꾸기 
    reverse(result.begin(), result.end());
    cout << result; 
}
