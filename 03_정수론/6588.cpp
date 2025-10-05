#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//에라토스테네스의 체
vector<bool> isPrime(int n){
    //n짜리 벡터 true로 초기화 
    vector<bool> is_prime(n+1, true); 
    //0과 1은 소수가 아니므로 미리 제거 
    is_prime[0] = is_prime[1] = false;
    //2~n-1까지 검사 
    for (int i = 2; i * i <= n; i++){
        if (is_prime[i]){ //i가 소수라면 
            for (int j = i * i; j <= n; j += i){
                is_prime[j] = false; //i의 배수 제거 
            }
        }
    }
    return is_prime;
}

//n = a+b 계산 (a=3, 5, ...) -> 가능한 a 반환 
int test(int n, vector<bool>& is_prime){
    for (int a = 3; a <= n / 2; a += 2){
        //a, b(=n-a) 둘 다 소수이면 
        if (is_prime[a] && is_prime[n-a]){
            return a; 
        }
    }
    return 0; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int max = 1000000;
    vector<bool> is_prime = isPrime(max);

    int n;
    while(cin >> n && n != 0){
        //a값 존재하면 
        int a = test(n, is_prime);
        if (a){
            cout << n << " = " << a << " + " << (n-a) << "\n"; 
        }
        else{
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
    }
}
