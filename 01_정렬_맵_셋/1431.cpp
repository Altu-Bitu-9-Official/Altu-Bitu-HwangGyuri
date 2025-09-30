#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
// 2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
// 3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.

bool comp(const string& a, const string& b){
    // 1. 
    if (a.size() != b.size()){
        return a.size() < b.size();
    }
    // 2. 
    int asum = 0;
    int bsum = 0;
    for (char k : a){
        if (isdigit(k)){
            asum += (k - '0');
        }
    }
    for (char k : b){
        if (isdigit(k)){
            bsum += (k - '0');
        }
    }
    if (asum != bsum){
        return asum < bsum; 
    }
    // 3. 
    return a < b; 
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
    }

    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i <n; i++){
        cout << arr[i] << '\n';
    }
}