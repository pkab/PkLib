#ifndef PKLIB_NODE_H
#define PKLIB_NODE_H
#include <stdint.h>
enum {
    Int = 0, Float, Double, Char, String, _bool,I8,
    I16, I32, I64, U8,
    U16, U32, U64, _complex
};
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
/*
 * Node Data Structure
 * Data can be of any type
 * Defined by type of data
 * size defines the size of Data
 */
typedef struct NODE{
    void *data; /* void pointer for any Data */
    uint8_t type; /* void Data type */
    uint64_t size; /* Size */
    struct NODE* next; /* Next node prev */
    struct NODE* prev; /* previous node */
}Node;

Node* NodeInit(void* , uint8_t, uint64_t);
void NodeFree(Node*);
void NodePrint(Node*);
#endif //PKLIB_NODE_H
