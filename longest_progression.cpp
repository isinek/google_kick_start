#include <bits/stdc++.h>

#define dump(...)		cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl
#define arr_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) << "): ["; for (unsigned long long int it = 0; it < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]); ++it) cerr << (__VA_ARGS__)[it] << (it + 1 < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) ? ", " : ""); cerr << "]]" << endl
#define vec_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << *it << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl
#define pair_dump(...)		cerr << "[" << #__VA_ARGS__ ": (" << it->first << ", " << it->second << ")]" << endl
#define vec_pair_dump(...)	cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << "(" << it->first << ", " << it->second << ")" << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl

using namespace std;

void solution()
{
	unsigned long long n, prev = ~0, a, max_dist = 0;
	long long diff;
	vector < pair < long long, unsigned long long > > arr;
	bool used_switch = false;

	scanf("%llu", &n);
	for (unsigned long long i = 0; i < n; ++i) {
		scanf("%llu", &a);
		diff = a;
		diff -= prev;

		if (prev == ~0) {
			prev = a;
			continue;
		} else if (arr.empty()) {
			arr.emplace_back(diff, 2);
		} else if (diff == arr.back().first) {
			++arr.back().second;
			if (arr.back().second > max_dist) {
				max_dist = arr.back().second;
				used_switch = false;
			}
		} else {
			arr.emplace_back(diff, 2);
			if (arr.size() > 3 && arr[0].first == arr[3].first && max_dist <= arr[0].second + arr[3].second && arr[1].second == 2 && arr[2].second == 2) {
				max_dist = arr[0].second + arr[3].second + 1;
				used_switch = true;
			}
			if (arr.size() > 4) {
				arr.erase(arr.begin());
			}
		}

		prev = a;
	}

	if (arr.size() > 3 && arr[0].first == arr[3].first && max_dist <= arr[0].second + arr[3].second && arr[1].second == 2 && arr[2].second == 2) {
		max_dist = arr[0].second + arr[3].second + 1;
	} else if (arr.size() > 1 && !used_switch) {
		++max_dist;
	}
	vec_pair_dump(arr);

	printf("%llu\n", max_dist);

	return;
}

int main()
{
	unsigned int T;

	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%u: ", i);
		solution();
	}
}
