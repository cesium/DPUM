#!/usr/bin/env python3

letters = "abcdefghijklmnopqrstuwvxyz"
morse = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..".split()
# CREATE DICTIONARY WITH LETTERS AND MORSE
dictionary = dict(zip(morse, letters))
result = []

def check_morse_code(original_code, all = set(dictionary), used_letters = []):


    for i in range(1,5):
        checking = original_code[:i]

        if checking in all:            
            used_letter = dictionary.get(checking, "")

            used_letters.append(checking)
            # REMOVE USED LETTERS FROM DICTIONARY
            rest = all.copy()
            rest.remove(checking)
            result.append(used_letter)

            # CHECK IF LETTERS ARE BEING REMOVED

            check_morse_code(original_code[i:], rest)
            break    



check_morse_code('.--...-.-.-.....-.--........----.-.-..---.---.--.--.-.-....-..-...-.---..--.----..')
print(result)

