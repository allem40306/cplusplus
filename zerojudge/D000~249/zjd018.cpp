﻿#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int n;
	float f;
	char ch;
	string s;
	while (getline(cin, s)){
		stringstream ss(s);
		double ans = 0;
		while (ss >> s){
			int n = 0, lens = s.size(), i, nn = 1, nf = 1;
			double f = 0;
			for (i = 0; i < lens; i++){
				if (s[i] == ':')break;
				if (s[i] == '-'){ nn = -1; continue; }
				n = n * 10 + (s[i] - '0');
			}
			i++;
			for (; i < lens; i++){
				if (s[i] == '.')break;
				if (s[i] == '-'){ nf = -1; continue; }
				f *= 10;
				f += double(s[i] - 48);
			}
			i++;
			for (double m = 0.1; i < lens; i++, m *= 0.1){
				f += (s[i] - '0')*m;
			}
			if (n*nn % 2)ans += nf*f;
			else ans -= nf*f;
		}
		cout << ans << endl;
	}
}