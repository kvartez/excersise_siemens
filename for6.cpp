
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
void color(int variable) {
    cout << " red wynosi:" << ((variable & 0x00ff0000) >> 16)<<endl;
    cout << " green wynosi:" << ((variable & 0x0000ff00) >> 8)<<endl;
    cout << " blue wynosi:" << ((variable & 0x000000ff) >> 0)<<endl;
    cout << " opacity wynosi:" << ((variable & 0xff000000) >> 24)<<endl;
}
bool check(int variable, int position) {
    
    if ((((0b1 << position) & variable) << position) == 1) {
        return true;
    }
    else if ((((0b1 << position) & variable) << position) != 1) {
        return false;
    }
}
void transition(int InNum,int OutNum) {
    int r,g,b;
    int rM, gM, bM;
    r = ((InNum & 0x00ff0000) >> 16);
    g = ((InNum & 0x0000ff00) >> 8);
    b = (InNum & 0x000000ff);
        
    rM = (((OutNum & 0x00ff0000) >> 16)-(r));
    gM = (((OutNum & 0x0000ff00) >> 8)- (g));
    bM = ((OutNum & 0x000000ff)-(b)) ;
       
    for (int i= 0; i <= 100; i++) {
        cout << hex<<((r+ (int)(rM*(i/100.0))) <<16 | ((g + (int)(gM * (i / 100.0))) << 8) | ((b + (int)(bM * (i / 100.0)))))<<endl;
    }
}
int main()
{

   
    //zadanie wykonac przejscie koloru coment if not needed
    transition(0x00111111, 0x00ffffff);
    //zadanie z * od zera druga zmienna
    cout<< check(0b00000001, 1) <<'\n';
    //wyluskiwanie kolorow
    color(0xf0ffffff);

    return 0;
}
