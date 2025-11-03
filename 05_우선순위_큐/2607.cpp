#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //단어 개수 
    cin >> n; 

    string norm; //기준 단어 
    cin >> norm; 

    //기준 단어 알파벳 빈도 저장용 배열
    int freq[26] = {0}; 

    for (char c : norm){
        freq[c - 'A']++; //빈도 카운트 
    }

    int count = 0; //같은 단어 개수 카운트 
    string word; //기준 단어 다음부터 입력 받음 

    for (int i = 0; i < n-1; i++){
        cin >> word; 
        int temp[26];
        int diff = 0; //다른 알파벳 개수 카운트 
        copy(freq, freq+26, temp); //temp에 기준 단어 배열 복사 
        
        for (char k : word){
            temp[k - 'A']--; 
        }
        for (int j=0; j<26; j++){
            diff += abs(temp[j]);
        }
        //같은 구성 -> diff=0 
        //하나의 문자 더하거나 빼는 경우 -> diff=1
        //하나의 문자를 바꾸는 경우 -> diff=2 
        if ((diff<=2) && (abs((int)norm.size()-(int)word.size()))<=1){
            count++; 
        }
    }
    cout << count; 
}