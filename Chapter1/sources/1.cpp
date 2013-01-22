#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>

using namespace std;

int uniquestring(char *s){
	int count;
	for(int i = 0; i < strlen(s); i++){
		count = 0;
		for(int j = 0; j < strlen(s); j++){
			s[j] -= s[i];
			if(s[j] == 0)count++;
			s[j] += s[i];
		}
		if(count > 1)return 0;
	}
	return 1;
}

void reversestring(char *s){
	int len = strlen(s);
	char *r = new char(len);
	for(int i = len - 1; i >= 0; i--){
		r[len - i - 1] = s[i];
	}
	delete(s);
	s = r;
}

int checkpermutation1(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int *mark = new int(len1);
	if(len1 != len2)return 0;
	for(int i = 0; i < len1; i++) mark[i] = 0;
	for(int i = 0; i < len1; i ++){
		for(int j = 0; j < len2; j++){
			if(s1[i] == s2[j] && mark[j] == 0){
				mark[j] = 1;
				break;
			}
			return 0;
		}
	}
	return 1;
}

int charcompare(const void *a, const void *b){
	return (*(char *)a - *(char *)b);
}

int checkpermutation2(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if(len1 != len2) return 0;

	char *news1 = new char(len1);
	char *news2 = new char(len2);

	strcpy(news1, s1);
	strcpy(news2, s2);

	qsort(news1, len1, sizeof(char), charcompare);
	qsort(news2, len2, sizeof(char), charcompare);

	return strcmp(news1, news2);
}

void addblank(char *s){
	int len = strlen(s);
	char *r = new char(len);
	for(int i = 0, j =0; i < len && j < len; i++){
		if(s[i] != ' '){
			r[j] = s[i];
			j ++;
		}
		else {
			r[j] = '%';
			r[j + 1] = '2';
			r[j + 2] = '0';
			j += 3;
		}
	}
}


string itoa(int i)
{
    std::string s;
    std::stringstream out;
    out << i;
    s = out.str();
    return s;
}

string stringcompress(char *s){
	string s1 = s;

	stringstream ss;
	char tmp;
	string temp;

	if(s1.length() <= 1)return s1;
    int count = 1;
	string r;
	ss << s[0];
	ss >> temp;
	r = r + temp;

	tmp = s[0];
	cout << "r: " << r << endl;

	for(int i = 1; i < s1.length(); i++){
		if(tmp == s[i])count ++;
		else{
			r = r + itoa(count);
			ss.clear();
			ss << s[i];
			temp.clear();
			ss >> temp;
			r = r + temp;
			count = 1;
			tmp = s[i];
		}
	}
	r = r + itoa(count);
	if(r.length() > s1.length())return s1;
	return r;
}

int main(int argc, char* argv[]){
	stringstream ss;
	string s;
	ss.clear();
	ss << 'a';
	ss.str("");
	ss << 'b';
	ss >> s;
	cout << s << endl;
}
