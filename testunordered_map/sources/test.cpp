#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;


	string whatTime(int seconds){
		stringstream hour, min, sec;
		hour << (seconds / (60 * 60));
		min << ((seconds % (60 * 60)) / 60);
		sec << (seconds % 60);


  		return hour.str() + ":" + min.str() + ":" + sec.str();

	}

	int main(int argc, char * argv[]){
		int a = 3661;
		cout << whatTime(5436) << endl;
	}
