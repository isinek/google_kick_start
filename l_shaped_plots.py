def count_l_shapes(m, r, c):
	v_segments, h_segments, fv_segments, fh_segments = [], [], [], []
	for x in m:
		for i in range(len(v_segments)):
			if v_segments[i][1][0] == x[0] - 1 and v_segments[i][1][1] == x[1]:
				v_segments[i][1] = x
				if v_segments[i][0] != v_segments[i][1]:
					fv_segments += [v_segments[i][:]]
		v_segments += [[x, x]]
		for i in range(len(h_segments)):
			if h_segments[i][1][0] == x[0] and h_segments[i][1][1] == x[1] - 1:
				h_segments[i][1] = x
				if h_segments[i][0] != h_segments[i][1]:
					fh_segments += [h_segments[i][:]]
		h_segments += [[x, x]]
	# print('\n'.join([str(x) for x in fv_segments]))
	# print('\n'.join([str(x) for x in fh_segments]))

	c = 0
	for x in fv_segments:
		for y in fh_segments:
			c += (x[0] == y[0] and (x[1][0] - x[0][0] + 1) == (y[1][1] - y[0][1] + 1)*2)
			c += (x[0] == y[0] and (x[1][0] - x[0][0] + 1)*2 == (y[1][1] - y[0][1] + 1))
			c += (x[0] == y[1] and (x[1][0] - x[0][0] + 1) == (y[1][1] - y[0][1] + 1)*2)
			c += (x[0] == y[1] and (x[1][0] - x[0][0] + 1)*2 == (y[1][1] - y[0][1] + 1))
			c += (x[1] == y[0] and (x[1][0] - x[0][0] + 1) == (y[1][1] - y[0][1] + 1)*2)
			c += (x[1] == y[0] and (x[1][0] - x[0][0] + 1)*2 == (y[1][1] - y[0][1] + 1))
			c += (x[1] == y[1] and (x[1][0] - x[0][0] + 1) == (y[1][1] - y[0][1] + 1)*2)
			c += (x[1] == y[1] and (x[1][0] - x[0][0] + 1)*2 == (y[1][1] - y[0][1] + 1))

	return c

n = int(input())
for i in range(n):
	r, c = [int(x) for x in input().split()]
	m = []
	for j in range(r):
		m += [(j + 1, k + 1) for k, x in enumerate(input().split()) if x == '1']
	print('Case #%d: %d' % (i + 1, count_l_shapes(m, r, c)))
