#include <iostream>
using namespace std;
int main() {
    int we;
    int mu;
    int chu;
    cin>>we;
    for (we = 0; we <= 100/5; ++we) {
        for (mu = 0; mu <=100/3 ; ++mu) {
            for (chu = 0; chu <= 100*3; chu+=3) {
                if(100==we*5+mu*3+chu/3&&100==we+mu+chu){
                    cout<<we<<" "<<mu<<" "<<chu<<endl;
                }
            }
        }
    }




    return 0;
}
