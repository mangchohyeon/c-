#include <fstream>
#include <gmp.h>
#include <iostream>
#include <mpfr.h>
#include <string>

using namespace std;

int main() {
  // pi = 4(1 - 1/3 + 1/5)
  //  MPFR 변수 및 정밀도 설정
  mpfr_t pi, term, denominator, sign, one, minus_one;
  const int precision = 512; //정밀도 설정

  mpfr_init2(pi, precision);          // 결과를 저장할 pi 변수
  mpfr_init2(term, precision);        // 각 항을 계산할 term 변수
  mpfr_init2(denominator, precision); // 분모 (1, 3, 5, ...)
  mpfr_init2(sign, precision);        // 부호
  mpfr_init2(one, precision);         //분자(1)
  mpfr_init2(minus_one, precision);
  mpfr_set_d(pi, 0.0, MPFR_RNDN);         // pi 초기화
  mpfr_set_d(one, 1.0, MPFR_RNDN);        // 상수 1 설정
  mpfr_set_d(minus_one, -1.0, MPFR_RNDN); //상수 -1설정
  mpfr_set_d(sign, 1.0, MPFR_RNDN);

  int max_iterations = 50; // 테일러 급수의 최대 항 수

  for (int i = 0; i < max_iterations; ++i) {
    // 분모 계산 (2 * i + 1)
    mpfr_set_ui(denominator, 2 * i + 1, MPFR_RNDN);

    // 항 계산: 1 / 분모
    mpfr_div(term, one, denominator, MPFR_RNDN);

    // 부호 적용
    mpfr_mul(term, term, sign, MPFR_RNDN);
    mpfr_add(pi, term, pi, MPFR_RNDN);

    // 부호 반전
    mpfr_mul(sign, minus_one, sign, MPFR_RNDN);
  }

  // π 계산: pi = 4 * (sum)
  mpfr_mul_ui(pi, pi, 4, MPFR_RNDN);

  // 결과 출력
  cout << "Calculated π: ";
  mpfr_out_str(stdout, 10, 100, pi, MPFR_RNDN); // 소수점 100자리까지 출력
  cout << '\n';

  fstream value_file("pi_value.txt", ios::app);
  fstream value_last_file("pi_value_last.txt", ios::out);

  if (!value_file) {
    cout << "Can't open the file(pi_value.txt)\n";

    // 변수 해제
    mpfr_clear(pi);
    mpfr_clear(term);
    mpfr_clear(denominator);
    mpfr_clear(one);

    return -1;
  }

  char *temp_str = new char[20100];        // 충분한 메모리 확보
  mpfr_sprintf(temp_str, "%.20000Rf", pi); // 소수점 이하 20000자리 출력
  value_file << temp_str << '\n';
  value_last_file << temp_str << '\n';

  // 변수 해제
  mpfr_clear(pi);
  mpfr_clear(term);
  mpfr_clear(denominator);
  mpfr_clear(one);
  delete[] temp_str;

  value_file.close();

  return 0;
}