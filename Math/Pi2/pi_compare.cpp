#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string pi1,pi2;
  
  ifstream file1("pi_value_last.txt");
  ifstream file2("pi2.txt");

  getline(file1,pi1);
  getline(file2,pi2);

  int leng = pi2.length();
  int res = 0;
  
  for(int i = 0; i < leng; i++)
  {
    if(pi1[i] != pi2[i])
    {
      res = i-1;
    }
  }

  if(res == 0)
  {
    res = leng - 2;
  }

  cout << "사용자가 구한 pi값은 실제 pi값과 소수점 " << res << "자리까지 일치합니다.\n"; 


  return 0;
}