#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf: takes an argument and prints to the standard output
 * considering only the %,c and s specifiers
 * dest[i]: pointer pointing to the address of the new string.
 * format[i]: pointer to the source string.
 */
 
 int _printf(const char *format, ...)
 {

	 convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	 };
	 
	 va_list ls;
	 int i = 0, j = 0;
	 char *dest;
	 
	  
     
     if (dest == NULL)
         return(1);
         
     va_start(ls, format);
     while(format[i] != '\0')
     {
         if(format[i] == '%')
           {
                 i++;
             if (format[i] == 'c')
               {
                   dest[j] = (char)va_arg(ls, int);
                 j++;
               }
	     else if (format[i] == 's')
	     {
		     dest[j] = (char *)va_arg(ls, int);
		     j++;
	     }
	   }
           else
               {
                   dest[j] = format[i];
                   j++;
                }
                i++;
     }
     write(1, dest, i++);
     va_end(ls);
     free(dest);
     return(i);
}
