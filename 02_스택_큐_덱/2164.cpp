#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<int> q;
    
    int n;
    cin >> n;

    //큐에 숫자 삽입 
    for (int i=1; i<=n; i++){
        q.push(i);
    }

    while(q.size()>1){
        q.pop(); //맨 위 카드 버림 
        q.push(q.front()); //제일 위 카드 제일 아래로 옮김 
        q.pop();

    }
    
    cout << q.front();

}