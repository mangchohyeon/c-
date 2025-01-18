#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // 소수들 담아줄 배열
    int *prime = new int[100];
    int count = 1;                                      //소수들 개수
    prime[0] = 2;                                       // 첫 번째 소수는 2

    // 소수 찾기
    for (int n = 3; n < 100; n++) 
    {
        int flag = 1;                                   // 소수임을 나타내는 플래그
        for (int j = 0; j < count; j++) 
        {
            if (n % prime[j] == 0)                     // 소수가 아님
            {
                flag = 0;
                break;
            }
        }

        if (flag)                                      // 소수라면 prime에 추가
        {
            prime[count] = n;
            count++;
        }
    }

    // 파일에 소수 저장
    ofstream outfile("prime.txt"); // prime.txt 파일 열기
    if (!outfile) 
    {
        cerr << "파일을 열 수 없습니다.\n";
        delete[] prime; // 동적 메모리 해제
        return 1;
    }

    outfile << count << "\n\n";
    cout << "Restoring Prime numbers to prime.txt\n";
    cout << "Number Of Prime : " << count << "\n\n";
    cout << "Prime Numbers\n";

    for(int i = 0; i < count; i++) 
    {
        outfile << prime[i];
        cout << prime[i];
        if(i != count - 1) 
        {
            outfile << '\n';
            cout << '\n';
        }
    }

    outfile.close(); // 파일 닫기
    delete[] prime; // 동적 메모리 해제

    
    return 0;
}
