

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
int pointCir(double PX,double PY,double CX,double CY,double R)
{
	double dist;
	dist = sqrt(pow((PX - CX), 2) + pow((PY - CY), 2));
	if (dist > R)
		return 2;
	if (dist == R)
		return 0;
	return 1;
}
void cordRead(string s,double& X, double& Y)
{
	int flag;
	flag = s.find(' ');
	X = stod(s.substr(0, flag));
	Y = stod(s.substr(flag + 1, s.length() - 1));
	return;
}
void math(string sfile1, string sfile2)
{
	double CX, CY, R, PX, PY;
	ifstream file1(sfile1), file2(sfile2);
	string S;
	getline(file1, S);
	cordRead(S, CX, CY);
	getline(file1, S);
	R = stod(S);
	file1.close();
	while (getline(file2, S)) {
		cordRead(S, PX, PY);
		cout << pointCir(PX,PY,CX,CY,R) << "\n";
		
	}
	file2.close();

}
int main(int argc, char* argv[])
{
	math(argv[1], argv[2]);

}


