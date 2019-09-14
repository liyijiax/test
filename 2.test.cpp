#include <iostream>
using namespace std;

void init_priem() {};

int prime(int x) {
	if (x <= 1) return 1;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		return 1;
	}
	return 0;
}


int main() {
	init_prime();
	int x;
	while (~scanf("%d", &x)) {
		printf("%s\n", prime(x) ? "NO" : "YES");
	}
	return 0;
}
