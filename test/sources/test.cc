#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int main(){

	ifstream fin("d1.txt");
	string s;
	while( fin >> s )
	{
		cout << "Read from file: " << s << endl;
	}
	getchar();
	getchar();
}
