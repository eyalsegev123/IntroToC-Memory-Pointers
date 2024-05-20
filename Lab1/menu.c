#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <base.c>

struct fun_desc {
    char *name;
    char (*fun)(char);
};

struct fun_desc menu[] = {
    { "Get String", my_get },
    { "Print String (cprt)", cprt },
    { "Print Hex (xoprt)", xoprt },
    { "Encrypt", encrypt },
    { "Decrypt", decrypt },
    { NULL, NULL }
};

int main() {
    char carray[5] = "";
    char input[128];
    int choice;

    while (1) {
        printf("Select operation from the following menu:\n");
        for (int i = 0; menu[i].name != NULL; i++) {
            printf("%d) %s\n", i, menu[i].name);
        }
        printf("Option: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input\n");
            continue;
        }

        if (choice >= 0 && menu[choice].name != NULL) {
            char* new_carray = map(carray, 5, menu[choice].fun);
            strcpy(carray, new_carray);
            free(new_carray);
        } else {
            printf("Not within bounds\n");
            break;
        }
    }
    return 0;
}
