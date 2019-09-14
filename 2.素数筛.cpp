#include <iostream>
using namespace std;
#define max_n 100

int prime[max_n] = {0};

int main() {
	for (int i = 2; i < max_n; i++) {
		if (prime[i]) continue;
		prime[++prime[0]] = i;
		for (int j = i * i; j < max_n; j += i) {
			prime[j] = 1;
		}
	}
	for (int i = 1; i <= prime[0]; i++) {
		cout << prime[i] << endl;
	}
	
}
