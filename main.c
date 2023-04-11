#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void clear() {
	system("cls");
	fflush(stdin);
}


void pause() {
	printf("\n\n\n");
	system("pause");
}


int getIntValue(char caption[]) {
	int value;

	printf("%s: ", caption);
	scanf("%d", &value);

	return value;
}


void getStringValue(char caption[], char string[]) {
	printf("%s: ", caption);
	fflush(stdin);
	gets(string);
}


void anatoly_1() {
	char string[255];

	getStringValue("String", string);

	int stringLength = (int) strlen(string);

	printf("\nResult: ");

	for (int i = stringLength - 1; i >= 0; i--) {
		printf("%c", string[i]);
	}
}


void anatoly_2() {
	int numDigits = 0;
	char string[255] = {"\0"};

	getStringValue("String", string);

	for (int i = 0; i < 255; i++) {
		int num = (int) string[i] - 48;
		if (num >= 0 && num <= 9)
			numDigits++;
	}

	printf("Num digits: %d", numDigits);
}

void anatoly_3() {
	int numLatinLetters = 0;
	char string[255] = {"\0"};

	getStringValue("String", string);

	for (int i = 0; i < 255; i++) {
		int code = (int) string[i];
		if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122))
			numLatinLetters++;
	}

	printf("Num latin letters: %d", numLatinLetters);
}


void anatoly_4() {
	char string[255] = {"\0"};

	getStringValue("String", string);

	printf("\nResult: ");

	for (int i = 0; i < 255; i++) {
		char chr = string[i];
		int code = (int) chr;

		if (code >= 65 && code <= 90)
			chr = (char) (code + 32);

		printf("%c", chr);
	}
}


void anatoly_5() {
	char string[255] = {"\0"};
	char stringFirst[255] = {"\0"};
	char stringSecond[255] = {"\0"};

	getStringValue("String", string);
	getStringValue("String 1", stringFirst);
	getStringValue("String 2", stringSecond);

	size_t stringLen = strlen(string);
	size_t stringFirstLen = strlen(stringFirst);
	size_t stringSecondLen = strlen(stringSecond);

	char* result = malloc(stringLen + 1);
	strcpy(result, string);

	char* pos = result;
	while ((pos = strstr(pos, stringFirst)) != NULL) {
		memmove(pos + stringSecondLen, pos + stringFirstLen, strlen(pos + stringFirstLen) + 1);
		memcpy(pos, stringSecond, stringSecondLen);
		pos += stringSecondLen;
	}

	printf("\nResult: %s", result);
}


int main() {
	int running = 1;

	while (running) {
		clear();

		printf("FUNCTIONS:\n");
		printf("1. ...\n");
		printf("2. ...\n");
		printf("3. ...\n");
		printf("4. ...\n");
		printf("5. ...\n");
		printf("6. Quit");

		int function = getIntValue("\n\nSelect function");

		clear();

		switch (function) {
			case 1:
				anatoly_1();
				break;
			case 2:
				anatoly_2();
				break;
			case 3:
				anatoly_3();
				break;
			case 4:
				anatoly_4();
				break;
			case 5:
				anatoly_5();
				break;
			case 6:
				running = 0;
				break;
			default:
				printf("Bruh... %d, rly?", function);
		}

		pause();
	}
}
