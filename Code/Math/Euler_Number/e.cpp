#include <fstream>
#include <gmp.h>
#include <iostream>
#include <mpfr.h>
using namespace std;

int main() {
  string line;
  fstream infile1("e_info.txt");
  if (!infile1) {
    cout << "Can't open e_info.txt\n";
    return -1;
  }
  getline(infile1, line);
  infile1.close();
  string res = "", res2 = "", res3 = "";
  mpfr_t e, x, t1, t2, ten, one;
  const int precision = 16384;
  const int max = stoi(line);
  const int start = max - 1000;
  mpfr_init2(e, precision);
  mpfr_init2(x, precision);
  mpfr_init2(t1, precision);
  mpfr_init2(t2, precision);
  mpfr_init2(ten, precision);
  mpfr_init2(one, precision);
  mpfr_set_d(ten, 10.0, MPFR_RNDN);
  mpfr_set_d(one, 1.0, MPFR_RNDN);
  mpfr_set_d(e, 0.0, MPFR_RNDN); // e초기화
  mpfr_set_d(x, 1.0, MPFR_RNDN); // x초기화(1)
  mpfr_set_d(t2, 1000.0, MPFR_RNDN);
  mpfr_pow(t1, ten, t2, MPFR_RNDN);
  for (int i = start; i < max; i++) {
    mpfr_mul(t1, t1, ten, MPFR_RNDN); // t1 = 10^i;
    mpfr_div(x, one, t1, MPFR_RNDN);  // x = 1/10^i
    mpfr_add(t2, one, x, MPFR_RNDN);  // t2 = 1 + x
    mpfr_pow(e, t2, t1, MPFR_RNDN);   // e = (1+ 1/(10^i))^10^i
    char temp1[1010];
    mpfr_sprintf(temp1, "%.1000Rf", e);
    res += "x : 1/10^";
    res += to_string(i) + "\n";
    string temp2(temp1);
    res += "e : " + temp2 + "\n\n";
    if (i == max - 1) {
      res2 += "x : 1/10^";
      res2 += to_string(i) + "\n";
      res3 += "e : " + temp2 + "\n";
    }
  }
  fstream outfile1("e_value.txt", ios::app);
  if (!outfile1) {
    cout << "Can't open the txt file\n";
    mpfr_clear(e);
    mpfr_clear(x);
    mpfr_clear(t1);
    mpfr_clear(t2);
    mpfr_clear(ten);
    mpfr_clear(one);
    return -1;
  }
  outfile1 << res;
  cout << "Perfect!\n";
  outfile1.close();
  fstream outfile2("e_info.txt", ios::out);
  if (!outfile2) {
    cout << "Can't open e_info.txt\n";
    mpfr_clear(e);
    mpfr_clear(x);
    mpfr_clear(t1);
    mpfr_clear(t2);
    mpfr_clear(ten);
    mpfr_clear(one);
    return -1;
  }
  int temp = (max + 1000);
  outfile2 << temp;
  outfile2.close();
  fstream outfile3("e_value_last.txt", ios::out);
  if (!outfile3) {
    cout << "Can't open e_info.txt\n";
    mpfr_clear(e);
    mpfr_clear(x);
    mpfr_clear(t1);
    mpfr_clear(t2);
    mpfr_clear(ten);
    mpfr_clear(one);
    return -1;
  }
  outfile3 << res2 << res3;
  outfile3.close();
  fstream infile2("e_compare.txt", ios::in);
  if (!infile2) {
    cout << "Can't open e_compare.txt\n";
    mpfr_clear(e);
    mpfr_clear(x);
    mpfr_clear(t1);
    mpfr_clear(t2);
    mpfr_clear(ten);
    mpfr_clear(one);
    return -1;
  }
  string wiki;
  getline(infile2, line);
  getline(infile2, wiki);
  wiki += "\n";
  infile2.close();
  fstream outfile4("e_compare.txt", ios::out);
  if (!outfile4) {
    cout << "Can't open e_compare.txt\n";
    mpfr_clear(e);
    mpfr_clear(x);
    mpfr_clear(t1);
    mpfr_clear(t2);
    mpfr_clear(ten);
    mpfr_clear(one);
    return -1;
  }
  outfile4 << res3;
  outfile4 << wiki;
  outfile4.close();
  mpfr_clear(e);
  mpfr_clear(x);
  mpfr_clear(t1);
  mpfr_clear(t2);
  mpfr_clear(ten);
  mpfr_clear(one);
  // g++ -o e e.cpp -lgmp -lmpfr
  return 0;
}