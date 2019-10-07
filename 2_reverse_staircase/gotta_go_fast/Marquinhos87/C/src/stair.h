/** @file stair.h*/

#ifndef STAIR_H_
#define STAIR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/** Function to verify if all characters pass to program are numbers
 *
 * @param l String pass to the program.
 * @return Return 0 if alright OK or 1 if some character isn't a number
 */
int verify(char* l);

/** Function to print to stdout the result stairCase.
 *
 * @param tam Number of stairs to draw.
 */
void prt(int tam);

/** Function that calls the others to generate de final result.
 *
 * @param l String with the number of stairs.
 * @return Return 0 if alright OK or 1 if something wrong
 */
int stair(char* l);

#endif