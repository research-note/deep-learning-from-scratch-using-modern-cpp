#include "main/MnistParser.hpp"
#include <iostream>

using namespace std;

int main(void)
{
	MnistParser *parser =  new MnistParser();
	parser->loadMnist();

    cout<<fixed;
    cout.precision(1);
    for (int i=0; i<28; ++i) {
        for (i=0; i<784; i++) {
            cout << parser->test_image[0][i] << " ";
        }
        cout << endl;
    }

	return 0;
}
