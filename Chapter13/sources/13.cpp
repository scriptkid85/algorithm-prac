/*
 * 13.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: gavin
 */


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdio.h>


using namespace std;

class Person{
//default members are all private;
	int id;
	string name;

public:

	void func(int a = 1, int b = 3){
		cout << a + b << endl;
	}

	void printid(){
		cout << id << endl;
	}


	virtual void aboutMe(){
		cout << "I am a person." << endl;
	}
	virtual bool addcourse(string s){
		cout << "person adds course." << endl;
	}
	virtual ~Person(){
		cout << "deleting person." << endl;
	}
};

class Student: public Person{
public:

	void aboutMe(){
		cout << "I am a student" << endl;
	}
	bool addcourse(string s){
		cout << "student adds course." << endl;
		return true;
	}
	~Student(){
		cout << "deleting student." << endl;
	}
};

class AStudent: public Student{
public:
	~AStudent(){
		cout << "deleting Astudent." << endl;
	}
};

void readklines(int k, char *inputfile){
	ifstream infile;
	string s[k];
	string temp;
	infile.open(inputfile);

	cout << inputfile << endl;
	if(!infile.good()){
		cout << "open file error!" << endl;
		return;
	}
	int i = 0;
	while(getline(infile, temp)){
		if(temp != ""){
			s[i] = temp;
			i = (i + 1) % k;
		}
	}
	int j = 0;
	while(j < k){
		cout << s[(i ++) % k] << endl;
		j ++;
	}
}

//(9)

void *aligned_malloc(size_t requiredbits, size_t alignment){
	size_t offset = alignment + 1 + sizeof(void *);
	void *p;
	void **q;
	if ((p = (void *)malloc(requiredbits + offset)) == NULL){
		return NULL;
	}
	q = (void **)(((size_t)p + offset) & ~(alignment - 1));
	q[-1] = p;
	return q;
}

void aligned_free(void *p){
	void *q  = ((void **)p)[-1];
	free(q);
}

class Test{
public:
	char *ptr;
	Test(char *s){
		ptr = s;
	}
};

void shallowcopy(Test &source, Test &dest){
	dest.ptr = source.ptr;
}

void deepcopy(Test &source, Test &dest){
	dest.ptr = (char *)malloc(sizeof(source.ptr) + 1);
	memcpy(dest.ptr, source.ptr, sizeof(source.ptr) + 1);
}

int main(){
	int a[2] = {-1};
	fill_n(a, 2, -2);
	char b[2] = {'a'};
	fill_n(b, 2, 'b');
	cout << *(a) << endl;
	cout << *(a + 1) << endl;
	cout << *(b) << endl;
	cout << *(b + 1) << endl;


}
