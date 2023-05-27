#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
va_list l, char b[], int f, int w, int p, int size);

/****************** FUNCTIONS_TO_PRINT ******************/

/*chars and strings */
int print_char(va_list t, char b[],
	int f, int w, int p, int size);
int print_string(va_list t, char b[],
	int f, int w, int p, int size);
int print_percent(va_list t, char b[],
	int f, int w, int p, int size);

/*numbers */
int print_int(va_list t, char b[],
	int f, int w, int p, int size);
int print_binary(va_list t, char b[],
	int f, int w, int p, int size);
int print_unsigned(va_list t, char b[],
	int f, int w, int p, int size);
int print_octal(va_list t, char b[],
	int f, int w, int p, int size);
int print_hexadecimal(va_list t, char b[],
	int f, int w, int p, int size);
int print_hexa_upper(va_list t, char b[],
	int f, int w, int p, int size);

int print_hexa(va_list t, char map_to[],
char b[], int f, char flag_character, int w, int p, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *f, int *y);
int get_width(const char *f, int *y, va_list l);
int get_precision(const char *f, int *y, va_list l);
int get_size(const char *f, int *y);

/*Function to print string in reverse*/
int print_reverse(va_list t, char b[],
	int f, int w, int p, int size);

/* Function to print non printable characters */
int print_non_printable(va_list t, char b[],
	int f, int wh, int p, int size);


/* Funcion to print a memory address */
int print_pointer(va_list t, char b[],
	int f, int w, int p, int size);

/*Function to print a string in rot */
int print_rot13string(va_list t, char b[],
	int f, int w, int p, int size);

/* width handler */
int handle_write_char(char cha, char b[],
	int f, int w, int p, int size);
int write_number(int _positive, int ind, char b[],
	int f, int w, int p, int size);
int write_num(int ind, char b[], int f, int w, int p,
	int len, char pad, char ext_c);
int write_pointer(char b[], int ind, int len,
	int w, int f, char pad, char ext_c, int _start);
int write_unsgnd(int _negative, int ind,
char b[], int f, int w, int p, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int n, int size);
long int convert_size_unsgnd(unsigned long int n, int size);

#endif /* MAIN_H */
