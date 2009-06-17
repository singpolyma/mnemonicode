#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mnemonic.h"

int main(int argc, char **argv) {
	char buf[0x90000];
	mn_byte outbuf[0x10000];
	int buflen;
	int n, i;
	int hex_encoded_output = 0;

	if(argc > 1 && strcmp(argv[1],"-x") == 0) {
		hex_encoded_output = 1;
	}

	buflen = fread(buf, 1, sizeof buf - 1, stdin);
	buf[buflen] = 0;

	n = mn_decode(buf, outbuf, sizeof outbuf);
	if(n < 0) {
		fprintf(stderr, "mn_decode result %d\n", n);
		return EXIT_FAILURE;
	}

	if(hex_encoded_output) {
		for(i = 0; i < n; i++) {
			printf("%X", outbuf[i]);
		}
	} else {
		fwrite(outbuf, 1, n, stdout);
	}

	return EXIT_SUCCESS;
}
