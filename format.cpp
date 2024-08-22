#include <bits/stdc++.h>
#include "testlib.h"
#include "format.h"
using namespace std;
string formatWithRandom(string script, string suffix = "", long long range_l = 1, long long range_r = 1e18) {
	return script + " " + rnd.next(range_l, range_r) + " " + suffix + " > $";
}
string format(string script, string suffix = "") {
	return script + (!suffix.empty() " " : "") + suffix + " > $";
}