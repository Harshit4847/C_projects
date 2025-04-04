#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_no[20];
    char emailadress[50];
};

struct Contact contacts[MAX_CONTACTS];
int totalcontacts = 0;

void fileInitialization() {
    FILE *file = fopen("contact.txt", "a");
    if (file == NULL) {
        printf("Error: Could not initialize file!\n");
    } else {
        fclose(file);
        printf("File initialized successfully.\n");
    }
}

void displaycontacts() {
    if (totalcontacts == 0) {
        printf("Contact list is empty. Try adding something first!\n");
        return;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < totalcontacts; i++) {
        printf("%d. Name: %s | Phone No.: %s | Email Address: %s\n",
               i + 1, contacts[i].name, contacts[i].phone_no, contacts[i].emailadress);
    }
}

void add_contact() {
    if (totalcontacts >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[totalcontacts].name, sizeof(contacts[totalcontacts].name), stdin);
    contacts[totalcontacts].name[strcspn(contacts[totalcontacts].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[totalcontacts].phone_no, sizeof(contacts[totalcontacts].phone_no), stdin);
    contacts[totalcontacts].phone_no[strcspn(contacts[totalcontacts].phone_no, "\n")] = 0;

    printf("Enter email address: ");
    fgets(contacts[totalcontacts].emailadress, sizeof(contacts[totalcontacts].emailadress), stdin);
    contacts[totalcontacts].emailadress[strcspn(contacts[totalcontacts].emailadress, "\n")] = 0;

    totalcontacts++;
    printf("Contact added successfully!\n");

    FILE *file = fopen("contact.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s,%s,%s\n", contacts[totalcontacts - 1].name, contacts[totalcontacts - 1].phone_no, contacts[totalcontacts - 1].emailadress);
    fclose(file);
}

void load_contacts() {
    FILE *file = fopen("contact.txt", "r");
    if (file == NULL) {
        printf("No existing contacts found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%49[^,],%19[^,],%49[^\n]\n", contacts[totalcontacts].name, contacts[totalcontacts].phone_no, contacts[totalcontacts].emailadress) != EOF) {
        totalcontacts++;
        if (totalcontacts >= MAX_CONTACTS) {
            printf("Max contact limit reached while loading!\n");
            break;
        }
    }

    fclose(file);
    printf("Contacts loaded successfully!\n");
}

void search_contact() {
    char search_name[50];
    printf("Enter the name to search: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < totalcontacts; i++) {
        if (strcasecmp(contacts[i].name, search_name) == 0) { // Case-insensitive comparison
            printf("\n Contact Found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone_no);
            printf("Email: %s\n", contacts[i].emailadress);
            found = 1;
            break;  // Stop searching after finding the first match
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void delete_contact() {
    char search_name[50];
    printf("Enter the name to delete: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < totalcontacts; i++) {
        if (strcasecmp(contacts[i].name, search_name) == 0) { // Case-insensitive comparison
            found = 1;

            // Shift all contacts after the found index one step left
            for (int j = i; j < totalcontacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }

            totalcontacts--; // Reduce contact count

            FILE *file = fopen("contact.txt", "w");
            if (file == NULL) {
                printf("Error opening file for updating!\n");
                return;
            }
            for (int k = 0; k < totalcontacts; k++) {
                fprintf(file, "%s,%s,%s\n", contacts[k].name, contacts[k].phone_no, contacts[k].emailadress);
            }
            fclose(file);

            printf("Contact deleted and file updated!\n");
            return;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void update_contact() {
    char search_name[50];
    printf("Enter the name to update: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    for (int i = 0; i < totalcontacts; i++) {
        if (strcasecmp(contacts[i].name, search_name) == 0) {
            printf("Contact found. Enter new details:\n");

            printf("New Name: ");
            fgets(contacts[i].name, sizeof(contacts[i].name), stdin);
            contacts[i].name[strcspn(contacts[i].name, "\n")] = 0;

            printf("New Phone No: ");
            fgets(contacts[i].phone_no, sizeof(contacts[i].phone_no), stdin);
            contacts[i].phone_no[strcspn(contacts[i].phone_no, "\n")] = 0;

            printf("New Email: ");
            fgets(contacts[i].emailadress, sizeof(contacts[i].emailadress), stdin);
            contacts[i].emailadress[strcspn(contacts[i].emailadress, "\n")] = 0;

            // Rewrite the file with updated contact list
            FILE *file = fopen("contact.txt", "w");
            if (file == NULL) {
                printf("Error updating file!\n");
                return;
            }

            for (int j = 0; j < totalcontacts; j++) {
                fprintf(file, "%s,%s,%s\n", contacts[j].name, contacts[j].phone_no, contacts[j].emailadress);
            }

            fclose(file);

            printf("Contact updated successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}


void menu() {
    int choice = 0;

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                displaycontacts();
                break;

            case 3:
                search_contact();
                break;

            case 4:
                delete_contact();
                break;

            case 5:
                update_contact();
                break;


            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

int main() {

    load_contacts();
    fileInitialization();
    menu();
    return 0;
}
