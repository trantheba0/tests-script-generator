#include <bits/stdc++.h>
#include "checker.h";
using namespace std;
bool compareResult(string file_1, string file_2, string inp = "") {
	ifstream f_1(file_1), f_2(file_2);
	long long ans_1, ans_2;
	while (f_1 >> ans_1) {
		f_2 >> ans_2;
		// cerr << ans_1 << ' ' << ans_2 << '\n';
		if (ans_1 != ans_2) return 0;
	}
	f_1.close();
	f_2.close();
	return 1;
}