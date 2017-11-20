#include"stack.h"
#include<cctype>

#define ERROR -999999999
/*(1-2)-2*(2+3)+4*(25/5)
2 * (3 - (5 + 4) / 9)
a + b
(1) + 7
(1 + (8 * 2)
123456*789*/
int infixCal(char s[]) {
	stack<int> opnd;
	stack<char>optr;
	if (s[0] == '-')opnd.push(0);			//Begin with '-'
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ')continue;				//Ignore blanks
		if (isdigit(s[i])) {						//Operand
			int tempNum = 0;
			while (isdigit(s[i])) {
				tempNum *= 10;
				tempNum += s[i++] - '0';
			}
			opnd.push(tempNum);
			tempNum = 0;
			i--;
		}
		else if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {		//Operator
			if (s[i] == ')') {
				if (optr.isEmpty()) {
					cout << "ERROR: Parenthesis Error" << endl;
					return ERROR;
				}
				if (optr.getTop() == '(') {
					optr.pop();
					continue;
				}
				while (optr.getTop() != '(') {
					if (optr.isEmpty()) {
						cout << "ERROR: Parenthesis Error" << endl;
						return ERROR;
					}
					char op = optr.pop();
					int n1, n2;
					if (opnd.isEmpty()) {
						cout << "ERROR: Illegal Expression" << endl;
						return ERROR;
					}
					n1 = opnd.pop();
					if (opnd.isEmpty()) {
						cout << "ERROR: Illegal Expression" << endl;
						return ERROR;
					}
					n2 = opnd.pop();
					switch (op) {
					case '+':
						opnd.push(n2 + n1);
						break;
					case '-':
						opnd.push(n2 - n1);
						break;
					case '*':
						opnd.push(n2*n1);
						break;
					case '/':
						opnd.push(n2 / n1);
						break;
					}
					if (optr.isEmpty()) {
						cout << "ERROR: Parenthesis Error" << endl;
						return ERROR;
					}
				}
				optr.pop();
			}
			else if ((optr.isEmpty() || ((optr.getTop() == '+' || optr.getTop() == '-') && (s[i] == '*' || s[i] == '/')) || s[i] == '(' || optr.getTop() == '('))
				optr.push(s[i]);
			else {
				while (!optr.isEmpty()) {
					char op = optr.pop();
					int n1, n2;
					if (opnd.isEmpty()) {
						cout << "ERROR: Illegal Expression" << endl;
						return ERROR;
					}
					n1 = opnd.pop();
					if (opnd.isEmpty()) {
						cout << "ERROR: Illegal Expression" << endl;
						return ERROR;
					}
					n2 = opnd.pop();
					switch (op) {
					case '+':
						opnd.push(n2 + n1);
						break;
					case '-':
						opnd.push(n2 - n1);
						break;
					case '*':
						opnd.push(n2*n1);
						break;
					case '/':
						opnd.push(n2 / n1);
						break;
					}
				}
				optr.push(s[i]);
			}
		}
		else {			//Illegal
			cout << "ERROR: Illegal Expression" << endl;
			return ERROR;
		}
	}
	while (!optr.isEmpty()) {
		char op = optr.pop();
		if (op == '(') {
			cout << "ERROR: Parenthesis Error" << endl;
			return ERROR;
		}
		int n1, n2;
		if (opnd.isEmpty()) {
			cout << "ERROR: Illegal Expression" << endl;
			return ERROR;
		}
		n1 = opnd.pop();
		if (opnd.isEmpty()) {
			cout << "ERROR: Illegal Expression" << endl;
			return ERROR;
		}
		n2 = opnd.pop();
		switch (op) {
		case '+':
			opnd.push(n2 + n1);
			break;
		case '-':
			opnd.push(n2 - n1);
			break;
		case '*':
			opnd.push(n2*n1);
			break;
		case '/':
			opnd.push(n2 / n1);
			break;
		}
	}
	if (opnd.isEmpty()) {
		cout << "ERROR: Illegal Expression" << endl;
		return ERROR;
	}
	return opnd.pop();
}