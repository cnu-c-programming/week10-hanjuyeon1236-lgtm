#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

Node* head = NULL;

void add(char* n, int s) {
    Node **curr = &head;
    while (*curr) curr = &((*curr)->next);
    *curr = malloc(sizeof(Node));
    strcpy((*curr)->name, n);
    (*curr)->score = s;
    (*curr)->next = NULL;
}

void del(char* n) {
    Node **curr = &head, *temp;
    while (*curr && strcmp((*curr)->name, n)) curr = &((*curr)->next);
    if (*curr) {
        temp = *curr;
        *curr = (*curr)->next;
        free(temp);
    }
}

int main() {
    char cmd[10], name[50];
    int score;
    while (scanf("%s", cmd) != EOF) {
        if (!strcmp(cmd, "add")) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (!strcmp(cmd, "delete")) {
            scanf("%s", name);
            del(name);
        } else if (!strcmp(cmd, "print")) {
            for (Node* t = head; t; t = t->next) printf("%s %d\n", t->name, t->score);
        }
    }
}
