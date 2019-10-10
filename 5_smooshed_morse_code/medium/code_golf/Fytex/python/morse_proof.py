from timeit import Timer


setup = '''
from string import ascii_lowercase as z
from random import shuffle

_z = list(z)
perms = [shuffle(_z) or ''.join(_z) for _ in range(10**7)]
perms.append(z)

a='0524261202181416042313200706152229100803091711252728'
d={x:''.join('.-'[int(z)&1] for z in bin(int(a[i:i+2]))[3:]) for x,i in zip(z,range(0,len(a),2))}

string = '.--...-.-.-.....-.--........----.-.-..---.---.--.--.-.-....-..-...-.---..--.----..'

results = filter(lambda x:''.join(map(d.get, x))==string, perms)#__import__('itertools').permutations(z))
'''

print(Timer('print(list(results))', setup=setup).timeit(1)) # +-14 seconds

# Listed shuffles of ascii_lowercase to simulate 10^7 permutations of a single morse code
# Appended ascii_lowercase to the list so at least one string which corresponds to the morse code will print out (Prove code works correctly)
'''
10^7          -- 14s
4*10^26 (26!) -- x

x = 5,6×10^20s =  1.8*10^13 years

Since this code is to be as short as possible here we go! But we would have to wait around 1.8*10^13 years to get results :D I will get the results with the code in gotta_go_fast

'''
