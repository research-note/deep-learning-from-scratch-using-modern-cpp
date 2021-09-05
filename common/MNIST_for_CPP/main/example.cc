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
        for (int j=0; j<28; ++j) {
            cout << parser->test_image[0][(i * 28) + j] << " ";
        }
        cout << endl;
    }

	return 0;
}
