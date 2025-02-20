#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  string pi;
  ifstream infile("pi2.txt");

  getline(infile,pi);
  infile.close();
  
  pi = pi.substr(0,20002);

  ofstream outfile("pi2.txt", ios:: out);
  outfile<< pi << '\n';

  return 0;
}