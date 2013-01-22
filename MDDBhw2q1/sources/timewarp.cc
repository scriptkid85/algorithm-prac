#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#define MAX_NUM 20000

using namespace std;
// Please implement your code here


long int DTW(FILE* f1, FILE* f2){

	int n1, n2, last, prev;
	int s1[MAX_NUM], s2[MAX_NUM];
	long int Dist[2][MAX_NUM];


	fscanf(f1, "%d", &n1);
	fscanf(f2, "%d", &n2);

	int i, j;

	for(i = 0; i < 2 ; i ++)
		for(j = 0; j < n2 + 1; j++)
			Dist[i][j] = 0;

	for(i = 1; i <= n1; i++){
		fscanf(f1, "%d", &s1[i]);
	}
	for(i = 1; i <= n2; i++){
		fscanf(f2, "%d", &s2[i]);
	}

    Dist[0][0] = 0;
	for(i = 1; i <= n2; i++){
		Dist[0][i] = Dist[0][i - 1] + abs(s1[1] - s2[i]);
	}

	last = 0;
	prev = 0;
	for(i = 1; i <= n1; i++){
		last = 1 - last;
	    prev = 1 - last;

	    Dist[last][1] = Dist[prev][1] + abs(s1[i] - s2[1]);

	    for(j = 2; j <= n2; j++){
			long int tempmin = Dist[prev][j - 1];
			if(Dist[prev][j - 1] > Dist[last][j - 1])
				tempmin = Dist[last][j - 1];
			if(tempmin > Dist[prev][j])
				tempmin = Dist[prev][j];
			Dist[last][j] = abs(s1[i] - s2[j]) + tempmin;

	    }
	}
	return Dist[last][n2];
}

int main(int nargs, char* args[]) {
	FILE* f1;
	FILE* f2;
	char* filename[10];
	int i, j;

	filename[0] = "0001.dat";
	filename[1] = "0002.dat";
	filename[2] = "0003.dat";
	filename[3] = "0004.dat";
	filename[4] = "0005.dat";
	filename[5] = "0006.dat";
	filename[6] = "0007.dat";
	filename[7] = "0008.dat";
	filename[8] = "0009.dat";
	filename[9] = "0010.dat";

	long int record[10][10];
	long int Minpairs = 1000000000;
	for(i = 0; i < 9; i++){
	  for(j = i + 1; j <= 9; j++){
		  if(!(f1 = fopen(filename[i], "r"))){
			  cout << "Cannot find the first file" << endl;
			  return 0;
			}

		  if(!(f2 = fopen(filename[j], "r"))){
			  cout << "Cannot find the second file" << endl;
			  return 0;
			}


		  record[i][j] = DTW(f1, f2);
		  if(Minpairs > record[i][j])Minpairs = record[i][j];
	  }
	}




	FILE* output;
	output = fopen("hw2.q1.output.txt", "w");
	for(i = 0; i < 9; i++)
	for(j = i + 1; j <= 9; j ++){
		if(record[i][j] == Minpairs)
			fprintf(output, "%s %s %ld\n", filename[i], filename[j], record[i][j]);
	}

	return 0;
}
