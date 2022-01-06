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
		// sort the given string in lexicographical order
		sort(s.begin(), s.end());
		int n = (int) s.size();
		int m = (int) t.size();
		int id = 0;
		vector<int> counter(26, 0);
		// check if the string t is a subsequence of string s
		// don't forget to count the frequency of the letters present (crucial part)
		for (int i = 0; i < n; i++) {
			if (s[i] == t[id] && id < m) {
				id++;
			}
			counter[s[i] - 'a']++;
		}
		// originally, the answer should be the sorted version of string s (assuming that it is not a subsequence of string t)
		string ans = s;
		// however, if it's the subsequence of string t, then form the string in their alphabetical order and:
		// let m = length of string t
		// interchange the second last character (t[m - 2]) and last character (t[m - 1]) of string t when changing string s
		if (id == m) {
			ans = "";
			for (int i = 0; i < (int) counter.size(); i++) {
				char letter = (char) 97 + i;
				if (letter == t[id - 1]) {
					continue;
				}
				if (letter == t[id - 2]) {
					ans += string(counter[t[id - 1] - 'a'], t[id - 1]);	
				}
				ans += string(counter[i], letter);
			}            
   	}
 		cout << ans << '\n';
	}
	return 0;
}