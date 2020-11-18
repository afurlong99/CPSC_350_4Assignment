#include <fstream>
#include <iostream>


using namespace std;



int main(int argc, char const *argv[]) {

ifstream infile;
infile.open(argv[1]);
int num;
infile >> num;
std::cout << num << '\n';

infile.close();



}
