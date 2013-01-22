#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 2){
		cout << "Have to input the k." << endl;
		return 0;
	}

	ifstream infile;
	infile.open("weather-data.txt");
	if(!infile.good()){
		cout << "Open file error!" << endl;
		return 0;
	}
	int k = atoi(argv[1]), n;
	double sundays = 0, correctcnt = 0, predictioncnt = 0;
	string s;

	n = 1;
	while(n <= k && getline(infile, s) ){
		n ++;
		if(!s.compare("sun"))sundays++;
	}
	while(getline(infile, s)){
		if(!s.compare("sun")){
			if(sundays > (k - sundays)){
				correctcnt ++;
			}
			sundays ++;
		}
		else{
			if(sundays <= (k - sundays)){
				correctcnt ++;
			}
		}
		k ++;
		predictioncnt ++;
	}
	infile.close();
	cout << (correctcnt / predictioncnt) << endl;
	return 1;
}
