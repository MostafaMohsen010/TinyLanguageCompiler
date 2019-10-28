
#include<stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include "TOKEN.CPP"

using namespace std;



int main() {

	string str = "aa bb cc ;   ;";
	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

	TokenRecord t(IF);
	
	cout << str;

	int d; cin >> d;
	return 0;
}