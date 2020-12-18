#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

struct Contact_book
{
  long long int number;
  char name[15];
  char email[MAX];
  struct Contact_book *next;
  struct Contact_book *previous;
} * head;

void add_to_list(struct Contact_book *ptr, long long int ph_number, char name[], char email_id[])
{
  struct Contact_book *temp = head;
  ptr = malloc(sizeof(struct Contact_book));
  ptr->number = ph_number;
  strcpy(ptr->name, name);
  strcpy(ptr->email, email_id);
  ptr->next = NULL;

  if (head == NULL)
  {
    head = ptr;
    printf("Contact Added Successfully\n\n");
    return;
  }

  else
  {
    ptr->next = head;
    head->previous = ptr;
    head = ptr;
    printf("Contact Added Successfully\n\n");
    return;
  }
}

bool searchbyName(char name[])
{
  struct Contact_book *temp = head;
  while (temp != NULL)
  {
    if (strcasecmp(temp->name, name) == 0)
    {
      printf("\nNumber=%lli\nName=%s\nEmailid=%s\n", temp->number, temp->name, temp->email);
      return true;
    }
    temp = temp->next;
  }
  printf("contact not found\n");
  return false;
}

bool searchbyEmail(char email_id[])
{
  struct Contact_book *temp = head;
  while (temp != NULL)
  {
    if (strcasecmp(temp->email, email_id) == 0)
    {
      printf("\nNumber=%lli\nName=%s\nEmailid=%s\n", temp->number, temp->name, temp->email);
      return true;
    }
    temp = temp->next;
  }
  printf("contact not found\n");
  return false;
}

bool searchbyNumber(long long int ph_number)
{
  struct Contact_book *temp = head;
  while (temp != NULL)
  {
    if (temp->number == ph_number)
    {
      printf("\nNumber=%lli\nName=%s\nEmail id=%s\n", temp->number, temp->name, temp->email);
      return true;
    }
    temp = temp->next;
  }
  printf("Contact not found\n");
  return false;
}

void display(struct Contact_book *ptr)
{
  struct Contact_book *temp = head;

  while (temp != NULL)
  {
    printf("Name: %s\nNumber: %lli\nEmail: %s.\n\n", temp->name, temp->number, temp->email);
    temp = temp->next;
  }
}

struct Contact_book *deletebyname(char delname[])
{
  struct Contact_book *temp = head;
  int flag = 0;
  while (temp != NULL)
  {
    if (strcasecmp(temp->name, delname) == 0)
    {
      if (temp == head)
      {
        temp = temp->next;
        temp->previous = NULL;
        head = temp;
        printf("Your contact has been deleted");
        break;
      }
      if (temp->next == NULL)
      {
        temp->previous->next = NULL;
        printf("Your contact has been deleted");
        break;
      }
      temp->previous->next = temp->next;
      temp->next->previous = temp->previous;
      printf("Your contact has been deleted");
      break;
    }
    temp = temp->next;
  }
}

struct Contact_book *delbynumber(long long int delnumber)
{
  struct Contact_book *temp = head;
  while (temp != NULL)
  {
    if (temp->number == delnumber)
    {
      if (temp == head)
      {
        temp = temp->next;
        temp->previous = NULL;
        head = temp;
        printf("Your contact has been deleted");
        break;
      }
      if (temp->next == NULL)
      {
        temp->previous->next = NULL;
        printf("Your contact has been deleted");
        break;
      }
      temp->previous->next = temp->next;
      temp->next->previous = temp->previous;
      printf("Your contact has been deleted");
      break;
    }
    temp = temp->next;
  }
  return head;
}

struct Contact_book *delbyemail(char delemail[])
{
  struct Contact_book *temp = head;

  while (temp != NULL)
  {
    if (strcasecmp(temp->email, delemail) == 0)
    {
      if (temp == head)
      {
        temp = temp->next;
        temp->previous = NULL;
        head = temp;
        printf("Your contact has been deleted");
        break;
      }
      if (temp->next == NULL)
      {
        temp->previous->next = NULL;
        printf("Your contact has been deleted");
        break;
      }
      temp->previous->next = temp->next;
      temp->next->previous = temp->previous;
      printf("Your contact has been deleted");
      break;
    }
    temp = temp->next;
  }
  return head;
}

void updateByName()
{
  char name[MAX];
  printf("Enter name of the record which you wish to update: ");
  scanf("%s", name);
  printf("\n");
  struct Contact_book *temp = head;
  while (temp != NULL)
  {
    if (strcasecmp(temp->name, name) == 0)
    {
      printf("Enter New name: ");
      scanf("%s", name);
      strcpy(temp->name, name);
      printf("Update Successful !!!\n");
      break;
    }
    temp = temp->next;
  }
}

void updateByNumber()
{
  long long int number;
  printf("Enter number of the record you wish to update: ");
  scanf("%lli", &number);
  printf("\n");
  struct Contact_book *temp = head;
  while (temp != NULL)
  {
    if (temp->number == number)
    {
      printf("Enter New number: ");
      scanf("%lli", &number);
      temp->number = number;
      printf("Update Successful !!!\n");
      break;
    }
    temp = temp->next;
  }
}

void updateByEmail()
{
  char email[MAX];
  printf("Enter email of the record which you wish to update: ");
  scanf("%s", email);
  printf("\n");
  struct Contact_book *temp = head;
  printf("Contact Found\n\n");
  while (temp != NULL)
  {
    if (strcasecmp(temp->email, email) == 0)
    {
      printf("Enter New email: ");
      scanf("%s", email);
      strcpy(temp->email, email);
      printf("Update Successful !!!\n");
      break;
    }
    temp = temp->next;
  }
}

void updateRecord()
{
  struct Contact_book *ptr = head;
  int choice;
  printf("Update Contact by: ");
  printf("(1)Name.   (2)Number.   (3)Email.    (4)Return.\n");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
  {
    updateByName();
    break;
  }
  case 2:
  {
    updateByNumber();
    break;
  }
  case 3:
  {
    updateByEmail();
    break;
  }
  case 4:
  {
    printf("Exiting the search option!!!\n");
    break;
  }
  }
}

int main()
{
  struct Contact_book *p = malloc(sizeof(struct Contact_book));
  int option;
  long long int number;
  char name[20], email[100];
  char delname[20];

  do
  {
    printf("Enter a choice \n(0)Exit.   (1)Add.   (2)Display.   (3)Search a contact.   (4)Delete contact.   (5)Update Contact.   (6)Clear screen.\n");
    scanf("%d", &option);
    switch (option)
    {
    case 0:
      break;
    case 1:
      printf("Enter Name:\n");
      scanf("%s", name);
      printf("Enter Number:\n");
      scanf("%lli", &number);
      printf("Enter Email\n");
      scanf("%s", email);
      add_to_list(p, number, name, email);
      break;
    case 2:
      display(p);
      break;
    case 3:
      printf("search by \n1. Name\n2. Email\n3. Number\n");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
        printf("Enter Name\n");
        scanf("%s", name);
        searchbyName(name);
        break;
      case 2:
        printf("Enter Email\n");
        scanf("%s", email);
        searchbyEmail(email);
        break;
      case 3:
        printf("Enter Eumber\n");
        scanf("%lli", &number);
        searchbyNumber(number);
        break;
      default:
        printf("Please enter valid option\n");
        break;
      }
      break;
    case 4:
      printf("Delete contact by:");
      printf("\n1. Name\n2. Email\n3. Phone Number\n");
      printf("Enter your choice:");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
        printf("Enter the name to be deleted = ");
        scanf("%s", delname);
        p = deletebyname(delname);
        break;
      case 2:
        printf("Enter email id to be deleted = ");
        scanf("%s", email);
        p = delbyemail(email);
        break;
      case 3:
        printf("Enter the phone number to be deleted=");
        scanf("%lli", &number);
        p = delbynumber(number);
        break;
      default:
        printf("Please enter valid option\n");
        break;
      }
      break;
    case 5:
      updateRecord();
      break;
    case 6:
    {
      system("cls");
      break;
    }
    default:
      printf("Enter valid option\n");
    }
  } while (option != 0);
  return 0;
}