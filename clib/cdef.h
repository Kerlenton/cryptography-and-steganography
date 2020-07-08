#ifndef CDEF_H

#define CDEF_H
#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

#define NULL ((void*) 0)
#define END(x) ((mode == x) ? END_OF_STRING : END_OF_NUMBER)

#endif