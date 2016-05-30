#inclue <iostream>
using namespace std;

void solve(char *s) {
	*s++ = 'a';
}

int main() {
	char s[10] = "0123456789";
	solve(s);
	cout << s << endl;
	return 0;
}