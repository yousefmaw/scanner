#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int currnet1(char s, string &ou, int &current, int &last, ofstream &outfile);
int currnet2(char s, string &ou, int &current, int &last, ofstream &outfile);
int currnet3(char s, string &ou, int &current, int &last, ofstream &outfile);
int currnet4(char s, string &ou, int &current, int &last, ofstream &outfile);
int currnet5(char s, string &ou, int &current, int &last, ofstream &outfile);
int output(char s, string &ou, int &current, int &last, ofstream &outfile);
int main()
{
	ifstream infile;
	infile.open("tiny_sample_code.txt");
	ofstream outfile;
	outfile.open("scanner_output.txt");
	if (infile.fail())
	{
		cout << "error";
		return 0;
	}
	else
	{
		char s; string ou = ""; int current = 1; int next; int last=1;
		while (infile.get(s)) 
		{
			if (current == 1)
			{
				next = currnet1(s,ou,current,last,outfile);
			}
			if (current == 2)
			{
				next = currnet2(s, ou, current, last, outfile);
			}
			if (current == 3)
			{
				next = currnet3(s, ou, current, last, outfile);
			}
			if (current == 4)
			{
				next = currnet4(s, ou, current, last, outfile);
			}
			if (current == 5)
			{
				next = currnet5(s, ou, current, last, outfile);
			}
			current = next;
		}
		output(s,ou,current,last, outfile); //the loop finishes without printing the last statment
	}
	outfile.close();
	infile.close();
	return 0;
}
int currnet1(char s, string &ou, int &current, int &last, ofstream &outfile)
{
	if (s == ' ')
	{
		return 1;
	}
	if (s == '{')
	{
		
		return 2;
	}
	if (48 <= s && s <= 57)
	{
		
		ou = ou + s;
		return 3;
	}
	if ((65 <= s && s <= 90) || (97 <= s && s <= 122))
	{
	
		ou = ou + s;
		return 4;
	}
	if (s == ':')
	{
		
		ou = ou + s;
		return 5;
	}
	if (s == '\n' )
	{

		return 1;
	}
	else
	{
		ou = ou + s;
		last = 1;
		return output(s,ou, current, last, outfile);

	}
}
int currnet2(char s, string &ou, int &current, int &last, ofstream &outfile)
{
	if (s == '}')
	{
		return 1;
		
	}
	else
	{
		return 2;
	}
}
int currnet3(char s, string &ou, int &current, int &last, ofstream &outfile)
{
	
	if (48 <= s && s <= 57)
	{

		ou = ou + s;
		return 3;
	}
	else
	{
		last = 3;
		 
		 return  output(s, ou, current, last, outfile);
	}
}
int currnet4(char s, string &ou, int &current, int &last, ofstream &outfile)
{

	if ((65 <= s && s <= 90) || (97 <= s && s <= 122))
	{

		ou = ou + s;
		return 4;
	}
	else
	{
		last = 4;
		
		return  output(s, ou, current, last, outfile);
	}
}
int currnet5(char s, string &ou, int &current, int &last, ofstream &outfile)
{

	if (s == '=')
	{
		last = 5;
		ou = ou + s;
		return output(s,ou,current,last,outfile);
	}
}
int output(char s,string &ou, int &current, int &last, ofstream &outfile)
{
	
		if (last == 1)
		{
			outfile << ou << " : special symbol" << endl;
			ou = "";
			return 1;
		}
		if (last == 3)
		{
			outfile << ou << " : number" << endl;
			ou = "";
		}
		if (last == 4)
		{

			if (ou == "if" || ou == "then" || ou == "else" || ou == "end" || ou == "repeat" || ou == "until" || ou == "read" || ou == "write")
			{
				outfile << ou << " : reserved word" << endl;
			}
			else
			{
				outfile << ou << " : identifier" << endl;
			}

			ou = "";
		}
		if (last == 5)
		{
			outfile << ou << " : special symbol" << endl;
			ou = "";
			return 1;
		}
		return currnet1(s, ou, last, current, outfile);
}