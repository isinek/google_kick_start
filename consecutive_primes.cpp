#include <bits/stdc++.h>

#define dump(...)		cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl
#define arr_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) << "): ["; for (unsigned long long int it = 0; it < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]); ++it) cerr << (__VA_ARGS__)[it] << (it + 1 < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) ? ", " : ""); cerr << "]]" << endl
#define vec_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << *it << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl
#define pair_dump(...)		cerr << "[" << #__VA_ARGS__ ": (" << it->first << ", " << it->second << ")]" << endl
#define vec_pair_dump(...)	cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << "(" << it->first << ", " << it->second << ")" << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl

using namespace std;

vector < unsigned long long > primes;

void solution()
{
	unsigned long long z, b, e, i, x, n;
	bool *sieve = NULL;

	scanf("%llu", &z);

	if (primes[primes.size() - 2]*primes.back() < z) {
		n = ((unsigned long long)(sqrt(z)*1.2));
		sieve = (bool *) calloc(n / 2, sizeof(bool));
		for (x = 1; x < primes.size(); ++x) {
			for (i = 3; i*primes[x] < n; ++i) {
				if ((i*primes[x])%2)
					sieve[(i*primes[x])/2] = true;
			}
		}
		for (x = primes.back() + 2; x < n; x += 2) {
			if (!sieve[x/2]) {
				primes.push_back(x);
				for (i = 3; i*x < n; ++i) {
					if ((i*x)%2)
						sieve[(i*x)/2] = true;
				}
			}
		}
		free(sieve);
	}

	e = primes.size();
	b = 1;
	i = e/2;
	while (b < i && i < e) {
		if (primes[i]*primes[i - 1] == z)
			break;
		else if (primes[i]*primes[i - 1] > z)
			e = i;
		else
			b = i;
		i = (e + b)/2;
	}

	printf("%llu\n", primes[i]*primes[i - 1]);

	return;
}

int main()
{
	unsigned int T;

	primes.push_back(2);
	primes.push_back(3);

	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%u: ", i);
		solution();
	}
}
