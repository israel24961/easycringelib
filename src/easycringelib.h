#pragma once
#include <stdint.h>

typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
typedef int64_t i64;

typedef float f32;
typedef double f64;

// Shortened structs
typedef struct {
  union {
    u64 a;
    u64 x;
  };
  union {
    u64 b;
    u64 y;
  };
} u64u64;

typedef struct {
  union {
    i64 a;
    i64 x;
  };
  union {
    i64 b;
    i64 y;
  };
} i64i64;

typedef struct {
  u64 size;
  union {
    u8 *data;
    void *datav;
    char *datac;
  };
} su64;

typedef struct {
  union {
    u32 x;
    u32 a;
    u32 u0;
  };
  union {
    u32 y;
    u32 b;
    u32 u1;
  };
}u32u32;

typedef struct {
  union {
    u32 a;
    u32 u0;
  };
  union {
    u32 b;
    u32 u1;
  };
  union {
    u32 c;
    u32 u2;
  };
} u32u32u32;

typedef u32u32u32 u32_3; // Cringe but I've used this for OpenGL indexes

typedef struct {
    union{
        f32 x;
        f32 a;
    };
    union{
        f32 y;
        f32 b;
    };
} f32f32;

// casting and when 'anonymous struct returns' are allowed 😥
#define verr(type)                                                             \
  struct {                                                                     \
    i64 err;                                                                   \
    type data;                                                                 \
  }

// Fun - c23
#ifdef __GNUC__
#define var __auto_type
#define let __auto_type
#else // For whatever reason  ccls and clangd-16.0.6  can't infer 'auto' in c23
#define var auto
#define let auto
#endif

typedef void fn;

#define __attr(X) __attribute__(( __##X##__ ))

#include <stdlib.h>
static inline void freep(void *p) {
        free(*(void**) p);
}

#define __clean  __attribute__((cleanup(freep)))

