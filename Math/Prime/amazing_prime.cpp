#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream infile("Prime Numbers.txt");
  if(!infile)
  {
    cout << "Can't open the infile\n";
    infile.close();
    return -1;
  }

  string line;
  string *prime = new string[78479];
  string *res = new string[1100];
  int count = 0,length_count = 0;

  for(int i = 0; i < 78479; i++)
  {
    getline(infile,line);
    prime[i] = line;
    int length = line.length();
    
    if(length == 1)
    {
      res[count] = line;
    }
    else if(length >= 2)
    {
      for(j = 0; j < )
    }
  }

  
  
  //g++ -o amazing_prime amazing_prime.cpp && ./amazing_prime

  return 0;
}