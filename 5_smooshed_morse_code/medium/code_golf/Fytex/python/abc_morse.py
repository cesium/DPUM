from string import ascii_lowercase as z
a='0524261202181416042313200706152229100803091711252728'
d={x:''.join('.-'[int(z)&1] for z in bin(int(a[i:i+2]))[3:]) for x,i in zip(z,range(0,len(a),2))}
for i in open('input.txt', 'r'):print(list(filter(lambda x:''.join(map(d.get, x))==i[:-1],__import__('itertools').permutations(z))))


