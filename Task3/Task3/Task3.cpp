#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
void LenIdVec(int &len, string file)
{
	int f;
	string S;
	ifstream in(file);
	while (getline(in, S)) {
		f=S.find("id");
		if (f != std::string::npos)
		{
			len = len + 1;
		}
	}
	in.close();
}
void CreateIdVec(int len, vector<int> &vecid,vector<bool> &vecval, string file)
{
	int f,i,valb1,valb2;
	i = 0;
	string S,S2;
	ifstream in(file);
	while (getline(in, S)) {
		f = S.find("id");
		if (f != std::string::npos)
		{
			valb1 = S.find(":");
			valb2 = S.find(",");
			S2 = S.substr(valb1 + 2, valb2 - valb1 - 2);
			vecid[i] = stoi(S2);
			getline(in, S);
			valb1 = S.find(":");
			valb2 = S.find("\n");
			S2 = S.substr(valb1 + 2, valb2 - valb1 - 3);
			if (S2 == "\"passed\"" )
			{
				vecval[i] = true;
			}
			else
			{
				vecval[i] = false;
			}

			i++;
		}
	}
	in.close();
}
void RepFill(int len,string infile, string outfile, vector<int> vecid, vector<bool> vecval)
{
	int id,f, valb1, valb2;
	int idindex = 0;
	bool flag;
	string S,S2,S3;
	ifstream in(infile);
	ofstream out(outfile);
	while (getline(in, S)) {
		f = S.find("id");
		if (f != std::string::npos)
		{
			out << S << "\n";
			valb1 = S.find(":");
			valb2 = S.find(",");
			id = stoi(S.substr(valb1 + 2, valb2 - valb1 - 2));
			flag = false;
			
			for (int i = 0; i < len; i++)
			{
				if (vecid[i] == id)
				{
					idindex = i;
					flag = true;
				}
			}
			if (flag == true)
			{
				getline(in, S);
				out << S << "\n";
				getline(in, S);
				valb1 = S.find(":");
				valb2 = S.find("\n");
				if (vecval[idindex] == true)
				{
					S3 = "\"passed\"";
				}
				else
				{
					S3 = "\"failed\"";
				}
				S2 = S.substr(0, valb1 + 1) + S3;
				f = S.find(",");
				if (f != std::string::npos)
				{
					S2 = S2 + ",";
				}
				
			}
			else
			{
				getline(in, S);
				S2 = S;
			}

		}
		else
		{
			S2 = S;
		}
		out << S2 << "\n";

	}
	in.close();
	out.close();
}
int main(int argc, char* argv[])
{
	int len=0;
	vector<int> vecid;
	vector<bool> vecval;
	LenIdVec(len, argv[2]);
	vecid.resize(len);
	vecval.resize(len);
	CreateIdVec(len, vecid,vecval, argv[2]);
	RepFill(len, argv[1], "report.json", vecid, vecval);

	


}

//CreateIdMas