// main.c
#include <stdio.h>
#include "recipient.h"
#include "recipient.c"
#include "transaction.h"
#include "transaction.c"
int main() {
    int choice;
    char name[50], blood_group[5];
    int urgency, units;

    while (1) {
        printf("\n BLOOD BANK MANAGEMENTSYSTEM \n");
        printf("1. Register Recipient\n");
        printf("2. Search Recipient\n");
        printf("3. View All Recipients\n");
        printf("4. Record Donation\n");
        printf("5. Record Blood Request\n");
        printf("6. Record Issued Blood\n");
        printf("7. View Last 5 Transactions\n");
        printf("8. Undo Last Transaction\n");
        printf("9. Exit\n");
        printf(" Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter recipient name: ");
                scanf("%s", name);
                printf("Enter blood group: ");
                scanf("%s", blood_group);
                printf("Enter urgency (lower = more urgent): ");
                scanf("%d", &urgency);
                register_recipient(name, blood_group, urgency);
                break;

            case 2:
                printf("Enter recipient name to search: ");
                scanf("%s", name);
                search_recipient(name);
                break;

            case 3:
                display_recipients();
                break;

            case 4:
                printf("Enter donor name: ");
                scanf("%s", name);
                printf("Enter blood group: ");
                scanf("%s", blood_group);
                printf("Enter units donated: ");
                scanf("%d", &units);
                if (is_valid_blood_group(blood_group))
                    push_transaction("Donation", name, blood_group, units);
                else
                    printf(" Invalid blood group.\n");
                break;

            case 5:
                printf("Enter recipient name: ");
                scanf("%s", name);
                printf("Enter blood group: ");
                scanf("%s", blood_group);
                printf("Enter units requested: ");
                scanf("%d", &units);
                if (is_valid_blood_group(blood_group))
                    push_transaction("Request", name, blood_group, units);
                else
                    printf("Invalid blood group.\n");
                break;

            case 6:
                printf("Enter recipient name: ");
                scanf("%s", name);
                printf("Enter blood group: ");
                scanf("%s", blood_group);
                printf("Enter units issued: ");
                scanf("%d", &units);
                if (is_valid_blood_group(blood_group))
                    push_transaction("Issued", name, blood_group, units);
                else
                    printf("Invalid blood group.\n");
                break;

            case 7:
                view_last_transactions(5);
                break;

            case 8:
                undo_last_transaction();
                break;

            case 9:
                printf("Exiting system...!\n");
                return 0;

            default:
                printf(" Invalid choice.\n");
        }
    }

    return 0;
}
