#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Donor Information
typedef struct {
    int id;
    char name[50];
    char bloodGroup[5];
    char city[30];
    char contact[15];
} Donor;

// Structure for Blood Stock (for report)
typedef struct {
    char bloodGroup[5];
    int unitsAvailable;
} BloodStock;


void searchDonor();
void generateReport();
void loadDonors(Donor donorList[], int *count);
void loadInventory(BloodStock stockList[], int *count);


void searchDonor() {              //for search
    Donor donorList[100];
    int count = 0;
    char searchGroup[5];

    loadDonors(donorList, &count);

    printf("\n----- SEARCH DONOR BY BLOOD GROUP -----\n");
    printf("Enter Blood Group to Search (e.g., A+, O-): ");
    scanf("%s", searchGroup);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(donorList[i].bloodGroup, searchGroup) == 0) {
            printf("\nID: %d | Name: %s | City: %s | Contact: %s",
                   donorList[i].id, donorList[i].name,
                   donorList[i].city, donorList[i].contact);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo donors found with blood group %s.\n", searchGroup);
    }
}


void generateReport() {
    BloodStock stockList[10];
    int count = 0;
    loadInventory(stockList, &count);

    printf("\n----- BLOOD BANK REPORT -----\n");
    printf("%-10s | %-10s\n", "BloodGroup", "Units");
    printf("---------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10s | %-10d\n", stockList[i].bloodGroup, stockList[i].unitsAvailable);
    }

    printf("---------------------------\n");
}


void loadDonors(Donor donorList[], int *count) {
    FILE *fp = fopen("donors.txt", "r");
    *count = 0;

    if (fp == NULL) {
        printf("\n⚠️ Donor file not found. Creating new one...\n");
        fp = fopen("donors.txt", "w");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%d %s %s %s %s",
                  &donorList[*count].id,
                  donorList[*count].name,
                  donorList[*count].bloodGroup,
                  donorList[*count].city,
                  donorList[*count].contact) != EOF) {
        (*count)++;
    }

    fclose(fp);
}

void loadInventory(BloodStock stockList[], int *count) {
    FILE *fp = fopen("inventory.txt", "r");
    *count = 0;

    if (fp == NULL) {
        printf("\n⚠️ Inventory file not found.\n");
        return;
    }

    while (fscanf(fp, "%s %d",
                  stockList[*count].bloodGroup,
                  &stockList[*count].unitsAvailable) != EOF) {
        (*count)++;
    }

    fclose(fp);
}
