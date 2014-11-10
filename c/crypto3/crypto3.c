#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct message {
	char input[100];
	char shifted[100];
	char result[100];
};

#define PRINT_HEX(a, b) x = 0; \
			printf("%s", a); \
			for (; x < sizeof b; x++) { \
				switch (b[x]) { \
					case '\n': \
						printf("\\n"); \
						continue; \
					case '\0': \
						printf("\\0"); \
						continue; \
					default: \
						printf("\\%X", b[x]); \
						continue; \
				} \
			} \
			printf("\n");

#define SHIFT()	x = 0; \
		for (; x < sizeof msg.shifted; x++) \
			msg.shifted[x] = s+x < sizeof msg.input ? msg.input[s+x] : msg.input[s+x - sizeof msg.input];

#define XOR()	x = 0; \
		for (; x < sizeof msg.result; x++) \
			msg.result[x] = msg.input[x] ^ msg.shifted[x];

int main (int argc, char **argv) {
	
	int x = 0, s = 3;
	struct message msg;
	memset(msg.input, '\0', sizeof msg.input);
	memset(msg.shifted, '\0', sizeof msg.shifted);
	memset(msg.result, '\0', sizeof msg.result);

	printf("%s\n\t%s\n\t%s\n\n%s",
		"Welcome to DC612 1-Day event!",
		"Crypto Lvl 3",
		"Explain the cipher.",
		"Input: ");
	
	fflush(stdout);
	if (!fgets(msg.input, sizeof msg.input, stdin)) {
		printf("%s\n", "You must input something.");
		exit(1);
	}
	//msg.input[sizeof msg.input] = '\0';
	
		
	SHIFT()
	XOR()

	PRINT_HEX("Plaintext: ", msg.input)
	PRINT_HEX("Round 1: ", msg.shifted)
	PRINT_HEX("Ciphertext: ", msg.result)
	exit(0);
}
