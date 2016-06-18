
#include <iostream>
using namespace std;

enum Action {BUY, SELL, NEGOTIATE};

void determine(Action x){
	switch(x){
		case BUY:
			cout << "BUY" << endl;
			break;
		case SELL:
			cout << "SELL" << endl;
			break;
		case NEGOTIATE:
			cout << "NEGOTIATE" << endl;
	}
}

int main(){

	Action a = BUY;
	Action b = SELL;
	Action c = NEGOTIATE;

	determine(a);
	determine(b);
	determine(c);
	determine(c);
	determine(b);
	determine(a);

	return 0;
}
