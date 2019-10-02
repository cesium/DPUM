#!/usr/bin/env python3

letters = "abcdefghijklmnopqrstuwvxyz"
morse = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..".split()
# CREATE DICTIONARY WITH LETTERS AND MORSE
dictionary = dict(zip(morse, letters))



def check_morse_code(original_code):
    print(original_code)

print(check_morse_code('-----......------.--.-...-.---.-..-.....-.-.-.-..--..-.--.--..-..-...-..--.....--.'))