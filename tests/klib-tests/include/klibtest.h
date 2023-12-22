#ifndef __KLIBTEST_H__
#define __KLIBTEST_H__

#include <am.h>
#include <klib.h>
#include <klib-macros.h>

void check(bool cond);
void check_seq(uint8_t *data, int l, int r);
void check_eq(uint8_t *data, int l, int r, int val);

void init_seq(uint8_t *data, int n);

#endif
