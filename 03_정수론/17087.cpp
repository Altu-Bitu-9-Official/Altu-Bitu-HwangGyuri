#include <iostream>
#include <vector> 

using namespace std;

//GCD 구하는 함수
int gdcIter(int a, int b){
    while (b){
        a %= b;
        swap(a, b);
    }
    return a; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s, a;
    //입력 첫째줄 
    cin >> n >> s;

    //동생 위치 벡터 
    vector<int> v(n); 

    for (int i = 0; i < n; i++){
        cin >> a;
        //수빈 위치-동생 위치 절댓값 벡터에 넣음 
        v.push_back(abs(s-a));
    }

    //최대공약수 계산 
    int gcd = v[0];
    for (int i = 1; i < v.size(); i++){
        gcd = gdcIter(v[i], gcd);
    }

    cout << gcd;
}