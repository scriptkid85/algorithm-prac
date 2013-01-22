#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <math.h>
// Please implement your code here

using namespace std;

typedef struct surface{
	double x1;
	double y1;
	double z1;
	double x2;
	double y2;
	double z2;
	double x3;
	double y3;
	double z3;
	double x4;
	double y4;
	double z4;
}Sur;

typedef struct myvector{
	double x;
	double y;
	double z;
}Vec;

queue<Sur> surfaces;

Vec GeneVec(double x, double y, double z){
	Vec v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

Vec NormalizeDirec(Vec v){
	Vec result = GeneVec(0, 0, 0);
	if(v.x != 0)
		if(v.x > 0)result.x = 1;
		else result.x = -1;
	else if(v.y != 0)
		if(v.y > 0)result.y = 1;
		else result.y = -1;
	else if(v.z != 0)
		if(v.z > 0)result.z = 1;
		else result.z = -1;

	return result;
}

Vec Xproduct(Vec a, Vec b){
	Vec result;
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;

	Vec Nresult = NormalizeDirec(result);

	return Nresult;
}

Sur GeneSurwithVec(Vec a, Vec b, Vec c, Vec d){
	Sur s;
	s.x1 = a.x;
	s.y1 = a.y;
	s.z1 = a.z;
	s.x2 = b.x;
	s.y2 = b.y;
	s.z2 = b.z;
	s.x3 = c.x;
	s.y3 = c.y;
	s.z3 = c.z;
	s.x4 = d.x;
	s.y4 = d.y;
	s.z4 = d.z;
	return s;
}

Vec GeneVecwithVec(Vec v1, double scaler1, Vec v2, double scaler2){
	Vec v;
	v.x = scaler1 * v1.x + scaler2 * v2.x;
	v.y = scaler1 * v1.y + scaler2 * v2.y;
	v.z = scaler1 * v1.z + scaler2 * v2.z;
	return v;
}

void printsur(Sur s){
	printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", s.x1,\
		  s.y1, s.z1, s.x2, s.y2,\
		  s.z2, s.x3, s.y3, s.z3, s.x4, s.y4, s.z4);

}


void DivideSur(Sur s){
	Vec a, b, direction;
	//compute the direction with right-hand rule
	a.x = s.x2 - s.x1;
	a.y = s.y2 - s.y1;
	a.z = s.z2 - s.z1;
	b.x = s.x3 - s.x1;
	b.y = s.y3 - s.y1;
	b.z = s.z4 - s.z1;
	direction = Xproduct(b, a);
	double edgelength = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);

	Vec base1 = GeneVec(s.x2 - s.x1, s.y2 - s.y1, s.z2 - s.z1);
	Vec base2 = GeneVec(s.x4 - s.x1, s.y4 - s.y1, s.z4 - s.z1);
	Vec base0 = GeneVec(0, 0, 0);
	Vec base = GeneVec(s.x1, s.y1, s.z1);


	Vec v0 = GeneVecwithVec(base1, 1.0, base0, 0.0);
	Vec V0 = GeneVecwithVec(base, 1.0, v0, 1.0);
	Vec v1 = GeneVecwithVec(base1, 1.0, base2, 1.0/3.0);
	Vec V1 = GeneVecwithVec(base, 1.0, v1, 1.0);
	Vec v2 = GeneVecwithVec(base1, 1.0, base2, 2.0/3.0);
	Vec V2 = GeneVecwithVec(base, 1.0, v2, 1.0);
	Vec v3 = GeneVecwithVec(base1, 1.0, base2, 1.0);
	Vec V3 = GeneVecwithVec(base, 1.0, v3, 1.0);
	Vec v4 = GeneVecwithVec(base1, 2.0/3.0, base0, 0.0);
	Vec V4 = GeneVecwithVec(base, 1.0, v4, 1.0);
	Vec v5 = GeneVecwithVec(base1, 2.0/3.0, base2, 1.0/3.0);
	Vec V5 = GeneVecwithVec(base, 1.0, v5, 1.0);
	Vec v6 = GeneVecwithVec(base1, 2.0/3.0, base2, 2.0/3.0);
	Vec V6 = GeneVecwithVec(base, 1.0, v6, 1.0);
	Vec v7 = GeneVecwithVec(base1, 2.0/3.0, base2, 1.0);
	Vec V7 = GeneVecwithVec(base, 1.0, v7, 1.0);
	Vec v8 = GeneVecwithVec(base1, 1.0/3.0, base0, 0.0);
	Vec V8 = GeneVecwithVec(base, 1.0, v8, 1.0);
	Vec v9 = GeneVecwithVec(base1, 1.0/3.0, base2, 1.0/3.0);
	Vec V9 = GeneVecwithVec(base, 1.0, v9, 1.0);
	Vec v10 = GeneVecwithVec(base1, 1.0/3.0, base2, 2.0/3.0);
	Vec V10 = GeneVecwithVec(base, 1.0, v10, 1.0);
	Vec v11 = GeneVecwithVec(base1, 1.0/3.0, base2, 1.0);
	Vec V11 = GeneVecwithVec(base, 1.0, v11, 1.0);
	Vec v12 = GeneVecwithVec(base0, 0.0, base0, 0.0);
	Vec V12 = GeneVecwithVec(base, 1.0, v12, 1.0);
	Vec v13 = GeneVecwithVec(base0, 0.0, base2, 1.0/3.0);
	Vec V13 = GeneVecwithVec(base, 1.0, v13, 1.0);
	Vec v14 = GeneVecwithVec(base0, 0.0, base2, 2.0/3.0);
	Vec V14 = GeneVecwithVec(base, 1.0, v14, 1.0);
	Vec v15 = GeneVecwithVec(base0, 0.0, base2, 1.0);
	Vec V15 = GeneVecwithVec(base, 1.0, v15, 1.0);

	Sur S[13];
	S[0] = GeneSurwithVec(V4, V0, V1, V5);
	S[1] = GeneSurwithVec(V5, V1, V2, V6);
	S[2] = GeneSurwithVec(V6, V2, V3, V7);
	S[3] = GeneSurwithVec(V8, V4, V5, V9);
	S[4] = GeneSurwithVec(V10, V6, V7, V11);
	S[5] = GeneSurwithVec(V12, V8, V9, V13);
	S[6] = GeneSurwithVec(V13, V9, V10, V14);
	S[7] = GeneSurwithVec(V14, V10, V11, V15);

	for(int i = 0; i < 8; i++)
		surfaces.push(S[i]);


	Vec V16 = GeneVecwithVec(V9, 1.0, direction, edgelength/3.0);
	Vec V17 = GeneVecwithVec(V5, 1.0, direction, edgelength/3.0);
	Vec V18 = GeneVecwithVec(V6, 1.0, direction, edgelength/3.0);
	Vec V19 = GeneVecwithVec(V10, 1.0, direction, edgelength/3.0);

	S[8] = GeneSurwithVec(V16, V17, V18, V19);
	S[9] = GeneSurwithVec(V5, V17, V16, V9);
	S[10] = GeneSurwithVec(V9, V16, V19, V10);
	S[11] = GeneSurwithVec(V10, V19, V18, V6);
	S[12] = GeneSurwithVec(V6, V18, V17, V5);

	for(int i = 8; i < 13; i++)
		surfaces.push(S[i]);

}

int main(int nargs, char* args[]) {

  int numsurtodivide;
  if(nargs > 2){
	  cout << "Error: there are more than one input argument." <<endl;
  }
  int n = strtol(args[1], NULL, 10);

  Vec K1v1 = GeneVec(0, 0, 0);
  Vec K1v2 = GeneVec(0, 1, 0);
  Vec K1v3 = GeneVec(1, 1, 0);
  Vec K1v4 = GeneVec(1, 0, 0);

  Sur firstsur = GeneSurwithVec(K1v1, K1v2, K1v3, K1v4);
  surfaces.push(firstsur);
  double rounds = 0;
  Sur surtodivide;
  while(rounds < n){
	  numsurtodivide = pow(13.0, rounds);
	  int i = 0;
	  while(i < numsurtodivide && (!surfaces.empty())){
		  surtodivide = surfaces.front();
		  surfaces.pop();
		  DivideSur(surtodivide);
		  i ++;
	  }
	  rounds ++;
  }

  //output K_n
  FILE* f = fopen("output.txt", "w");
  fprintf(f, "%d\n", (int)pow(13.0, n));
  Sur surtooutput;
  while(!surfaces.empty()){
	  surtooutput = surfaces.front();
	  surfaces.pop();
	  fprintf(f, "%lf %lf %lf\n%lf %lf %lf\n%lf %lf %lf\n%lf %lf %lf\n", surtooutput.x1,\
			  surtooutput.y1, surtooutput.z1, surtooutput.x2, surtooutput.y2,\
			  surtooutput.z2, surtooutput.x3, surtooutput.y3, surtooutput.z3, surtooutput.x4, surtooutput.y4, surtooutput.z4);

	  }
  fclose(f);
  return 0;
}
