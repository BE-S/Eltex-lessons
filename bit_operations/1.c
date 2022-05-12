#include "stdio.h"

int main(void) {
	int a = 0xDDCCBBAA;
	unsigned int b, d;
	unsigned char c;

	scanf("%x", &b);

	b = b << 16;

	for (int i = 0; i <= 24; ++i) {
		printf("%x", c = b >> i);
	}

	d = a ^ b;

	for (int i = 0; i <= 24; ++i) {
		printf("%x", c = d >> i);
	}
}