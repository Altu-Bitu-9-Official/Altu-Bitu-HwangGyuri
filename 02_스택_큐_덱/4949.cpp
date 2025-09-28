#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str; 

    //getline: 계행 이전까지의 문자열 입력 받음 
    while(getline(cin, str)){   
        //온점 들어오면 종료 
        if (str == "."){
            break;
        }    

        //괄호 저장 스택 정의 
        stack<char> s;
        bool status = true; 

        for (char c : str){
            //여는 괄호면 스택에 push 
            if (c == '('|| c == '['){
                s.push(c);
            } else if (c == ')'){ // 닫는 괄호인 경우 
                if (s.empty() || s.top() != '('){
                    status = false; 
                    break; 
                }
                s.pop();
            }
            else if (c == ']'){
                if (s.empty() || s.top() != '['){
                    status = false;
                    break; 
                }
                s.pop(); 
            }
        }
        //실행 후 스택 비어있어야 함 
        if (!s.empty()){
            status = false; 
        }
        //status = false이면 no 출력 
        cout << ((status) ? "yes\n" : "no\n");
    }
}