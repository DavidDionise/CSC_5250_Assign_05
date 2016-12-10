
#include "util.h"
#include "phone_book.h"

char* getLine() {
	int length = 10;
	int count = 0;
	char* buffer = (char*)malloc(sizeof(char) * length);
	char* buf_ptr = &buffer[0];
	char c;

	*buf_ptr = '\0';
	
	while((c = getchar()) != '\n') {
		if(count >= (length - 1)) {
			length += 10;
			buffer = (char*)realloc(buffer, length);
		}

		++count;
		*buf_ptr = c;
		*(++buf_ptr) = '\0';
	}

	return buffer;
}

char* getLineFromFile(FILE *fp) {
	fp = fopen("database.txt", "r");

	int length = 10;
	int count = 0;
	char* buffer = (char*)malloc(sizeof(char) * length);
	char* buf_ptr = &buffer[0];
	char c;

	*buf_ptr = '\0';
	
	while((c = fgetc(fp)) != '\n') {
		if(count >= (length - 1)) {
			length += 10;
			buffer = (char*)realloc(buffer, length);
		}

		++count;
		*buf_ptr = c;
		*(++buf_ptr) = '\0';
	}

	fclose(fp);
	return buffer;	
}

void Add(entry *arg, CLIENT *clnt) {
	r_val *result;
	char *name, *number;

	puts("Enter the name : ");
	name = getLine();

	puts("Enter the number : ");
	number = getLine();

	arg->name = malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(arg->name, name);

	arg->number = malloc(sizeof(char) * (strlen(number) + 1));
	strcpy(arg->number, number);

	arg->next = NULL;

	result = add_to_database_1(arg, clnt);

	if (result == NULL) {
		clnt_perror(clnt, "call failed:");
	}
	else if(result->r_num == -1) {
		printf("%s\n", result->r_error);
	}
	else printf("returned %i\n", result->r_num);
}


