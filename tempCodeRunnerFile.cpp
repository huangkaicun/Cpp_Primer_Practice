#include <iostream>
using namespace std;

class PTM{
    public:
    int ivalue;
    static float fvalue;
 
};
int main(){
    int PTM::*piValue = &PTM::ivalue;
    float *pfValue = &PTM::fvalue;
    float *spfValue = &PTM::fvalue;

    cout << "piValue = " << piValue << endl;
    // cout << "pfValue = " << pfValue << endl;
    cout << "spfValue = " << spfValue << endl;
    
}