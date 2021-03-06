// Copyright 2012 Rui Ueyama <rui314@gmail.com>
// This program is free software licensed under the MIT license.

#include <stdarg.h>
#include "test.h"

char buf[100];

static void test_int(int a, ...) {
    va_list ap;
    va_start(ap, a);
    expect(1, a);
    expect(2, va_arg(ap, int));
    expect(3, va_arg(ap, int));
    expect(5, va_arg(ap, int));
    expect(8, va_arg(ap, int));
    va_end(ap);
}

static void test_float(float a, ...) {
    va_list ap;
    va_start(ap, a);
    expectf(1.0, a);
    expectf(2.0, va_arg(ap, float));
    expectf(4.0, va_arg(ap, float));
    expectf(8.0, va_arg(ap, float));
    va_end(ap);
}

static void test_mix(char *p, ...) {
    va_list ap;
    va_start(ap, p);
    expect_string("abc", p);
    expectf(2.0, va_arg(ap, float));
    expect(4, va_arg(ap, int));
    expect_string("d", va_arg(ap, char *));
    expect(5, va_arg(ap, int));
    va_end(ap);
}

char *format(char *fmt, ...) {
    va_list ap;
    va_start(ap, p);
    vsprintf(buf, fmt, ap);
    va_end(ap);
    buf;
}

static void test_va_list(void) {
    expect_string("", format(""));
    expect_string("3", format("%d", 3));
    expect_string("3,1.0,6,2.0,abc", format("%d,%.1f,%d,%.1f,%s", 3, 1.0, 6, 2.0, "abc"));
}

void testmain(void) {
    print("varargs");
    test_int(1, 2, 3, 5, 8);
    test_float(1.0, 2.0, 4.0, 8.0);
    test_mix("abc", 2.0, 4, "d", 5);
    test_va_list();
}
