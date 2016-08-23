#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<char> out;
stack<char> myStack;

int order(char c)
{
	if (c == '*' || c == '/') return 3;
	if (c == '+' || c == '-') return 2;
	if (c == '(') return 1;
	return -1;
}

void polish(const char* s)
{
	while (1)
	{
		while (isspace(*s)) { ++s; }

		if (*s == '\0') // last rows
		{
			while (!myStack.empty())
			{
				out.push_back(myStack.top());
				myStack.pop();
			}
			break;
		}

		// alphabet or digits.
		if (islower(*s) || isdigit(*s))
		{
			out.push_back(*s);
			s++; continue;
		}

		if (*s == '(')
		{
			myStack.push(*s);
		}
		else if (*s == ')')
		{
			// pop until meet (
			while (!myStack.empty())
			{
				char c = myStack.top();
				myStack.pop();
				if (c == '(')
				{
					break;					
				}
				out.push_back(c);
			}
		}
		else
		{
			// operator, check the order.
			while (!myStack.empty() && order(myStack.top()) >= order(*s))
			{
				out.push_back(myStack.top());
				myStack.pop();
			}
			myStack.push(*s);
		}

		s++;
	}	
}

int main()
{
	string input;
	cin >> input;
			
	const char* str = input.c_str();
	out.clear();
	polish(str);
	for (unsigned int i = 0; i < out.size(); ++i)
	{
		cout << out[i];
	}
	cout << endl;
	
    return 0;
}

