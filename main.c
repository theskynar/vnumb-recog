#include <stdio.h>
#include <stdlib.h>

int isNumber(char c);
int isAlpha(char c);
int append(char tempS[], char variables[][100], int line);
int clean(char *tempS, int size);
void display(const char variables[][100], int line);
int equals(char tmp[100], char line[100]);

int main() {

    char variables[100][100] = {"\0"};

    int i = 0, tmp = 0;
    char msg[100];
    char tempS[100] = "";
    int tempN;
    int currLine = 0;

    gets(msg);

    goto E0;

    E0:
        if (isAlpha(msg[i]) == 1) {
            tempS[tmp] = msg[i];
            i++; tmp++;
            goto E1;
        } else if (isNumber(msg[i]) == 1) {
            tempN = msg[i] - '0';
            i++;
            goto E2;
        } else if (msg[i] == '\0') {
            display(variables, currLine);
            exit(0);
        } else if (msg[i] == ' ') {
            i++;
            goto E0;
        }
    E1:
        if (msg[i] == '\0') {
            currLine = append(tempS, variables, currLine);
            tmp = clean(tempS, tmp);
            goto E0;
        } else if (msg[i] == ' ') {
            currLine = append(tempS, variables, currLine);
            tmp = clean(tempS, tmp);
            i++;
            goto E0;
        } else {
            tempS[tmp] = msg[i];
            i++; tmp++;
            goto E1;
        }
    E2:
        if (msg[i] == '\0') {
            goto E0;
        } else if (msg[i] == ' ') {
            i++;
            goto E0;
        } else if (isNumber(msg[i]) == 1) {
            tempN = tempN * 10 + (msg[i] - '0');
            printf("N(%d)\n", tempN);
            i++;
            goto E2;
        }

}

int isNumber(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int isAlpha(char c) {
    if (c >= 'A'  && c <= 'Z') {
        return 1;
    }
    return 0;
}

int equals(char tmp[100], char line[100]) {
    int result = 1;

    for (int k = 0; tmp[k] != '\0' || line[k] != '\0' ; k++) {
        if (tmp[k] != line[k]) {
            result = 0;
            return result;
        }
    }

    return result;
}

int append(char tempS[], char variables[][100], int line) {
    int found = 0;
    for (int p = 0; p <= line; p++) {
        if (equals(tempS, variables[p]) == 1) {
            found = 1;
            printf("Found at V(%d)\n", p);
        }
    }

    if (found == 0) {
        for (int c = 0; variables[line][c] = tempS[c]; c++);
        printf("Created at V(%d)\n", line);
        line++;
    }

    return line;
}

int clean(char *tempS, int size) {
    for (int i = 0; i <= size; i++)
        *(tempS + i) = 0;

    return 0;
}

void display(const char variables[][100], int line) {
    printf("\nList of variables\n");
    for (int i = 0 ; i < line; i++) {
        for (int j =0; variables[i][j] != '\0'; j++) {
            printf("%c", variables[i][j]);
        }
        printf("\n");
    }
}



