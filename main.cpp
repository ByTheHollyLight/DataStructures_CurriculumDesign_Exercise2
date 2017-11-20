#include"utility.h"

int main() {
	char s[100];
	while (cin.getline(s, 100)) {
		int ans = infixCal(s);
		if (ans != ERROR)
			cout << infixCal(s) << endl;
	}
	return 0;
}