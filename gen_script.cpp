#include <bits/stdc++.h>
#include "testlib.h"
#include "checker.h"
#include "format.h"
#include "wa_killer.h"
using namespace std;
const string script_destination = "tests-script.txt";
signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	#ifdef LOCAL
		freopen(script_destination.c_str(), "w", stdout);
	#endif
	
}