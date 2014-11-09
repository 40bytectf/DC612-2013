#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HIGH_SHIFT			3
#define LOW_SHIFT			2
#define DEC_SHIFT			1
#define SHIFT_MAX			26
#define NUMBER_OF_LETTERS		26
#define NUMBER_OF_DIGITS		10
#define CIPHER_SPECIAL_CHARS		" .!?,;:'()[]{}`"
#define TO_CHAR(a) (char)(a)

struct message {
	char coded[50];
	char original[50];
	size_t size;
};

int main (int argc, char **argv) {
	
	int32_t	i = 0;
	struct message msg;
	msg.size = 0;
	memset(msg.coded, '\0', sizeof msg.coded);
	memset(msg.original, '\0', sizeof msg.coded);

	printf("%s\n\t%s\n\t%s\n\n%s",
		"Welcome to DC612 1-Day Event",
		"Crypto Lvl 1",
		"What type of cipher is this, and what are the keys?",
		"Input: ");
	
	fflush(stdout);
	if (!fgets(msg.original, sizeof msg.original, stdin)) {
		printf("%s\n", "You need some from of input.");
		exit(1);
	}
	msg.original[sizeof msg.original - 1] = '\0';

	for (i=0; i<strlen(msg.original); i++) {
  		if (strchr(CIPHER_SPECIAL_CHARS, msg.original[i])!=NULL)
   			msg.coded[i] = msg.original[i];
		else if (islower(msg.original[i]))
			msg.coded[i] = TO_CHAR((((int)(msg.original[i]-'a') + LOW_SHIFT) % NUMBER_OF_LETTERS) + 'a');
		else if (isupper(msg.original[i]))
			msg.coded[i] = TO_CHAR((((int)(msg.original[i]-'A') + HIGH_SHIFT) % NUMBER_OF_LETTERS) + 'A');
		else if (isdigit(msg.original[i]))
			msg.coded[i] = TO_CHAR(((int)(msg.original[i]-'0') + DEC_SHIFT) % NUMBER_OF_DIGITS + '0');
  		else {
			msg.original[i] = '\0';
			msg.coded[i] = '\0';
			break;
  		}
 	}
 	msg.coded[sizeof msg.coded - 1] = '\0';

	printf("%s %s - ","Plaintext:", msg.original);
	for (i=0; i<strlen(msg.original); i++)
		printf("\\%d", msg.original[i]);
	printf("\n");

	printf("%s %s - ", "Ciphertext:", msg.coded);
	for (i=0; i<strlen(msg.coded); i++)
		printf("\\%d", msg.coded[i]);
	printf("\n");
	exit(0);
}	
