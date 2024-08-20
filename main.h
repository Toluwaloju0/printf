#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int spec_C(char c);
int spec_S(char *str);
int spec_D(int a);
char *itoa(int a);
char *itoa_fr_unsigned(unsigned int a);
char *itoa_fr_octal(unsigned int a);
char *itoa_fr_hexasmall(unsigned int a);
char *itoa_fr_hexabig(unsigned int a);
int spec_B(unsigned int a);
char *to_binary(unsigned int num);
int spec_U(unsigned int a);
int spec_O(unsigned int a);
int spec_x(unsigned int a);
int spec_X(unsigned int);

#endif
