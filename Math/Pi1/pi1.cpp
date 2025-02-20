#include <iostream>
#include <mpfr.h>
#include <gmp.h>
#include <fstream>

using namespace std;

int main(void)
{
    ofstream out("pi.txt", ios::app);

    const int precision = 32768;

    // pi = n * sin(pi / n)
    mpfr_t res, pi, n, temp, ten;

    mpfr_init2(res, precision);
    mpfr_init2(pi, precision);
    mpfr_init2(n, precision);
    mpfr_init2(temp, precision);
    mpfr_init2(ten, precision);

    char* temp_str = new char[10100];  // 충분한 메모리 확보
    mpfr_const_pi(pi, MPFR_RNDN);
    mpfr_set_d(ten, 10, MPFR_RNDN);
    mpfr_set_d(n, 1, MPFR_RNDN);

    for (int i = 0; i < 1000; i++)
    {
        mpfr_mul(n, n, ten, MPFR_RNDN);       // n = n * 10
        mpfr_div(temp, pi, n, MPFR_RNDN);    // temp = pi / n
        mpfr_sin(temp, temp, MPFR_RNDN);     // temp = sin(pi / n)
        mpfr_mul(res, n, temp, MPFR_RNDN);   // res = n * sin(pi / n)

        // 문자열로 변환 후 파일에 저장
        mpfr_sprintf(temp_str, "%.10000Rf", res);  // 소수점 이하 10000자리 출력
        out << temp_str << '\n';
    }

    delete[] temp_str;
    mpfr_clear(res);
    mpfr_clear(pi);
    mpfr_clear(n);
    mpfr_clear(temp);
    mpfr_clear(ten);

    return 0;
}