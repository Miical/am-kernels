#include "klibtest.h"

void check(bool cond) {
  if (!cond) halt(1);
}

void check_seq(uint8_t *data, int l, int r) {
  for (int i = l; i < r; i++) {
    check(data[i] == (uint8_t)i);
  }
}

void check_eq(uint8_t *data, int l, int r, int val) {
  for (int i = l; i < r; i++) {
    check(data[i] == val);
  }
}

void init_seq(uint8_t *data, int n) {
  for (int i = 0; i < n; i++) {
    data[i] = i;
  }
}
