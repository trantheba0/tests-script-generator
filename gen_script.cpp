#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const string script_destination = "tests-script.txt";
string formatWithRandom(string script, string suffix = "", long long range_l = 1, long long range_r = 1e18);
string formatWithoutRandom(string script, string suffix = "");
string getWaKiller(string script_pattern, string solution_1, string solution_2, int max_test = 1000, string script_suffix = "");
string getTleKiller(string script_pattern, string solution, int max_test = 100, string script_suffix = "");
bool compareResult(string file_1, string file_2, string inp = "");

string formatWithRandom(string script, string suffix, long long range_l, long long range_r) {
	return script + " " + to_string(rnd.next(range_l, range_r)) + " " + suffix + " > $";
}
string formatWithoutRandom(string script, string suffix) {
	return script + (!suffix.empty()? " " : "") + suffix + " > $";
}
string getWaKiller(string script_pattern, string solution_1, string solution_2, int max_test, string script_suffix) {
	bool ok = 0;
	string script_result = "";
	do {
		script_result = formatWithRandom(script_pattern, script_suffix);
		system(script_result.c_str());
		system(solution_1.c_str());
		system(solution_2.c_str());
		ok = !compareResult(solution_1 + ".out", solution_2 + ".out");
	} while (!ok && --max_test);
	return (ok? script_result : "");
}
string getTleKiller(string script_pattern, string solution, int max_test, string script_suffix) {
	return "";
}
bool compareResult(string file_1, string file_2, string inp) {
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
signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	#ifdef LOCAL
		freopen(script_destination.c_str(), "w", stdout);
	#endif

}