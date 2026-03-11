#pragma once

#ifdef NDEBUG
#define ASSERT(x) ((void)0)
#else
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(x)                                                              \
  do {                                                                         \
    if (!(x)) {                                                                \
      fprintf(stderr, "Assertion failed: %s (%s:%d)\n", #x, __FILE__,          \
              __LINE__);                                                       \
      abort();                                                                 \
    }                                                                          \
  } while (0)
#endif
