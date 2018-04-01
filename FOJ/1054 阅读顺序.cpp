#include<iostream>
#include<string>
using namespace std;

int main()
{
	string letter;
	int N;
	
	cin >> N;
	cin.get();
	
	while (N--)
	{
		getline(cin,letter);
		
		int len = letter.size();
		
		for (int i = len - 1; i >= 0; i--)
		{
			cout << letter[i];
		}
		cout << endl;	
	}
	
	return 0;
}
