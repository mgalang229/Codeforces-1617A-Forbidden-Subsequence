#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		string t;
		cin >> t;
		// if there are no occurrences of a, b, or c in S, sort S and output it
		// else, if T is not equal to "abc", sort S and output it
		// else, output all a, then all c, then all b, then the rest of the string sorted
		sort(s.begin(), s.end());
		vector<int> counter(26, 0);
		for (auto& e : s) {
			counter[e - 'a']++;
		}
		if (t != "abc" || !counter[0] || !counter[1] || !counter[2]) {
			cout << s;
		} else {
			while (counter[0] > 0) {
				cout << 'a';
				counter[0]--;
			}
			while (counter[2] > 0) {
				cout << 'c';
				counter[2]--;
			}
			while (counter[1] > 0) {
				cout << 'b';
				counter[1]--;
			}
			for (int i = 3; i < 26; i++) {
				while (counter[i] > 0) {
					cout << char('a' + i);
					counter[i]--;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
