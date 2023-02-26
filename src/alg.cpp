// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  else {
    return value * pown(value, n - 1);
  }
}

uint64_t fact(uint16_t n) {
  if (n < 2) {
    return 1;
  }
  else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double e = 1.0;
  for (int i = 1; i <= count; i++) {
    e += calcItem(x, i);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double sum = 0;
  for (count; count > 0; count--) {
    sum += pown(-1, count - 1) * calcItem(x, 2 * count - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0;
  for (count; count > 0; count--) {
    sum += pown(-1, count - 1) * calcItem(x, 2 * count - 2);
  }
  return sum;
}
