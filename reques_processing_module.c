#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char bloodGroup[5];
    int unitsAvailable;
} BloodStock;


void processBloodRequest();
void loadInventory(BloodStock stockList[], int *count);
void updateInventory(BloodStock stockList[], int count);

void processBloodRequest() {
    BloodStock stockList[10];
    int count = 0;
    char reqBloodGroup[5];
    int reqUnits;

    loadInventory(stockList, &count);

    printf("\n----- BLOOD REQUEST PROCESSING -----\n");
    printf("Enter Blood Group Required (e.g., A+, O-, AB+): ");
    scanf("%s", reqBloodGroup);
    printf("Enter Number of Units Required: ");
    scanf("%d", &reqUnits);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(stockList[i].bloodGroup, reqBloodGroup) == 0) {
            found = 1;
            if (stockList[i].unitsAvailable >= reqUnits) {
                stockList[i].unitsAvailable -= reqUnits;
                printf("\n Request Approved! %d units of %s issued.\n",
                       reqUnits, reqBloodGroup);
                updateInventory(stockList, count);
            } else {
                printf("\nInsufficient stock! Only %d units available.\n",
                       stockList[i].unitsAvailable);
                printf("Suggestion: Search for donors with %s blood group.\n", reqBloodGroup);
            }
            break;
        }
    }

    if (!found) {
        printf("\n Blood group %s not found in inventory.\n", reqBloodGroup);
    }
}

void loadInventory(BloodStock stockList[], int *count) {
    FILE *fp = fopen("inventory.txt", "r");
    *count = 0;

    if (fp == NULL) {
        printf("\n⚠ Inventory file not found. Creating new one...\n");
        fp = fopen("inventory.txt", "w");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%s %d",
                  stockList[*count].bloodGroup,
                  &stockList[*count].unitsAvailable) != EOF) {
        (*count)++;
    }

    fclose(fp);
}

void updateInventory(BloodStock stockList[], int count) {
    FILE *fp = fopen("inventory.txt", "w");
    if (fp == NULL) {
        printf("\nError updating inventory file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d\n", stockList[i].bloodGroup, stockList[i].unitsAvailable);
    }

    fclose(fp);
}