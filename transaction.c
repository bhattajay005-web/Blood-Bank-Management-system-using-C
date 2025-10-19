// transaction_module.c
#include <stdio.h>
#include <string.h>
#include "transaction.h"

#define MAX_TRANSACTIONS 100

typedef struct {
    char type[20];      // Donation, Request, Issued
    char name[50];      // Person's name
    char blood_group[5];
    int units;
} Transaction;

Transaction stack[MAX_TRANSACTIONS];
int top = -1;

void push_transaction(const char *type, const char *name, const char *blood_group, int units) {
    if (top >= MAX_TRANSACTIONS - 1) {
        printf(" Transaction log full.\n");
        return;
    }
    top++;
    strcpy(stack[top].type, type);
    strcpy(stack[top].name, name);
    strcpy(stack[top].blood_group, blood_group);
    stack[top].units = units;

    printf("Transaction Recorded: %s | %s | %s | %d unit(s)\n",
           type, name, blood_group, units);
}

void view_last_transactions(int count) {
    if (top == -1) {
        printf("No transactions recorded yet.\n");
        return;
    }

    printf("\n Last %d Transactions:\n", count);
    for (int i = top; i >= 0 && count > 0; i--, count--) {
        printf(" %s: %s | %s | %d unit(s)\n",
               stack[i].type, stack[i].name, stack[i].blood_group, stack[i].units);
    }
}

void undo_last_transaction() {
    if (top == -1) {
        printf("No transaction to undo.\n");
        return;
    }

    printf(" Undoing Transaction: %s | %s | %s | %d unit(s)\n",
           stack[top].type, stack[top].name, stack[top].blood_group, stack[top].units);
    top--;
}
