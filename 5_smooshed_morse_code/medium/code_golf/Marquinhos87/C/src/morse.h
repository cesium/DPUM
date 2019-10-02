/** @file morse.h*/

#ifndef MORSE_H_
#define MORSE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Function that translate morse code to character (with length 4).
 *
 * @param c Character to converte to morse code.
 * @return String with morse code of the character
 */
char translateToChar4(char* c);

/** Function that translate morse code to character (with length 3).
 *
 * @param c Character to converte to morse code.
 * @return String with morse code of the character
 */
char translateToChar3(char* c);

/** Function that translate morse code to character (with length 2).
 *
 * @param c Character to converte to morse code.
 * @return String with morse code of the character
 */
char translateToChar2(char* c);

/** Function that translate morse code to character (with length 1).
 *
 * @param c Character to converte to morse code.
 * @return String with morse code of the character
 */
char translateToChar1(char* c);

/** Function to print to stdout the result translation.
 *
 * @param l String of Morse Code to translation.
 * @param ls String with translation.
 */
void prt(char* l,char* t);

/** Function that calls the others to generate de final result.
 *
 * @param l String for translation.
 * @return Return 0 if alright OK or 1 if something wrong
 */
int translate(char* l);

#endif