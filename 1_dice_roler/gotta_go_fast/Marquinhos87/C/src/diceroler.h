/** @file diceroler.h*/

#ifndef DICEROLER_H_
#define DICEROLER_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int x; /*!< This is a global variable to save the current position of the line that we are processing.*/

/** Function that parse the string to get the number of dices.
 *
 * @param l a charater pointer.
 * @return The number of dices
 */
int getD(char* l);

/** Function that parse the string to get the number of faces of the dices.
 *
 * @param l a charater pointer.
 * @return The number of faces of every dice
 */
int getF(char* l);

/** Funtion that generate numbers between '1 to f' in a total of 'd' times.
 *
 * @param d Number of dices.
 * @param f Number of faces.
 * @return The Integer array with de values of the all dices
 */
int* genV(int d,int f);

/** Function to print to stdout the result of a play or multiple-play.
 *
 * @param d Number of dices.
 * @param v Sum of the values of all dices.
 * @param vs Integer array with all values of the dices.
 */
void prt(int d,int v,int* vs);

/** Function that make de sum of all dices rolled.
 *
 * @param d Number of dices.
 * @param v Integer array with all values of the dices.
 * @return The sum of all dices rolled
 */
int sum(int d,int* v);

/** Function that calls the others to generate de final result
 *
 * @param l String to process.
 * @return Return 0 if alright OK or 1 if something wrong
 */
int calc(char* l);

#endif