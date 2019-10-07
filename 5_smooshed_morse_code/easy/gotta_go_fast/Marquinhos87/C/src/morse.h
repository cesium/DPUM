/** @file morse.h*/

#ifndef MORSE_H_
#define MORSE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Function that translate a character to morse code.
 *
 * @param c Character to converte to morse code.
 * @return String with morse code of the character
 */
char* translateChar(char c);

/** Function to print to stdout the result translation.
 *
 * @param l String for translation.
 * @param ls Set of Strings with morse code of every character
 */
void prt(char* l,char** ls,int n);

/** Function that calls the others to generate de final result.
 *
 * @param l String for translation.
 * @return Return 0 if alright OK or 1 if something wrong
 */
int translate(char* l);

#endif