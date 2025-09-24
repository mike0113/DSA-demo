#include <iostream>

using std::cout;
using std::cin;


int main(){
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    while(h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0){
        if(m2 < m1){
            m2 += 60;
            h2 -= 1;
        }
        if(h2 < h1){
            h2 += 24;
        }
        int sleep = (h2-h1)*60 + (m2-m1);
        cout << sleep << std::endl;

        cin >> h1 >> m1 >> h2 >> m2;
    }

}