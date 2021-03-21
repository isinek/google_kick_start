n = int(input())
for i in range(n):
	x, wg = [int(x) for x in input().split()]
	s = input()
	og = sum([1 for x in range(len(s)//2) if s[x] != s[-x - 1]])
	print('Case #%d: %d' % (i + 1, abs(wg - og)))
