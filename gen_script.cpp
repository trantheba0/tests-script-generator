#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const string script_destination = "tests-script.txt";
void addTest(string script);
string formatWithRandom(string script, string suffix = "", long long range_l = 1, long long range_r = 1e18);
string formatWithoutRandom(string script, string suffix = "");
string getWaKiller(string script_pattern, string solution_1, string solution_2, int max_test = 1000, string script_suffix = "");
string getTleKiller(string script_pattern, string solution, int max_test = 100, string script_suffix = "");
bool compareResult(string file_1, string file_2, string inp = "");
bool checkSubtask(vector<string> scripts, string solution, vector<string> wa_files);
bool genSubtask(vector<pair<string, int> > scripts, string solution, vector<string> wa_files, 
	string subtaskName = "", int max_test = 1000);

int count_test = 0;
void addTest(string script) {
	++count_test;
	// cerr << script << '\n';
	cerr << "Completed test #" << count_test << '\n';
	cout << script << '\n';
}
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
bool checkSubtask(vector<string> scripts, string solution, vector<string> wa_files) {
	vector<bool> failed(wa_files.size(), 0);
	for (auto &script : scripts) {
		system(script.c_str());
		system(solution.c_str());
		for (int i = 0; i < (int)wa_files.size(); ++i) {
			if (failed[i]) continue;
			string wa_file = wa_files[i];
			system(wa_file.c_str());
			bool ok = !compareResult(solution + ".out", wa_file + ".out");
			if (ok) failed[i] = 1;
		}
	}
	for (int i = 0; i < (int)wa_files.size(); ++i) {
		if (!failed[i]) return 0;
	}
	return 1;
}
bool genSubtask(vector<pair<string, int> > scripts, string solution, vector<string> wa_files, 
	string subtaskName, int max_test) {
	while (max_test--) {
		vector<string> cur;
		for (auto &x : scripts) {
			string script = x.first;
			int num = x.second;
			for (int i = 0; i < num; ++i) {
				cur.push_back(formatWithRandom(script, subtaskName));
			}
		}
		if (checkSubtask(cur, solution, wa_files)) {
			for (auto &script : cur) {
				addTest(script);
			}
			return 1;
		}
	}
	cerr << "Can't generate subtask named " << subtaskName << " with " << max_test << " rounds of generating!\n";
	return 0;
}
signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	#ifdef LOCAL
		freopen(script_destination.c_str(), "w", stdout);
	#endif
	
}