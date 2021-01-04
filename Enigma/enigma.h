#ifndef ENIGMA_H

#define ENIGMA_H
#define BUFF_SIZE 1024

#include <stdio.h>

extern int enigma(int in, int rotor1, int rotor2, int rotor3, int reflector);
extern int input_string(char buffer[]);

#endif
