#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define KEY "abcdefgh"
#define MAX_KEY 7

struct message {
	char plain[100];
	char temp[2];
	char key[9];
};

int main (int argc, char **argv) {

	int c = 0, i = 0;
	struct message msg;
	memset(msg.plain, '\0', sizeof msg.plain);
	memset(msg.temp, '\0', sizeof msg.temp);
	snprintf(msg.key, sizeof msg.key, KEY);
	
	printf("%s\n\t%s\n\t%s\n\n%s",
		"Welcome to DC612 1-Day event!",
		"Crypto Lvl 2",
		"Find the hidden key.",
		"Input: ");
	
	fflush(stdout);
	if (!fgets(msg.plain, sizeof msg.plain, stdin)) {
		printf("%s\n", "You must input something.");
		exit(1);
	}
	msg.plain[sizeof msg.plain] = '\0';

	printf("%s", "Input: ");
        for (c=0; c<strlen(msg.plain); c++) {
                if (msg.plain[c] == '\n' || msg.plain[c] == '\0')
			break;
		printf("\\%X", msg.plain[c]);
        }
        printf("\n");

	printf("%s", "Final Output: ");
	for (c=0; c<strlen(msg.plain); c++) {
		if (msg.plain[c] == '\n' || msg.plain[c] == '\0' || msg.key[i] == '\0')
			break;
		msg.temp[0] =  msg.plain[c] ^ msg.key[i];
		printf("\\%X", msg.temp[0]);
		i = i < MAX_KEY ? i+1 : 0;
	}
	printf("\n");
	exit(0);
}
