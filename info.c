#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

void addContact(struct Contact contacts[], int *count);
void viewContacts(struct Contact contacts[], int count);
void editContact(struct Contact contacts[], int count);
void deleteContact(struct Contact contacts[], int *count);

int main() {
    struct Contact contacts[100];
    int count = 0;
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add a new contact\n");
        printf("2. View contacts\n");
        printf("3. Edit a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                viewContacts(contacts, count);
                break;
            case 3:
                editContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addContact(struct Contact contacts[], int *count) {
    printf("\nEnter name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*count].phone);
    printf("Enter email address: ");
    scanf("%s", contacts[*count].email);
    (*count)++;
    printf("Contact added successfully!\n");
}

void viewContacts(struct Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display.\n");
    } else {
        printf("\nContact List:\n");
        for (int i = 0; i < count; i++) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", contacts[i].name, contacts[i].phone, contacts[i].email);
        }
    }
}

void editContact(struct Contact contacts[], int count) {
    char searchName[50];
    printf("Enter the name of the contact to edit: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Enter new name: ");
            scanf("%s", contacts[i].name);
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            printf("Enter new email address: ");
            scanf("%s", contacts[i].email);
            printf("Contact edited successfully!\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void deleteContact(struct Contact contacts[], int *count) {
    char searchName[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", searchName);

    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].phone, contacts[j + 1].phone);
                strcpy(contacts[j].email, contacts[j + 1].email);
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found.\n");
}
