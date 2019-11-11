/*
Sam_S 
Binary Gap Count in c++
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string addBits(long long b)
{
	stringstream ss;

	ss << b;
	string aB;
	ss >> aB;

	if (b > 11111111) {
		int stringlength = aB.length();
		for (int i = 0; i < 12 - stringlength; i++)
		{
			aB = "0" + aB;
		}
	}
	else if (b > 1111) 
	{
		int stringlength = aB.length();
		for (int i = 0; i < 8 - stringlength; i++)
		{
			aB = "0" + aB;
		}
	}
	else 
	{
		int stringlength = aB.length();
		for (int i = 0; i < 4 - stringlength; i++)
		{
			aB = "0" + aB;
		}
	}
	return aB;

}

vector<int> Binbin(int n){
	
	// converts to binary
	vector<int> a;
	  if (n == 0) {
		  a.push_back(0);
		  return a;
	  }
	  else 
	for (int i = 0; n > 0; i++) {
		i = n % 2;
		a.push_back(i);
		n = n / 2;
	  }
	  return a;
}

vector<int> gapCount(string e) 
{
	// o counts the ones and z counts the zeros,  
	// e is the binary converted, added bit integer originally entered
	// f is the element id.
	// copy() takes the string d, from e, and places it in a vector.
	
	
	int f = 0; int o = 0; int z = 0;
	string d = e;
	vector<char> v1(d.length());
	copy(d.begin(),d.end(),v1.begin());
	vector<int> v2;
	while ( f < v1.size())
	{
		if (v1.at(f) == '1')
		{
			o++;
		}
		if (o > 0 && v1.at(f) == '0')
		{
			z++;
		}
		if (o >= 2 && z >= 1)
		{
			v2.push_back(z);
			z = 0;
			o= 1;

		}
		if (o > 1 && z < 1)
		{
			o--;
		}
		f++;
	}
	if (v2.size() == 0) {
		v2.push_back(0);
		return v2;
	}
	
	//returns the gaps' amount
	return v2;
	
}

int mAx(vector<int> w) {
	
	// returns the larger gap
	
	vector<int> x = w;
	int max = x.at(0);
	int y = x.size();
	for (int z = 1; z < y; z++)
	{

		if (x.at(z) > max)
		{
			max = x.at(z);
		}
	}
	return max;
}

int main()
{
	
	cout << "***:::Binary Gap Counter:::***";
	int enter = 0;
	
	while (enter >= 0) {
		cout << "\n\nPlease enter an NEW integer: ";
		
		vector<int> bin;
		vector<int> p;
		cin >> enter;
		
		if (enter<0) { cout << "\n\nThank you!\n\n"; break; } // enter a negative number to exit loop/program

		bin = Binbin(enter);
				
		long long result;
		int l = bin.size();
		
		stringstream tt;
		for (int i = l-1; i >= 0; i--) {
			tt << bin.at(i);
		}
		tt >> result;
		
		cout << "Binary Format: \n"<<result<<endl;
			
		cout << "\nFormatted to 4, 8, or 12 bit: \n";
		cout<< addBits(result);
					
		string v = addBits(result);
		
		p = gapCount(v);// <-----was Causing Error
			
		cout << "\nBinary Gaps: ";
		int q = p.size();
		for (int i = 0; i < q;i++) {
			cout << p.at(i);
			if (i != q - 1) {
			cout << ",";
		  }
		}
			 
		cout << "\nMaximum Gap: " << mAx(p);
	}

	return 0;
}
