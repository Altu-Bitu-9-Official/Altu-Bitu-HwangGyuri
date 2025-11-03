#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //N번째 큰 수 
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; //최소힙 정의 

    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int num;
            cin >> num; 

        //메모리 초과 방지 -> 상위 n개 값만 유지 
        if (pq.size() < n){
            pq.push(num); 
        }

        else if (num > pq.top()){
            pq.pop();
            pq.push(num); 
        }
    }
 }
    cout << pq.top();
}