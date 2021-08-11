

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;
int math(string sfile1)
{
	ifstream file1(sfile1);
	string S;
	int size=0, j = 0, mid = 0,flag=0;
	double Sum=0;
	while (getline(file1, S))
	{
		Sum = Sum + stod(S);
		size++;
	}
	mid = round(Sum / size);
	int* array = new int[size-1];
	file1.close();
	file1.open(sfile1);
	while (getline(file1, S))
	{
		array[j]=stoi(S);
		j++;
	}
	for (j = 0; j < size; j++) {
		flag = flag + abs(array[j] - mid);
	}
	return flag;
}
int main(int argc, char* argv[])
{
	cout << math(argv[1]);

}