#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "rus");
	int j = 0;
	stack<char> st;
	string str;
	cout << "Введите строку данных: ";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			st.push(str[i]);
		}
		if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			if (st.empty())
			{
				j = -1; break;
			}
			else
			{
				{
					char top = st.top(); 
					st.pop();
					if ((str[i] == '}' && top != '{') ||
						(str[i] == ')' && top != '(') ||
						(str[i] == ']' && top != '[')) {
						j = -1;
						break;
					}
				}
			}
		}
	}
	if (st.empty() && j!=-1)
	{
		cout << "скобки расставлены верно";
	}
	else
		if (!st.empty() || j == -1) { cout << "скобки расставлены не верно"; }
	return 0;
}