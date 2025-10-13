#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    string king, rock; //킹, 돌 위치정보 
    int n; //움직이는 횟수

    cin >> king >> rock >> n; 
    int kx = king[0] - 64;  //킹 x 좌표 a~h -> 1~8로 변환 
    int ky = king[1] - 48;  //킹 y 좌표 숫자로 변환 

    int rx = rock[0] - 64; //돌 x 좌표 a~h -> 1~8로 변환
    int ry = rock[1] - 48; //돌 y 좌표 숫자로 변환 

    string input; //이동 입력값 

    //연산
    while(n--){
        cin >> input; 
        //이동 값(돌 이동에도 써야 함)
        int mx = 0;
        int my = 0; 

        if (input == "R"){
             mx = 1; 
        }
        else if (input == "L"){
            mx = (-1); 
        }
        else if (input == "B"){
            my = (-1); 
        }
        else if (input == "T"){
            my = 1; 
        }
        else if (input == "RT"){
            mx = 1; 
            my = 1; 
        }
        else if (input == "LT"){
            mx = (-1); 
            my = 1; 
        }
        else if (input == "RB"){
            mx = 1; 
            my = (-1); 
        }
        else if (input == "LB"){
            mx = (-1); 
            my = (-1); 
        }
        //한 번 실행 후 킹 위치 좌표 
        int move_kx = kx + mx;
        int move_ky = ky + my; 

        int move_rx = rx;
        int move_ry = ry; 

        //킹이 체스판 밖으로 나가는 경우 
        if (move_kx < 1 || move_kx > 8 || move_ky < 1 || move_ky >8){
            continue; 
        }

        //킹 위치가 체스판 안이고 
        //킹 위치 = 돌 위치인 경우 
        if (move_kx == rx && move_ky == ry){
            move_rx = rx + mx;
            move_ry = ry + my; 
            //돌 위치 이동 시 돌이 체스판 밖으로 나가는 경우 
            if (move_rx < 1 || move_rx > 8 || move_ry < 1 || move_ry >8){
                continue;
            }
        }

        kx = move_kx;
        ky = move_ky;

        rx = move_rx;
        ry = move_ry; 
    }
    //출력(다시 형변환 해주어야 함)
    cout << (char)(kx+64) << ky << '\n';
    cout << (char)(rx+64) << ry;
}