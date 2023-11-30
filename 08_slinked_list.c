#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insertfirst() {
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("no space");
  } else {
    printf("enter the element to be inserted:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL) {
      head = newnode;
    } else {
      newnode->next = head;
      head = newnode;
    }
    printf("%d inserted into the list", newnode->data);
  }
}

void insertlast() {
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("no space");
  } else {
    printf("enter the element to be inserted:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL) {
      head = newnode;
    } else {
      temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
    }
    printf("%d inserted into the list", newnode->data);
  }
}

void insertlocation() {
  struct node *newnode, *temp, *prev;
  int key, i = 1;
  
  newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("No space\n");
    return;
  }

  printf("Enter the location to insert: ");
  scanf("%d", &key);

  if (key < 1) {
    printf("Invalid position. Position must be greater than or equal to 1.\n");
    free(newnode);
    return;
  }

  printf("Enter the element to be inserted: ");
  scanf("%d", &newnode->data);

  temp = head;
  prev = NULL;

  if (key == 1) {
    // Insert at the beginning
    newnode->next = head;
    head = newnode;
    printf("%d inserted at the beginning\n", newnode->data);
    return;
  }

  while (i < key && temp != NULL) {
    prev = temp;
    temp = temp->next;
    i++;
  }

  if (temp == NULL && i <= key) {
    // Insert at the end
    prev->next = newnode;
    newnode->next = NULL;
    printf("%d inserted at the end\n", newnode->data);
  } else if (temp == NULL) {
    printf("Invalid position. List size is smaller than the specified position.\n");
    free(newnode);
  } else {
    // Insert at the specified position
    newnode->next = temp;
    prev->next = newnode;
    printf("%d inserted at position %d\n", newnode->data, key);
  }
}


void deletefirst() {
  struct node *temp;
  temp = head;
  if (head == NULL) {
    printf("linked list is empty");
    return;
  }
  head = temp->next;
  printf("%d deleted", temp->data);
  free(temp);
}

void deletelast() {
  struct node *temp, *prev;
  temp = head;
  if (head == NULL) {
    printf("linked list is empty");
    return;
  }
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == head) {
    head = temp->next;
    free(temp);
    return;
  }
  prev->next = temp->next;
  printf("%d deleted", temp->data);
  free(temp);
}

void deletelocation() {
  struct node *temp, *prev;
  int key, i = 1;
  printf("enter the position to be deleted:");
  scanf("%d", &key);
  temp = head;
  prev = NULL;
  while (i < key && temp != NULL) {
    prev = temp;
    temp = temp->next;
    i++;
  }

  if (temp == NULL) {
    printf("the %d value not exist", key);
    return;
  } else {
    if (temp == head) {
      head = temp->next;
      free(temp);
      return;
    }
    prev->next = temp->next;
    printf("%d deleted", temp->data);
    free(temp);
  }
}

void search() {
  struct node *temp;
  int key, i = 1, flag = 0;
  printf("enter the elements: ");
  scanf("%d", &key);
  if (head == NULL) {
    printf("no elements in the list");
  } else {
    temp = head;
    while (temp != NULL) {
      if (temp->data == key) {
        printf("element found at position %d", i);
        flag = 1;
        break;
      }
      temp = temp->next;
      i++;
    }
    if (flag == 0) {
      printf("element not found");
    }
  }
}

void display() {
  struct node *p;
  if (head == NULL) {
    printf("linked list is empty");
  } else {
    printf("elements are:");
    p = head;
    while (p != NULL) {
      printf("\t %d", p->data);
      p = p->next;
    }
  }
}

int main() {
  int ch;
  printf("singly linked list");
  do {
    printf("\n 1.insertfirst 2.insertlast 3.insertlocation 4.deletefirst 5.deletelast 6.deletelocation 7.search 8.display 9.exit");
    printf("\n enter your choice:");
    scanf("\n%d", &ch);
    switch (ch) {
    case 1:
      insertfirst();
      break;
    case 2:
      insertlast();
      break;
    case 3:
      insertlocation();
      break;
    case 4:
      deletefirst();
      break;
    case 5:
      deletelast();
      break;
    case 6:
      deletelocation();
      break;
    case 7:
      search();
      break;
    case 8:
      display();
      break;
    case 9:
      exit(0);
    default:
      printf("invalid choice");
    }
  } while (ch != 9);
  return 0;
}
