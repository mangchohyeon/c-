#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    char *pi1 = new char[10200];
    char *pi2 = new char[10200];

    ifstream pi_text1("pi.txt");
    ifstream pi_text2("pi2.txt");

    int pi_num1, pi_num2;

    if (pi_text1.is_open()) 
    {
        string line;
        string last_line;  // 마지막 줄을 저장할 변수

        // 파일 끝까지 한 줄씩 읽으면서 마지막 줄만 저장
        while (getline(pi_text1, line)) 
        {
            last_line = line;
        }

        // 마지막 줄을 pi1에 저장
        strcpy(pi1, last_line.c_str());
        pi_num1 = last_line.length(); // pi1의 길이 저장

        cout << "pi.txt 파일이 정상적으로 열림\n";
        pi_text1.close();
    } 
      
    else 
    {
        cout << "pi.txt 파일이 정상적으로 열리지 않음\n";
        return -1;
    }

    if (pi_text2.is_open()) 
    {
        pi_text2 >> pi2;
        pi_num2 = strlen(pi2);
        cout << "pi2.txt 파일이 정상적으로 열림\n";
        pi_text2.close();
    }
      
    else 
    {
        cout << "pi2.txt 파일이 정상적으로 열리지 않음\n";
        return -1;
    }

    int count = -2;
    for (int i = 0; i < pi_num2 - 1; i++) 
    {
        if (pi1[i] == pi2[i]) 
        {
            count++;
        } 
        else 
        {
            cout << "사용자가 구한 pi값과 실제 pi값은 \n";
            cout << "소수점 " << count << "번째 자리까지 일치합니다.\n";
            break;
        }
    }

    for (int i = 0; i < strlen(pi1); i++) 
    {
        cout << pi1[i];
    }

    cout << '\n';

    return 0;
}