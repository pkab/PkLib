#ifndef PKLIB_COMPARATOR_H
#define PKLIB_COMPARATOR_H

#include <stdint.h>
enum {
    Int = 0, Float, Double, Char, String, _bool,
    I8, I16, I32, I64, U8, U16, U32, U64, _complex, entry, Other
};
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

int compare(void* data1, void *data2, u8 type);
#endif //PKLIB_COMPARATOR_H
