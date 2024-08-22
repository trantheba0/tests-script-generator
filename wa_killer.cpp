#include <bits/stdc++.h>
#include "checker.h"
#include "format.h"
string getWaKiller(string script_pattern, string script_suffix, string solution_1, string solution_2) {
	bool ok = 0;
	string script_result = "";
	do {
		script_result = formatWithRandom(script_pattern, script_suffix);
		system(script_result);
		system(solution_1);
		system(solution_2);
		ok = !compareResult(solution_1 + ".out", solution_2 + ".out");
	} while (!ok);
	return script_result
}