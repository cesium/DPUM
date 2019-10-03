#!/usr/bin/env python3

letters = "abcdefghijklmnopqrstuwvxyz"
morse = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..".split()
# CREATE DICTIONARY WITH LETTERS AND MORSE
dictionary = dict(zip(morse, letters))



def check_morse_code(original_code, dictionary, used_letters = []):
    
    for i in range(1,3):
        checking = original_code[:i]

        if checking in dictionary:            
            used_letter = dictionary.get(checking, "")

            dictionary.pop(checking)
            print("\n\n\n")
            print(checking)

            print(used_letter, end=" ")   



check_morse_code('-----......------.--.-...-.---.-..-.....-.-.-.-..--..-.--.--..-..-...-..--.....--.', dictionary)

