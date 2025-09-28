#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력값 
    //다이어트전체중, 에너지섭취량(기초대사량), 기초대사량 변화역치 
    int weight, energy1, meta1; 
    cin >> weight >> energy1 >> meta1;

    //다이어트기간, 에너지섭취량(기초대사량), 일일활동대사량
    int day, energy2, meta2; 
    cin >> day >> energy2 >> meta2; 

    //요요 판단용 
    int energy = energy1; 

    //1. 기초대사량 변화 무시할 경우
    int weight1 = weight; 
    bool dead1 = false;

    for (int d = 0; d < day; d++){
        //k1: 일일 에너지 섭취량 - 일일 에너지 소비량 
        int k1 = energy2 - (energy + meta2);
        weight1 += k1; 
        if (weight1 <= 0){
            dead1 = true;
            break;
        }
    }
    //사망 예상
    if (dead1){
        cout << "Danger Diet\n";
    }
    else 
        cout << weight1 << ' ' << energy << '\n'; 

    //2. 기초대사량 변화 고려할 경우
    int weight2 = weight;
    int change_e = energy; //변화 
    bool dead2 = false;

    for (int d = 0; d < day; d++){
        int k2 = energy2 - (change_e + meta2);
        weight2 += k2;
        if (weight2 <= 0){
            dead2 = true;
            break;
        }
        //변화 역치 T 초과 
        if (abs(k2) > meta1){            
            change_e += (int)floor(k2 / 2.0);
        }
        if (change_e <= 0){
            dead2 = true;
            break;
        }
    }
    //사망 예상
    if (dead2){
        cout << "Danger Diet\n";
    } else{ //요요 예상 
        if ((energy - change_e)> 0){
            cout << weight2 << ' ' << change_e << ' ' << "YOYO" << '\n';
         } else{
            cout << weight2 << ' ' << change_e << ' '<< "NO" << '\n';
    }
    }

}