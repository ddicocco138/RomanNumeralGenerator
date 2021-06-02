// Damiano DiCocco




#include <iostream>m
#include <string>

using namespace std;

int value(char r)
{
	if (r == 'I') return 1;
	if (r == 'V') return 5;
	if (r == 'X') return 10;
	if (r == 'L') return 50;
	if (r == 'C') return 100;
	if (r == 'D') return 500;
	if (r == 'M') return 1000;

	return -1;
}

int romanToInteger(string& str)
{
	int result = 0;

	for (int i = 0; i < str.length(); i++)
	{
		// One by one converting the letter into integer
		int s1 = value(str[i]);

		if (i + 1 < str.length())
		{
			int s2 = value(str[i + 1]);

			// Comparing both values
			if (s1 >= s2)
			{
				//If value of current symbol is greater
				// or equal to the next symbol
				result = result + s1;
			}
			else
			{
				// Value of current symbol is
				// less than the next symbol
				result = result + s2 - s1;
				i++;
			}
		}
		else
		{
			result = result + s1;
		}
	}
	return result;
}

string integerToRoman(int num)
{
	string m[] = { "", "M", "MM", "MMM" };
	string c[] = { "", "C", "CC", "CCC", "CD", "D","DC", "DCC", "DCCC", "CM" };
	string x[] = { "", "X", "XX", "XXX", "XL", "L","LX", "LXX", "LXXX", "XC" };
	string i[] = { "", "I", "II", "III", "IV", "V","VI", "VII", "VIII", "IX" };

	string thousands = m[num / 1000];
	string hundereds = c[(num % 1000) / 100];
	string tens = x[(num % 100) / 10];
	string ones = i[num % 10];

	return thousands + hundereds + tens + ones;
}




int main()
{
	char r;
	string str = "";
	char menuchoice;
	string romannum = "A";
	int number = 1;
	while (number >= 0)
	{
		cout << "User, Please select one of the following\n ";
		cout << "'A' - Roman to Number \n";
		cout << " 'B' - Number to Roman \n";
		cout << "Please enter your single character choice now \n";
		cin >> menuchoice;

		if (menuchoice == 'A')
		{
			while (str != "-1")
			{
				cout << "Please enter a Roman Numeral to be converted to a Number or -1 to exit : \n";
				cin >> str;
				if (str == "-1")
					break;
				for (int i = 0; i < str.length(); i++)
				{
					if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
					{
						str = "invalid";
					}
				}
				if (str == "invalid")
				{
					cout << "Invalid roman numeral entered! Cannot be converted!\n";
					str = "";
				}
				else if (str != "-1")
					cout << "Integer form of your choosen roman numeral is : " << romanToInteger(str) << endl;
			}
			break;
		}

		if (menuchoice == 'B')
		{
			while (number != -1)
			{
				cout << "Enter an Integer to be converted to Roman Numeral or -1 to exit : \n";
				cin >> number;
				if (number == 0)
					cout << "Roman numerals should be greater than or equal to one!\n";
				else if (number != -1)
					cout << "Roman numeral form of interger : " << integerToRoman(number) << endl;
			}
			break;
		}
		if (menuchoice != 'A' || menuchoice != 'B')
		{
			cout << "Menu Choice invalid, Please try again \n";
			break;
		}
		return 0;
	}
}
