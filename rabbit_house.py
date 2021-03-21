def count_boxes(m, r, c, q):
	res, curr_val = 0, m[q[0][0]][q[0][1]]
	while (len(q)):
		if curr_val > m[q[0][0]][q[0][1]]:
			q = sorted(q, key=lambda x: -m[x[0]][x[1]])
			curr_val = m[q[0][0]][q[0][1]]
		if curr_val == m[q[-1][0]][q[-1][1]]:
			break
		x = q.pop(0)

		if x[0] > 0 and m[x[0] - 1][x[1]] < m[x[0]][x[1]] - 1:
			res += m[x[0]][x[1]] - 1 - m[x[0] - 1][x[1]]
			m[x[0] - 1][x[1]] = m[x[0]][x[1]] - 1
		if x[0] < r - 1 and m[x[0] + 1][x[1]] < m[x[0]][x[1]] - 1:
			res += m[x[0]][x[1]] - 1 - m[x[0] + 1][x[1]]
			m[x[0] + 1][x[1]] = m[x[0]][x[1]] - 1

		if x[1] > 0 and m[x[0]][x[1] - 1] < m[x[0]][x[1]] - 1:
			res += m[x[0]][x[1]] - 1 - m[x[0]][x[1] - 1]
			m[x[0]][x[1] - 1] = m[x[0]][x[1]] - 1
		if x[1] < c - 1 and m[x[0]][x[1] + 1] < m[x[0]][x[1]] - 1:
			res += m[x[0]][x[1]] - 1 - m[x[0]][x[1] + 1]
			m[x[0]][x[1] + 1] = m[x[0]][x[1]] - 1

	return res

n = int(input())
for i in range(n):
	r, c = [int(x) for x in input().split()]
	m, q = [], []
	highest = [(0, 0)]
	for j in range(r):
		m += [[int(x) for x in input().split()]]
		q += [(j, k) for k in range(c)]
	q = sorted(q, key=lambda x: -m[x[0]][x[1]])
	print('Case #%d: %d' % (i + 1, count_boxes(m, r, c, q)))
