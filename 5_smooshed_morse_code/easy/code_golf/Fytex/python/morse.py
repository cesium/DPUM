a='0524261202181416042313200706152229100803091711252728'
l=[bin(int(a[i:i+2]))[3:] for i in range(0,len(a),2)]
for c in input().lower():print(''.join('.-'[int(z)&1] for z in l[ord(c)-97]),end='') 
