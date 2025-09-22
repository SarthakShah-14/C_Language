#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50 // max name length
#define MAX_TRAINS 50
#define MAX_USERS 50
#define MAX_SEATS 50 // max no of seats

char admin_name[20] = "admin";
char admin_pass[20] = "admin123";

int no_of_record = 0;
struct train {
  int tno;
  char name[MAX_NAME_LENGTH];
  char destination[MAX_NAME_LENGTH];
  char arrival[MAX_NAME_LENGTH];
  int seatsAvailable;
  int hr, min;
  // int seatsAvailable[MAX_SEATS];
} train;
int avltrainno(int rno);
struct User {
  char username[MAX_NAME_LENGTH];
  char password[MAX_NAME_LENGTH];
  char name[MAX_NAME_LENGTH];
  char sname[MAX_NAME_LENGTH];
  int bookedSeats[MAX_SEATS];
};

struct entuser {
  char username[MAX_NAME_LENGTH];
  char password[MAX_NAME_LENGTH];
};
struct entuser fuser;
struct train trains[MAX_TRAINS];
struct User users[MAX_USERS];

struct booktk {
   long long int mobno;
  char name[MAX_NAME_LENGTH];
  char lastname[MAX_NAME_LENGTH];
  int booktickt;
  int age;
  int tno;
};
struct booktk passenger[20];
void view_train();
int fare(int);
int live_seats(int);

int currentUser = -1;
int get_no_of_record() {
  FILE *fp;
  fp = fopen("Train_Record4", "r");
  no_of_record = 0;
  while (fread(&train, sizeof(train), 1, fp)) {
    no_of_record = no_of_record + 1;
  }
  fclose(fp);
  return no_of_record;
}

void printmenu() {

  printf("\n---------------------------------Select your "
         "choice--------------------------------------\n");
  printf("\n1. Registration/Sign up");
  printf("\n2. Login");
  printf("\n3. Insert");
  printf("\n4. Display");
  printf("\n5. Search by Number");
  printf("\n6. Search by Name");
  printf("\n7. Delete");
  printf("\n8. Update");
  printf("\n9. Book Ticket");
  printf("\n10. Sort");
  printf("\n11. Exit");
  printf("\n-------------------------------------------------------------------"
         "----------------------\n");
}
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert() {
  int enter = 1;
  FILE *fp;
  do {
    fp = fopen("Train_Record4", "a");
    printf("Enter the Train No  :");
    scanf("%d", &train.tno);
    printf("Enter the Name of Train:");
    scanf("%s", train.name);
    printf("Enter Arrival:");
    scanf("%s", train.arrival);
    printf("Enter Destination:");
    scanf("%s", train.destination);
    printf("Enter Train Hour :");
    scanf("%d", &train.hr);
    printf("Enter Train Minute:");
    scanf("%d", &train.min);
    printf("Enter the Number of Seats availble");
    scanf("%d", &train.seatsAvailable);
    fwrite(&train, sizeof(train), 1, fp);
    fclose(fp);
    printf("etner 1 for another input or 0 for exit");
    scanf("%d", &enter);
  } while (enter == 1);
}
//    FUNCTION TO DISPLAY RECORDS
void disp() {
  FILE *fp1;
  fp1 = fopen("Train_Record4", "r");
  printf("\n\n-----------------------------------------------------------------"
         "-----------------------\n");
  printf("| TrainNo | TrainName         | Arrival    | Destination | TrainTime "
         "  | Seats Available |\n");
  printf("|---------|-------------------|------------|-------------|-----------"
         "--|-----------------|\n");
  while (fread(&train, sizeof(train), 1, fp1)) {
    printf("| %-7d | %-17s | %-10s | %-11s | %d:%-9d | %-7d         |\n",
           train.tno, train.name, train.arrival, train.destination, train.hr,
           train.min, train.seatsAvailable);
  }
  printf("---------------------------------------------------------------------"
         "-------------------\n");
  fclose(fp1);
}

void userRegistration() {
  FILE *fpr;
  fpr = fopen("USERS_PASSWORD", "a");

  printf("Enter username: ");
  scanf("%s",
        fuser.username); // Assuming you want to add the user to the last index
  printf("Enter password: ");
  scanf("%s", fuser.password);
  fwrite(&fuser, sizeof(fuser), 1, fpr);
  fclose(fpr);
  printf("User registered successfully!\n");
}

int userLogin() {
  int flag = 1;

  char enteredUsername[MAX_NAME_LENGTH];
  char enteredPassword[MAX_NAME_LENGTH];

  printf("Enter username: ");
  scanf("%s", enteredUsername);
  printf("Enter password: ");
  scanf("%s", enteredPassword);
  FILE *fpl;
  fpl = fopen("USERS_PASSWORD", "r");
  if (fpl == NULL) {
    printf("no Users Registered");
    return -1;
  }

  while (fread(&fuser, sizeof(fuser), 1, fpl)) {
    if (strcmp(enteredUsername, fuser.username) == 0 &&
        strcmp(enteredPassword, fuser.password) == 0) {
      fclose(fpl);
      printf("Login successful!\n");
      printf("Welcome to the railway ticket booking System :%s",
             enteredUsername);
      flag = 1; // Return the index of the logged-in user
      return flag;
    } 
    else 
    {

      flag = -1; // Login failed
    }
  }
  if (flag == -1)
    printf("invalid username or password");
  return flag;
}

void searchbynumber() {
  FILE *fp2;
  int r, s, avl;
  printf("\nEnter the train  no you want to search  :");
  scanf("%d", &r);
  avl = avltrainno(r);
  if (avl == 0)
    printf("Train No %d is not available in the file\n", r);
  else {
    fp2 = fopen("Train_Record4", "r");
    printf("\n\n---------------------------------------------------------------"
           "-------------------------\n");
    printf("| TrainNo | TrainName         | Arrival    | Destination | "
           "TrainTime   | Seats Available |\n");
    printf("|---------|-------------------|------------|-------------|---------"
           "----|-----------------|\n");
    while (fread(&train, sizeof(train), 1, fp2)) {
      s = train.tno;
      if (s == r) {
        printf("| %-7d | %-17s | %-10s | %-11s | %d:%-9d | %-7d         |\n",
               train.tno, train.name, train.arrival, train.destination,
               train.hr, train.min, train.seatsAvailable);
      }
    }
    printf("-------------------------------------------------------------------"
           "------------------\n");
    fclose(fp2);
  }
}

int avltrainno(int rno) {
  FILE *fp;
  // int c = 0;
  fp = fopen("Train_Record4", "r");
  while (!feof(fp)) {
    fread(&train, sizeof(train), 1, fp);
    if (rno == train.tno) {
      fclose(fp);
      return 1;
    }
  }
  fclose(fp);
  return 0;
}
void searchbyname() {
  FILE *fp2;
  char sname[20];
  int c = 0;
  printf("\nEnter the name no you want to search  :");
  scanf("%s", sname);
  fp2 = fopen("Train_Record4", "r");
  printf("\n\n-----------------------------------------------------------------"
         "-----------------------\n");
  printf("| TrainNo | TrainName         | Arrival    | Destination | TrainTime "
         "  | Seats Available |\n");
  printf("|---------|-------------------|------------|-------------|-----------"
         "--|-----------------|\n");
  while (fread(&train, sizeof(train), 1, fp2)) {
    if (strcmp(sname, train.name) == 0) {
      printf("| %-7d | %-17s | %-10s | %-11s | %d:%-9d | %-7d         |\n",
             train.tno, train.name, train.arrival, train.destination, train.hr,
             train.min, train.seatsAvailable);
      c++;
    }
  }
  printf("\n\n-----------------------------------------------------------------"
         "-----------------------\n");
  if (c == 0) {
    printf("\n No records found with name %s", sname);
  } else {
    printf("\n %d Records found", c);
  }
  fclose(fp2);
}

void deletefile() {

  FILE *fpo;
  FILE *fpt;
  int r, s;
  int j;
  printf("Enter the Train no you want to delete :");
  scanf("%d", &r);
  j = avltrainno(r);
  if (j == 0) {
    printf("Train no %d is not available in the file\n", r);
  } else {
    fpo = fopen("Train_Record4", "r");
    fpt = fopen("TempFile2", "w");
    while (fread(&train, sizeof(train), 1, fpo)) {
      s = train.tno;
      if (s != r) {
        fwrite(&train, sizeof(train), 1, fpt);
      }
    }
    fclose(fpo);
    fclose(fpt);
    fpo = fopen("Train_Record4", "w");
    fpt = fopen("TempFile2", "r");
    while (fread(&train, sizeof(train), 1, fpt)) {
      fwrite(&train, sizeof(train), 1, fpo);
    }
    printf("\nRECORD DELETED\n");

    fclose(fpo);
    fclose(fpt);
  }
}

// FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty() {
  int c = 0;
  FILE *fp;
  fp = fopen("Train_Record4", "r");
  while (fread(&train, sizeof(train), 1, fp)) {
    c = 1;
  }
  fclose(fp);
  return c;
}

// update
void update() {
  int avl;
  FILE *fpt;
  FILE *fpo;
  int s, r, ch;
  printf("Enter train number to update:");
  scanf("%d", &r);
  avl = avltrainno(r);
  if (avl == 0) {
    printf("train number %d is not Available in the file", r);
  } else {
    fpo = fopen("Train_Record4", "r");
    fpt = fopen("TempFile2", "w");
    while (fread(&train, sizeof(train), 1, fpo)) {
      s = train.tno;
      if (s != r) {
        fwrite(&train, sizeof(train), 1, fpt);
      } else {
        printf("\n\t1. Update Time of Train %d", r);
        printf("\n\t2. Update No of seats of train  %d", r);
        printf("\n\t3. Update both Time and No of Seats %d", r);
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
          printf("Enter Time of Train in hours:");
          scanf("%d", &train.hr);
          printf("Enter Time of Train in minutes:");
          scanf("%d", &train.min);
          break;
        case 2:
          printf("Enter No of Seats: ");
          scanf("%d", &train.seatsAvailable);
          break;
        case 3:
          printf("Enter Time of Train in hours:");
          scanf("%d", &train.hr);
          printf("Enter Time of Train in mins:");
          scanf("%d", &train.min);

          printf("Enter No of Seats: ");
          scanf("%d", &train.seatsAvailable);
          break;
        default:
          printf("Invalid Selection");
          break;
        }
        fwrite(&train, sizeof(train), 1, fpt);
      }
    }
    fclose(fpo);
    fclose(fpt);
    fpo = fopen("Train_Record4", "w");
    fpt = fopen("TempFile2", "r");
    while (fread(&train, sizeof(train), 1, fpt)) {
      fwrite(&train, sizeof(train), 1, fpo);
    }
    fclose(fpo);
    fclose(fpt);
    printf("RECORD UPDATED");
  }
}

void book_ticket() 
{
  int y, us;
  disp();
  FILE *fp;
  fp = fopen("passenger2", "a");
  printf("\nEnter The train Number:");
  scanf("%d", &passenger->tno);
  printf("Enter the mobile No  :");
  scanf("%lld", &passenger->mobno);
  printf("Enter the Name of the Passenger:");
  scanf("%s", passenger->name);
  printf("Enter The last name:");
  scanf("%s", passenger->lastname);
  printf("Enter the passenger age:");
  scanf("%d", &passenger->age);
  printf("no.of tickets AvAilible at %d  ", passenger->tno);
  printf("\nTotal Seats Available=%d\n\n", train.seatsAvailable);

  printf("Enter The  no of ticket you want to book");
  scanf("%d", &passenger->booktickt);
  us = passenger->booktickt;
  y = live_seats(us);
  if (y == 0) {
    int take = passenger->booktickt;
    int ns = fare(take);
    printf("Amount is : %d", ns);

    fwrite(&passenger, sizeof(passenger), 1, fp);
    fclose(fp);

    FILE *fp1;
    fp1 = fopen("passenger2", "r");
    printf("\n\n| TrainNo | PassengerName   | PassengerLastName    | "
           "TicketBooked | PhoneNo  | Age |\n");
    printf("|---------|-----------------|----------------------|--------------|"
           "----------|-----|\n");
    while (fread(&passenger, sizeof(passenger), 1, fp1)) {
      printf("| %-7d | %-15s | %-20s | %-12d | %-8lld | %-3d |\n", passenger->tno,
             passenger->name, passenger->lastname, passenger->booktickt,
             passenger->mobno, passenger->age);
    }
    fclose(fp1);
  } else {
    printf("Unable to Book Ticket");
    fclose(fp);
  }
}

int fare(int no_tk) {
  int ns = 500 * no_tk;
  return ns;
}

int live_seats(int us) {
  int flag = 0;

  FILE *fpa;
  fpa = fopen("Train_Record4", "a");
  while (fread(&train, sizeof(train), 1, fpa)) 
  {
	//  if(us>0&&us<=50)
	  //{
    if (passenger->tno == train.tno)
    {
      train.seatsAvailable = train.seatsAvailable - us;
	printf("%d",train.seatsAvailable);
	  
		//fwrite(&train,sizeof(train),1,fpa);

      printf("Ticket Booked Successfully");
      flag = 0;
      break;
	}
    else
	{
		printf("No of seats enterrd is less than 0 or greater than 50");
	} 
	// }
  //  else
    //{
      //flag = 1;
    //}
  }
  if (flag == 1) {
    printf("Train Number is Wrong\n");
  }
  fclose(fpa);
  return flag;
}

void view_train() {
  printf("\n Train NO\t Train_Name\t Time \t fare");
  printf("\n 11111:\t Shatabdi Express\t  19:25 \t 500\n ");
  printf("\n 12222: Rajdhani Express  10:55  \t 500\n ");
  printf("\n 13333: Vande Bharat Express 12:29  \t 500\n ");
  printf("\n 14444: Maharajas'Express 10:55  \t 500\n ");
  printf("\n 12450: Intercity Express  05:59  \t 500\n ");
}

void sort() {
  int i, j;
  int size = get_no_of_record();
  struct train *p;
  struct train temp;
  p = (struct train *)calloc(size, sizeof(struct train));
  FILE *fpo;
  fpo = fopen("Train_Record4", "r");
  for (int i = 0; i < size; i++) {
    fread(p + i, sizeof(train), 1, fpo);
  }

  for (i = 0; i < size - 1; i++) {
    for (j = i + 1; j < size; j++) {
      if ((p + i)->tno > (p + j)->tno) {
        temp = *(p + i);
        *(p + i) = *(p + j);
        *(p + j) = temp;
      }
    }
  }
  printf("| TrainNo | TrainName      | Arrival    | Destination | TrainTime | "
         "Seats Available |\n");
  printf("|---------|----------------|------------|-------------|-----------|--"
         "---------------|\n");
  for (i = 0; i < size; i++) {
    printf("| %-7d | %-14s | %-10s | %-11s | %d:%-d \t  |%-7d          |\n",
           (p + i)->tno, (p + i)->name, (p + i)->arrival, (p + i)->destination,
           (p + i)->hr, (p + i)->min, (p + i)->seatsAvailable);
  }
  fclose(fpo);
}

int check() {
  char str1[20], str2[20];
  int flag = 0;
  printf("Enter Admin Username");
  scanf("%s", str1);
  printf("Enter Admin Password");
  scanf("%s", str2);
  if (strcmp(admin_name, str1) == 0) {
    if (strcmp(admin_pass, str2) == 0) {
      flag = 1;
    }
  }
  return flag;
}

int main() {
  int choice, emt;
  int ans;

  do {
    printmenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      userRegistration();
      break;
    case 2:
      currentUser = userLogin();
      break;
    case 3:
      ans = check();
      if (ans == 1) {
        insert();
      } else {
        printf("Enter Correct Id or Password To get Access");
      }
      break;
    case 4:
      if (currentUser != -1) {
        emt = empty();
        if (emt == 0)
          printf("The file is Empty");
        else
          disp();
      } else
        printf(" Please log in first");
      break;
    case 5:
      if (currentUser != -1) {
        searchbynumber();
      } else
        printf("Please log in first");
      break;
    case 6:
      if (currentUser != -1) {
        searchbyname();
      } else
        printf(" Please log in first");
      break;
    case 7:
      if (currentUser != -1) {
        ans = check();
        if (ans == 1) {
          deletefile();
        } else {
          printf("Enter Correct Id or Password To get Access");
        }
      } else
        printf(" Please log in first");
      break;
    case 8:
      if (currentUser != -1) {
        ans = check();
        if (ans == 1) {
          update();
        } else {
          printf("Enter Correct Id or Password To get Access");
        }
      } else
        printf("Please log in first");
      break;
    case 9:
      if (currentUser != -1) {
        book_ticket();
      } else
        printf("Please log in first");
      break;
    case 10:
      if (currentUser != -1) {
        sort();
      } else
        printf("Please log in first");
      break;
    case 11:
    printf("Code exited");
      exit(1);

      break;
    default:
      printf("invalid choice");
    }
  } while (choice != 11);
}