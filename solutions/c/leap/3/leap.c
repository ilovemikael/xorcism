#include "leap.h"

bool leap_year(int year) {
  bool a = year%4 == 0 && (year%100 != 0 || year%400 == 0) ? 1 : 0;
  return a;
}
