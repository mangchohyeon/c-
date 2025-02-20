#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream infile("Prime Numbers.txt");
  if(!infile)
  {
    cerr << "Can't open the file(Prime Numbers.txt)\n";
    return -1;
  }

  int N,t,count = 0;
  string line;
  
  cout << "Input number : ";
  cin >> N;

  if(N > 1000000)
  {
    cerr << "Number has to be less than 1000000 or equal 10000000 and more than 0\n";
    return -1;
  }
  else if(N <= 0)
  {
    cerr << "Number has to be less than 1000000 or equal 10000000 and more than 0\n";
    return -1;
  }
    
  while(1)
  {
    getline(infile,line);
    t = stoi(line);
    if(t > N)
    {
      break;
    }
    count ++;
  }

  
  cout << "The number of prime numbers up to the number you entered is " << count << ".\n";

  return 0;
}