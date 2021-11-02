#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

string strToBinary(string s)
{
    int n = s.length();
    string res = "";
    for (int i = 0; i <= n; i++)
    {
        int val = int(s[i]);
        string bin = "";
        while (val > 0)
        {
            (val % 2) ? bin.push_back('1') :
                bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
        res += bin;
    }
    return res;
}

int main() {
	ifstream input;
	input.open("input.txt");
	string inS;
	while (!input.eof()) {
		string temp;
		getline(input, temp);
        inS += temp + "\n";
	}
    input.close();

	cout << inS << "\n";
    string bin = strToBinary(inS);
    cout << bin << "\n";
    reverse(bin.begin(), bin.end());
    cout << bin << "\n";

    fstream output;
    output.open("output.txt");
    string outS;
    int pos = 0;
    while (!output.eof()) {
        string temp;
        getline(output, temp);
        int spaceAmount = 0;
        while (spaceAmount < 4 && pos<bin.length())
        {
            temp += (bin[pos] == '0') ? " " : "  ";
            spaceAmount += (bin[pos] == '0') ? 1 : 2;
            pos++;
            cout << bin[pos] << " " << ((bin[pos] == '0') ? " " : "  ") << " " << spaceAmount << "\n";
        }
        outS += temp + "\n";
    }
    output.close();
    output.open("output.txt");
    output << outS;
    output.close();
}