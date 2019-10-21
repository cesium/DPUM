#!/usr/bin/env python3


alphabet = "abcdefghijklmnopqrstuvwxyz"
morse = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..".split(' ')
test_code = '.--...-.-.-.....-.--........----.-.-..---.---.--.--.-.-....-..-...-.---..--.----..'
# CREATE DICTIONARY [LETTERS : MORSE]
dictionary = dict(zip(alphabet, morse))

def check_morse_code(remaining: str, used_letters = ''):

    # IF ALL THE CODE IS TESTED, JOIN THE LETTERS
    if not remaining:
        if len(used_letters) == len(alphabet):
            return "".join(used_letters)

    # LOOP THGROUGH ALL LETTERS IN THE ALPHABET
    for letter in {l for l in alphabet if l not in used_letters}:
        # CHECK IF THE MORSE PART CURRENTLY VERIFYING IS THE NEXT ONE TO CHECK
        if not remaining.startswith(dictionary[letter]):
            continue
        # ADD THE LETTER VERIFIED NOW TO THE LIST OF USED LETTERS
        verified_letters = used_letters + letter
        # REMOVE THE TESTED CODE FROM THE REMAINING VARIABLE
        untested_test_code = remaining[len(dictionary[letter]):]
        try:
            # ENTER ON A RECURSIVE LOOP TO TEST IT WITH ALL THE CODE
            return check_morse_code(untested_test_code, verified_letters)
        except:
            continue

    raise Exception('Ok, espero que dê')

print(check_morse_code(test_code))
