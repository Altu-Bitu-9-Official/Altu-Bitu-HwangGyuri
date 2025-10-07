#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력 (지구, 태양, 달)
    int e, s, m;
    cin >> e >> s >> m;

    // 연산 
    for (int year = 1; year <= 7980; year++){
        //입력값과 비교할 변수 각각 세팅 
        int E = year % 15;
        if (E == 0){
            E = 15; 
        }
        int S = year % 28;
        if (S == 0){
            S = 28; 
        }
        int M = year % 19; 
        if (M == 0){
            M = 19; 
        }
        if (E==e && S==s && M==m){
            cout << year << '\n'; 
        }
    }
}