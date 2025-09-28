#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int diffStr(string s){
    set<string> k;

    for (int i=0; i < s.size(); i++){
        for (int j=s.size()-i; j > 0; j--){
            string str = s.substr(i, j);
            k.insert(str);
        }
    }
    return k.size();
}



int main(){
    
    string input;
    cin >> input;

    cout << diffStr(input);

}