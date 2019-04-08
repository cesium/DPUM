import itertools;[print(*a) for a in sorted({tuple(sorted(n)) for n in itertools.combinations([int(n) for n in input().split()],3) if sum(n)==0})]
