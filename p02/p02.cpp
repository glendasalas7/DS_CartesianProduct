#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

vector<string> sort(istream& i1){	
	int size = 0;
	vector<string> temp;
	vector<string> temp2;
	string read = "";
	string word = "";
	char last = 'z';
	char x;
		while(getline(i1, read)){
		for(int i = 0; i < read.size(); i++){
			x = read.at(i); //gets x
			if(x != ' '){//if x isnt white space
				word.append(1u, x);//adds to string
			}
			else if(x == ' ' &&  last != ' '){
				temp.push_back(word);
				word = "";
			}
			last = x;
			}
		}

	for(int i = 0; i < temp.size(); i++){
		for(int j = i+1; j < temp.size(); j++){
			if(temp[i] == temp[j]){
				temp.erase(temp.begin() + j);
			}
		}
	}

	return temp;
	}

int main(int argc, char* argv[]){
		ifstream i1;
		ifstream i2;
		ofstream out;
		i1.open(argv[1]);
		i2.open(argv[2]);
		out.open(argv[3]);

		string read = "";
		int size = 0;
		vector<string> A;
		vector<string> B;

		A = sort(i1);
		B = sort(i2);

		out <<"A = {";
		for(int i =0; i < A.size(); i++){
			if(i == A.size()-1){
				out << A[i];
			}else
			out << A[i] << ", ";
		}
		out << "}" << endl;

		out <<"B = {";
		for(int i = 0; i < B.size(); i++){
			if(i == B.size()-1){
				out<< B[i];
			}else
			out<< B[i] << ", ";
		}
		out<< "}" << endl<<endl;

		out<<"AxB = { ";
		for(int i = 0; i < A.size(); i++){
			if(i > 0) out<< "	";
			for(int j = 0; j < B.size(); j++){
				if(j == B.size()-1){
					out<< "(" << A[i] <<", " << B[j] << ")";
				}else
					out<< "(" << A[i] <<", " << B[j] << "),  ";
			}
			out << endl;
		}
		out<<"	}"<<endl;

		cout<<"Wrote output to 'result.txt'"<<endl;
		if (i1.is_open()){
			i1.close();
			i2.close();
			out.close();
		}
		else {
		cout << "Unable to open input file(s)." << endl;
		}
}