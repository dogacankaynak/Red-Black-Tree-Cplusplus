#include <iostream>
#include "RedBlackTree.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
RedBlackTree tree;
string fileName(argv[1]);
int n = atoi(argv[2]);
tree.generateTree(fileName, n);
cout << "\n Total " << n << "-gram count: "<< tree.wordCount() << endl;
tree.wordFrequencies();

//Before insertion of new n-grams
cout << "\nTotal " << n << "-gram count: "<< tree.wordCount() << endl;
tree.addNgram("samp");
tree.addNgram("samp");
tree.addNgram("zinc");
tree.addNgram("aatt");
cout << "\nTotal " << n << "-gram count: "
<< tree.wordCount() << endl;
tree.wordFrequencies();

return 0;
}
