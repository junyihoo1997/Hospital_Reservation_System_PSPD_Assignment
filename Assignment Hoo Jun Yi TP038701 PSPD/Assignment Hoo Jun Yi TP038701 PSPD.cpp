// Assignment Hoo Jun Yi TP038701 PSPD.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<conio.h>
#include<string>
#include<Windows.h>
using namespace std;
void main();// Show the "Welcome to Hospital Reservation System"
void choice();// Let user to choose if he is doctor of admin
void login();//Login for doctor
void login2();//login for admin
void mainpage();// Show the doctor mainpage
void mainpage2();// Show the admin mainpage
void menu1(); // The menu that can see by doctor
void menu2();// The menu that can see by admin
void module1();// Let doctor to view patients
void module2();// Let doctor to view appointment
void module3();// Let admin to view patients
void module4();// Let admin to view appointment
void module5();//Add patient
void module6();//Delete patient
void module7();//Modify patient
void module8();//Search patient
void module9();//View patient
void module10();//Add appointment
void module11();//Delete appointment
void module12();//Modify appointment
void module13();//Search appointment
void module14();//View appointment
struct patient
{
	char patientid[20];
	char patientname[25];
	char patientsex[30];
	char patientage[35];
	char patientbloodtype[40];
	char patientaddress[45];
	char patientdiagnosis[50];
};
struct appointment
{
	char appointmentid[20];
	char doctorid[25];
	char appointmentdate[30];
	char patientdisease[35];
	char appointmentdescription[40];
};
struct patient z1;
struct appointment z2;
int i,j;
int cnt;
int flag;
char fp;
char password[25];
char password2[25];
string pass ="1234\r";
string pass2 ="12345\r";
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void main()
{
	gotoxy(15, 5);
	printf("\t**************************************************\n");
	gotoxy(15, 6);
	printf("\t*     Welcome to Hospital Reservation System     *\n");
	gotoxy(15, 7);
	printf("\t**************************************************\n");
	choice();
}
void choice()// To choose doctor or admin
{
	int code;
	gotoxy(15, 7);
	printf("\n\t\t*1. Doctor                                       *");
	gotoxy(15, 8);
	printf("\n\t\t*2. Admin                                        *");
	gotoxy(15, 9);
	printf("\n\t\t*3. Exit                                         *");
	gotoxy(15, 11);
	printf("\t**************************************************\n");
	gotoxy(15, 12);
	printf("\n\t\tWho are you?\t");
	scanf("%d", &code);
	switch (code)
	{
	case 1:
		printf("\t\tYou have chosen Doctor.\n");
		login();
		break;
	case 2:
		printf("\t\tYou have chosen Admin.\n");
		login2();
		break;
	case 3:
		exit(0);
	default:
		printf("\t\tThat's not an answer! Press any key to exit.\n");
		getch();
		exit(0);
	}
	getch();
}
void login() //Doctor part
{
	for (cnt = 0; cnt < 3; cnt++)
	{
		printf("\t\tEnter your Password: ");
		for (i = 0;i < 25;i++)
		{
			password[i] = '\0';
		}
		i = 0;
		password[0] = _getch();
		while (password[i] != 13)
		{
			i++;
			printf("*");
			password[i] = _getch();
		}
		if (pass != password)
		{
			printf("\n\t\tLog in fail\n");
			getch();
		}
		else
		{
			printf("\n\t\tLog in success!");
			getch();
			system("cls");
			mainpage();
			break;
		}
	}
}
void login2() //Admin login part
{
	for (cnt = 0; cnt < 3; cnt++)
	{
		printf("\t\tEnter your Password: ");
		for (i = 0;i < 25;i++)
		{
			password2[i] = '\0';
		}
		i = 0;
		password2[0] = _getch();
		while (password2[i] != 13)
		{
			i++;
			printf("*");
			password2[i] = _getch();
		}
		j = strlen(password2);
		if (pass2 != password2)
		{
			printf("\n\t\tLog in fail\n");
			getch();
		}
		else
		{

			printf("\n\t\tLog in success!");
			getch();
			system("cls");
			mainpage2();
		}
	}
}
void mainpage() // Doctor main menu
{
	gotoxy(15, 5);
	printf("\t**************************************************\n");
	gotoxy(15, 6);
	printf("\t*     Welcome to main menu of the system         *\n");
	gotoxy(15, 7);
	printf("\t**************************************************\n");
	menu1();
}
void mainpage2() // Admmin main menu
{
	gotoxy(15, 5);
	printf("\t**************************************************\n");
	gotoxy(15, 6);
	printf("\t*     Welcome to main menu of the system         *\n");
	gotoxy(15, 7);
	printf("\t**************************************************\n");
	menu2();
}
void menu1() // Doctor menu
{
	int code;
	int zz;
	gotoxy(15, 7);
	printf("\n\t\t*1. View Patient Details                         *");
	gotoxy(15, 8);
	printf("\n\t\t*2. View Appointment                             *");
	gotoxy(15, 9);
	printf("\n\t\t*3. Exit                                         *");
	gotoxy(15, 10);
	printf("\n\t\t*4. Return to login page                         *");
	gotoxy(15, 12);
	printf("\t**************************************************\n");
	gotoxy(15, 13);
	printf("\n\t\tChoose Your Option\n");
	gotoxy(15, 15);
	printf("\tEnter your option:");
	scanf("%d", &code);
	switch (code)
	{
	case 1:
		printf("\t\tYou have chosen to view the patient details. \n\t\tPress any key to continue.\n\n");
		getch();
		system("cls");
		module1();
		printf("\n\t\tDo you wish to go back?:");
		printf("\n\t\t1. Yes \n\t\t2.No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			mainpage();
		}
		else
		{
			break;
		}
		break;
	case 2:
		printf("\t\tYou have chosen to view the appointment. \n\t\tPress any key to continue\n\n");
		getch();
		system("cls");
		module2();
		printf("\n\t\tDo you wish to go back?:");
		printf("\n\t\t1. Yes \n\t\t2. No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			mainpage();
		}
		else
		{
			break;
		}
		break;
	case 3:
		exit(0);
		break;
	case 4:
		system("cls");
		main();
		break;
	default:
		printf("\t\tThat's not an option!\n");
		getch();
	}
	getch();
}
void menu2()// Admin menu
{
	int code;
	gotoxy(15, 7);
	printf("\n\t\t*1. Patient                                      *");
	gotoxy(15, 8);
	printf("\n\t\t*2. Appointment                                  *");
	gotoxy(15, 9);
	printf("\n\t\t*3. Exit                                         *");
	gotoxy(15, 10);
	printf("\n\t\t*4. Return to login page                         *");
	gotoxy(15, 11);
	printf("\n\t\t*Choose Your Option                              *\n");
	gotoxy(15, 13);
	printf("\t**************************************************\n");
	gotoxy(15, 14);
	printf("\tEnter your option: ");
	scanf("%d", &code);
	switch (code)
	{
	case 1:
		printf("\t\tYou have chosen patient. Press any key to continue.\n\n");
		getch();
		system("cls");
		module3();
		break;
	case 2:
		printf("\t\tYou have chosen appointment. Press any key to continue\n\n");
		getch();
		system("cls");
		module4();
		break;
	case 3:
		exit(0);
		break;
	case 4:
		system("cls");
		main();
		break;
	default:
		printf("\t\tThat's not an option!\n");
		getch();
	}
	getch();
}
void module1() // This is doctor part
{
	gotoxy(15, 5);
	printf("\t\t***********************************\n");
	gotoxy(15, 6);
	printf("\t\t*              Patients           *\n");
	gotoxy(15, 7);
	printf("\t\t***********************************\n\n");
	FILE *viewpatient;
	struct patient detail;
	fseek(stdin, 0, SEEK_END);
	char PD;
	viewpatient = fopen("patientlist.txt", "r");
	if (viewpatient == NULL)
	{
		printf("\n\t\tCant find or open the file");
	}
	else
	{
		while (fread(&detail, sizeof(detail), 1, viewpatient) == 1)
		{
			printf("\n\t\t\tPatient ID:%s", detail.patientid);
			printf("\n\t\t\tPatient Name:%s", detail.patientname);
			printf("\n\t\t\tPatient Address:%s", detail.patientaddress);
			printf("\n\t\t\tPatient Blood Type:%s", detail.patientbloodtype);
			printf("\n\t\t\tPatient Diagnosis:%s", detail.patientdiagnosis);
			printf("\n\t\t\tPatient Sex:%s", detail.patientsex);
			printf("\n\t\t\tPatient Age:%s\n\n", detail.patientage);
		}
		fclose(viewpatient);
	}
}
void module2()// This is doctor part
{
	gotoxy(15, 5);
	printf("\t\t***********************************\n");
	gotoxy(15, 6);
	printf("\t\t*              Appointment        *\n");
	gotoxy(15, 7);
	printf("\t\t***********************************\n\n");
	FILE *viewappointment;
	struct appointment detail;
	fseek(stdin, 0, SEEK_END);
	char PD;
	viewappointment = fopen("appointmentlist.txt", "r");
	if (viewappointment == NULL)
	{
		printf("\n\t\tCant find or open the file");
	}
	else
	{
		while (fread(&detail, sizeof(detail), 1, viewappointment) == 1)
		{
			printf("\n\t\t\tAppointment ID:%s", detail.appointmentid);
			printf("\n\t\t\tDoctor ID:%s", detail.doctorid);
			printf("\n\t\t\tAppointment Date:%s", detail.appointmentdate);
			printf("\n\t\t\tPatient Disease:%s", detail.patientdisease);
			printf("\n\t\t\tAppointment Description:%s\n\n", detail.appointmentdescription);
		}
		fclose(viewappointment);
	}
}
void module3()// This is admin part
{
	int choice;
	int zz; // choice for go back 
	gotoxy(15, 5);
	printf("\t\t***********************************\n");
	gotoxy(15, 6);
	printf("\t\t*              Patients           *\n");
	gotoxy(15, 7);
	printf("\t\t***********************************\n\n");
	gotoxy(15, 8);
	printf("\t\t*     Select one from below       *\n");
	gotoxy(15, 9);
	printf("\t\t*                                 *\n");
	gotoxy(15, 10);
	printf("\t\t*1. Add patient                   *\n");
	gotoxy(15, 11);
	printf("\t\t***********************************\n");
	gotoxy(15, 12);
	printf("\t\t*2. Delete patient                *\n");
	gotoxy(15, 13);
	printf("\t\t***********************************\n");
	gotoxy(15, 14);
	printf("\t\t*3. Modify patient                *\n");
	gotoxy(15, 15);
	printf("\t\t***********************************\n");
	gotoxy(15, 16);
	printf("\t\t*4. Search patient                *\n");
	gotoxy(15, 17);
	printf("\t\t***********************************\n");
	gotoxy(15, 18);
	printf("\t\t*5. View patient                  *\n");
	gotoxy(15, 19);
	printf("\t\t***********************************\n");
	gotoxy(15, 20);
	printf("\t\t*6. Back to menu                  *\n");
	gotoxy(15, 21);
	printf("\t\t***********************************\n");
	gotoxy(15, 22);
	printf("\t\t*7. Exit                          *\n");
	gotoxy(15, 23);
	printf("\t\t***********************************\n");
	gotoxy(15, 25);
	printf("\t\tEnter your option: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\t\tYou have chosen add patient. Press any key to continue.\n\n");
		getch();
		system("cls");
		module5();
		printf("\n\t\tDo you want to go back to patient page?:");
		printf("\n\t\t1. Yes \n\t\t2. No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module3();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 2:
		printf("\t\tYou have chosen delete patient. Press any key to continue\n\n");
		getch();
		system("cls");
		module6();
		printf("\n\t\tDo you want to go back to patient page?:");
		printf("\n\t\t1. Yes \n\t\t2. No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module3();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 3:
		printf("\t\tYou have chosen modify patient. Press any key to continue\n\n");
		getch();
		system("cls");
		module7();
		printf("\n\t\tDo you want to go back to patient page?:");
		printf("\n\t\t1. Yes \n\t\t2. No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module3();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 4:
		printf("\t\tYou have chosen search patient. Press any key to continue\n\n");
		getch();
		system("cls");
		module8();
		printf("\n\t\tDo you want to go back to patient page?:");
		printf("\n\t\t1. Yes \n\t\t2. No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module3();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 5:
		printf("\t\tYou have chosen view patient. Press any key to continue\n\n");
		getch();
		system("cls");
		module9();
		printf("\n\t\tDo you want to go back to patient page?:");
		printf("\n\t\t1. Yes \n\t\t2. No\n\t\t");
		scanf("%d",&zz);
		if (zz == 1)
		{
			system("cls");
			module3();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
		break;
	case 6:
		printf("\t\tYou have wish to go back to menu. Press any key to continue\n\n");
		getch();
		system("cls");
		printf("\n\t\tDo you really want to go back to menu page?:");
		printf("\n\t\t1. Yes \n\t\t2. No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			mainpage2();
		}
		if (zz == 2)
		{
			printf("You going to be exit. Press any key to continue. ");
			getch();
			exit(0);
		}
		else
		{
			printf("Invalid Input! You going to be exit. Press any key to continue.");
			getch();
			exit(0);
		}
		case 7:
		exit(0);
		break;
	default:
		printf("\t\tThat's not an option!\n");
		getch();
	}
	system("cls");
}
void module4() // This is admin part
{
	int(choice);
	int(zz);
	gotoxy(15, 5);
	printf("\t\t***********************************\n");
	gotoxy(15, 6);
	printf("\t\t*              Appointment        *\n");
	gotoxy(15, 7);
	printf("\t\t***********************************\n\n");
	gotoxy(15, 8);
	printf("\t\t*       Select one from below     *\n");
	gotoxy(15, 9);
	printf("\t\t*                                 *\n");
	gotoxy(15, 10);
	printf("\t\t*1. Add appointment               *\n");
	gotoxy(15, 11);
	printf("\t\t***********************************\n");
	gotoxy(15, 12);
	printf("\t\t2. Delete appointment             *\n");
	gotoxy(15, 13);
	printf("\t\t***********************************\n");
	gotoxy(15, 14);
	printf("\t\t3. Modify appointment             *\n");
	gotoxy(15, 15);
	printf("\t\t***********************************\n");
	gotoxy(15, 16);
	printf("\t\t4. Search appointment             *\n");
	gotoxy(15, 17);
	printf("\t\t***********************************\n");
	gotoxy(15, 18);
	printf("\t\t5. View appointment               *\n");
	gotoxy(15, 19);
	printf("\t\t***********************************\n");
	gotoxy(15, 20);
	printf("\t\t6. Back to menu                   *\n");
	gotoxy(15, 21);
	printf("\t\t***********************************\n");
	gotoxy(15, 22);
	printf("\t\t7. Exit                           *\n");
	gotoxy(15, 23);
	printf("\t\t***********************************\n");
	gotoxy(15, 25);
	printf("\t\tEnter your option:");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\t\tYou have chosen add appointment. Press any key to continue.\n\n");
		getch();
		system("cls");
		module10();
		printf("\n\t\tDo you wish to go back to appointment page?: ");
		printf("\n\t\t1.Yes \n\t\t2.No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module4();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 2:
		printf("\t\tYou have chosen delete appointment. Press any key to continue\n\n");
		getch();
		system("cls");
		module11();
		printf("\n\t\tDo you wish to go back to appointment page?: ");
		printf("\n\t\t1.Yes \n\t\t2.No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module4();
		}
		if(zz==2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 3:
		printf("\t\tYou have chosen modify appointment. Press any key to continue\n\n");
		getch();
		system("cls");
		module12();
		printf("\n\t\tDo you wish to go back to appointment page?: ");
		printf("\n\t\t1.Yes \n\t\t2.No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module4();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 4:
		printf("\t\tYou have chosen search appointment. Press any key to continue\n\n");
		getch();
		system("cls");
		module13();
		printf("\n\t\tDo you wish to go back to appointment page?: ");
		printf("\n\t\t1.Yes \n\t\t2.No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module4();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 5:
		printf("\t\tYou have chosen view appointment. Press any key to continue\n\n");
		getch();
		system("cls");
		module14();
		printf("\n\t\tDo you wish to go back to appointment page?: ");
		printf("\n\t\t1.Yes \n\t\t2.No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			module4();
		}
		if (zz == 2)
		{
			system("cls");
			mainpage2();
		}
		else
		{
			printf("Invalid input! Press any key to go back to the mainpage.");
			getch();
			system("cls");
			mainpage2();
		}
	case 6:
		printf("\t\tYou have wish to go back to menu. Press any key to continue\n\n");
		getch();
		system("cls");
		printf("\n\t\tDo you really want to go back to menu page?:");
		printf("\n\t\t1.Yes");
		printf("\n\t\t2.No\n\t\t");
		scanf("%d", &zz);
		if (zz == 1)
		{
			system("cls");
			mainpage2();
		}
		if (zz == 2)
		{
			printf("You going to be exit. Press any key to continue. ");
			getch();
			exit(0);
		}
		else
		{
			printf("Invalid Input! You going to be exit. Press any key to continue.");
			getch();
			exit(0);
		}
	case 7:
		exit(0);
		break;
	default:
		printf("That's not an option!\n");
		getch();
	}
	system("cls");
	module4();
}
void module5()//Add patient
{
	gotoxy(15, 5);
	printf("\t\t*********************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Add Patient                 *\n");
	gotoxy(15, 7);
	printf("\t\t*********************************************\n");
	char fp;
	FILE *addpatient;
	addpatient = fopen("patientlist.txt", "a");//Add
	struct patient z1;
	fseek(stdin, 0, SEEK_END);
	printf("\n\t\t\tEnter patient id:");
	scanf("%[^\n]%*c", &z1.patientid);
	if (flag = 0);
	{
		while (fwrite(&z1, sizeof(z1), 1, addpatient) == 1)
		{
			if (strcmp(z1.patientid, z1.patientid) == 0)
			{
				flag = 1;
			}
		}
	}
	printf("\n\t\t\tEnter patient name:");
	scanf("%[^\n]%*c", &z1.patientname);
	printf("\n\t\t\tEnter patient gender:");
	scanf("%[^\n]%*c", &z1.patientsex);
	printf("\n\t\t\tEnter patient age:");
	scanf("%[^\n]%*c", &z1.patientage);
	printf("\n\t\t\tEnter patient blood group:");
	scanf("%[^\n]%*c", &z1.patientbloodtype);
	printf("\n\t\t\tEnter patient address:");
	scanf("%[^\n]%*c", &z1.patientaddress);
	printf("\n\t\t\tEnter patient diagnosis:");
	scanf("%[^\n]%*c", &z1.patientdiagnosis);
	fwrite(&z1, sizeof(z1), 1, addpatient);
	fclose(addpatient);
	getch();
};
void module6()//Delete patient
{
	gotoxy(15, 5);
	printf("\t\t*********************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Delete Patient              *\n");
	gotoxy(15, 7);
	printf("\t\t*********************************************\n");
	{
		FILE*deletepatient, *patientbackup;
		deletepatient = fopen("patientlist.txt", "r+"); // For read
		patientbackup = fopen("newdeletedpatient.txt", "wb+");
		char deleteid[20];
		printf("\n\t\t\tEnter the ID: ");
		scanf("%s", &deleteid);
		while (fread(&z1, sizeof(z1), 1, deletepatient) == 1)
		{
			if (strcmp(deleteid, z1.patientid) != 0)
			{
				fwrite(&z1, sizeof(z1), 1, patientbackup);
			}
		}
		fclose(deletepatient);
		fclose(patientbackup);
		remove("patientlist.txt");
		rename("newdeletedpatient.txt", "patientlist.txt");
		printf("\t\t\tDeleted patient!");
		getch();
	}
	getch();
}
void module7()//Modify patient
{
	gotoxy(15, 5);
	printf("\t\t*********************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Modify Patient              *\n");
	gotoxy(15, 7);
	printf("\t\t*********************************************\n");
	FILE *modifypatient, *patientbackup;
	char pid[20];
	modifypatient = fopen("patientlist.txt", "r+");
	patientbackup = fopen("newdeletedpatient.txt", "wb+");
	printf("\t\t\tEnter Patient ID: ");
	scanf("%s", &pid);
	rewind(modifypatient);
	if (modifypatient == NULL)
	{
		printf("\n\t\t\tCant find or open the file");
	}
	else
	{
		while (fread(&z1, sizeof(z1), 1, modifypatient) == 1)
		{
			if (strcmp(pid, z1.patientid) == 0)
			{
				fseek(stdin, 0, SEEK_END);
				printf("\n\t\t\tEnter new patient id:");
				scanf("%[^\n]%*c", &z1.patientid);
				printf("\n\t\t\tEnter new patient name:");
				scanf("%[^\n]%*c", &z1.patientname);
				printf("\n\t\t\tEnter new patient gender:");
				scanf("%[^\n]%*c", &z1.patientsex);
				printf("\n\t\t\tEnter new patient age:");
				scanf("%[^\n]%*c", &z1.patientage);
				printf("\n\t\t\tEnter new patient blood group:");
				scanf("%[^\n]%*c", &z1.patientbloodtype);
				printf("\n\t\t\tEnter new patient address:");
				scanf("%[^\n]%*c", &z1.patientaddress);
				printf("\n\t\t\tEnter new patient diagnosis:");
				scanf("%[^\n]%*c", &z1.patientdiagnosis);
				fwrite(&z1, sizeof(z1), 1, patientbackup);
			}
			else
			{
				fwrite(&z1, sizeof(z1), 1, patientbackup);
			}
		}
		fclose(modifypatient);
		fclose(patientbackup);
		remove("patientlist.txt");
		rename("newdeletedpatient.txt", "patientlist.txt");
		printf("\t\t\tDone Edit patient!");
		getch();
	}
}
void module8()//Search patient
{
	gotoxy(15, 5);
	printf("\t\t*********************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Search Patient              *\n");
	gotoxy(15, 7);
	printf("\t\t*********************************************\n");
	FILE *searchpatient;
	struct patient detail;
	fseek(stdin, 0, SEEK_END);
	char pid[20];
	int cnt;
	cnt = 0;
	searchpatient = fopen("patientlist.txt", "r");
	printf("\t\t\tEnter Patient ID: ");
	scanf("%s", &pid);
	if (searchpatient == NULL)
	{
		printf("\n Cant find or open the file");
	}
	else
	{
		while (fread(&detail, sizeof(detail), 1, searchpatient) == 1)
		{
			if (strcmp(pid, detail.patientid) == 0)
			{
				printf("\n\t\t\tPatient ID:%s", detail.patientid);
				printf("\n\t\t\tPatient Address:%s", detail.patientaddress);
				printf("\n\t\t\tPatient Blood Type:%s", detail.patientbloodtype);
				printf("\n\t\t\tPatient Diagnosis:%s", detail.patientdiagnosis);
				printf("\n\t\t\tPatient Sex:%s", detail.patientsex);
				printf("\n\t\t\tPatient Age:%s\n\n", detail.patientage);
				printf("\t\t\tPress any key to continue!");
				cnt++;
			}
		}
		if (cnt == 0)
		{
			printf("\t\t\tThis is not the ID you look for!");
		}
		fclose(searchpatient);
	}
	getch();
}
void module9()//view patient
{
	gotoxy(15, 5);
	printf("\t\t*********************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               View Patient                *\n");
	gotoxy(15, 7);
	printf("\t\t*********************************************\n");
	FILE *viewpatient;
	struct patient detail;
	fseek(stdin, 0, SEEK_END);
	char PD;
	viewpatient = fopen("patientlist.txt", "r");
	if (viewpatient == NULL)
	{
		printf("\n Cant find or open the file");
	}
	else
	{
		while (fread(&detail, sizeof(detail), 1, viewpatient) == 1)
		{
			printf("\n\t\t\tPatient ID:%s", detail.patientid);
			printf("\n\t\t\tPatient Name:%s", detail.patientname);
			printf("\n\t\t\tPatient Address:%s", detail.patientaddress);
			printf("\n\t\t\tPatient Blood Type:%s", detail.patientbloodtype);
			printf("\n\t\t\tPatient Diagnosis:%s", detail.patientdiagnosis);
			printf("\n\t\t\tPatient Sex:%s", detail.patientsex);
			printf("\n\t\t\tPatient Age:%s\n\n", detail.patientage);
		}
		fclose(viewpatient);
	}
	getch();
}
void module10()//add appointment
{
	gotoxy(15, 5);
	printf("\t\t*************************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Add Appointment                 *\n");
	gotoxy(15, 7);
	printf("\t\t*************************************************\n");
	FILE *addappointment;
	addappointment = fopen("appointmentlist.txt", "a");//Add appointment
	struct appointment z2;
	fseek(stdin, 0, SEEK_END);
	printf("\n\t\t\tEnter appointment id:");
	scanf("%[^\n]%*c", &z2.appointmentid);
	printf("\n\t\t\tEnter doctor ID:");
	scanf("%[^\n]%*c", &z2.doctorid);
	printf("\n\t\t\tEnter appointment date:");
	scanf("%[^\n]%*c", &z2.appointmentdate);
	printf("\n\t\t\tEnter patient disease:");
	scanf("%[^\n]%*c", &z2.patientdisease);
	printf("\n\t\t\tEnter appointment description:");
	scanf("%[^\n]%*c", &z2.appointmentdescription);
	fwrite(&z2, sizeof(z2), 1, addappointment);
	fclose(addappointment);
	getch();
};
void module11()// Delete appointment
{
	gotoxy(15, 5);
	printf("\t\t*************************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Delete Appointment              *\n");
	gotoxy(15, 7);
	printf("\t\t*************************************************\n");
	{
		FILE*deleteappointment, *deletebackup;
		deleteappointment = fopen("appointmentlist.txt", "r+"); // For read
		deletebackup = fopen("newdeletedappointment.txt", "wb+");
		char deleteid[20];
		printf("\n\t\t\tEnter the ID: ");
		scanf("%s", &deleteid);
		while (fread(&z2, sizeof(z2), 1, deleteappointment) == 1)
		{
			if (strcmp(deleteid, z2.appointmentid) != 0)
			{
				fwrite(&z2, sizeof(z2), 1, deletebackup);
			}
		}
		fclose(deleteappointment);
		fclose(deletebackup);
		remove("appointmentlist.txt");
		rename("newdeletedappointment.txt", "appointmentlist.txt");
		printf("\t\t\tDeleted appointment!");
		getch();
	}
}
void module12()//Modify appointment
{
	gotoxy(15, 5);
	printf("\t\t*************************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Modify Appointment              *\n");
	gotoxy(15, 7);
	printf("\t\t*************************************************\n");
	FILE*modifyappointment, *modifybackup;
	char appointmentid[20];
	modifyappointment = fopen("appointmentlist.txt", "r+");
	modifybackup = fopen("newdeletedappointment.txt", "wb+");
	printf("\n\t\t\tEnter the ID: ");
	scanf("%s", &appointmentid);
	rewind(modifyappointment);
	if (modifyappointment == NULL)
	{
		printf("\n\t\t\tCant find or open the file");
	}
	else
	{
		while (fread(&z2, sizeof(z2), 1, modifyappointment) == 1)
		{
			if (strcmp(appointmentid, z2.appointmentid) == 0)
			{
				fseek(stdin, 0, SEEK_END);
				printf("\n\t\t\tEnter new appointment id:");
				scanf("%[^\n]%*c", &z2.appointmentid);
				printf("\n\t\t\tEnter new doctor ID:");
				scanf("%[^\n]%*c", &z2.doctorid);
				printf("\n\t\t\tEnter new appointment date:");
				scanf("%[^\n]%*c", &z2.appointmentdate);
				printf("\n\t\t\tEnter new patient disease:");
				scanf("%[^\n]%*c", &z2.patientdisease);
				printf("\n\t\t\tEnter new appointment description:");
				scanf("%[^\n]%*c", &z2.appointmentdescription);
				fwrite(&z2, sizeof(z2), 1, modifybackup);
			}
			else
			{
				fwrite(&z2, sizeof(z2), 1, modifybackup);
			}
		}
		getch();
		fclose(modifyappointment);
		fclose(modifybackup);
		remove("appointmentlist.txt");
		rename("newdeletedappointment.txt", "appointmentlist.txt");
		printf("\t\t\tDone Edit Appointment!");
	}
}
void module13()//Search appointment
{
	gotoxy(15, 5);
	printf("\t\t*************************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               Search Appointment              *\n");
	gotoxy(15, 7);
	printf("\t\t*************************************************\n");
	FILE *searchappointment;
	struct appointment detail;
	searchappointment = fopen("appointmentlist.txt", "r");//Add appointment
	fseek(stdin, 0, SEEK_END);
	char appointmentid[20];
	int cnt;
	cnt = 0;
	searchappointment = fopen("appointmentlist.txt", "r");
	printf("\t\t\tEnter Appointment ID: ");
	scanf("%s", &appointmentid);
	if (searchappointment == NULL)
	{
		printf("\n Can't find or open the file");
	}
	else
	{
		while (fread(&detail, sizeof(detail), 1, searchappointment) == 1)
		{
			if (strcmp(appointmentid, detail.appointmentid) == 0)
			{
				printf("\n\t\t\tAppointment ID:%s", detail.appointmentid);
				printf("\n\t\t\tDoctor ID:%s", detail.doctorid);
				printf("\n\t\t\tAppointment Date:%s", detail.appointmentdate);
				printf("\n\t\t\tPatient Disease:%s", detail.patientdisease);
				printf("\n\t\t\tAppointment Description:%s\n\n", detail.appointmentdescription);
				printf("\t\t\tPress any key to continue!");
				cnt++;
			}
		}
		if (cnt == 0)
		{
			printf("This is not the ID you look for!");
		}
		fclose(searchappointment);
	}
	getch();
}
void module14()//View appointment
{
	gotoxy(15, 5);
	printf("\t\t*************************************************\n");
	gotoxy(15, 6);
	printf("\t\t*               View Appointment                *\n");
	gotoxy(15, 7);
	printf("\t\t*************************************************\n");
	FILE *viewappointment;
	struct appointment detail;
	fseek(stdin, 0, SEEK_END);
	char PD;
	viewappointment = fopen("appointmentlist.txt", "r");
	if (viewappointment == NULL)
	{
		printf("\n Cant find or open the file");
	}
	else
	{
		while (fread(&detail, sizeof(detail), 1, viewappointment) == 1)
		{
			printf("\n\t\t\tAppointment ID:%s", detail.appointmentid);
			printf("\n\t\t\tDoctor ID:%s", detail.doctorid);
			printf("\n\t\t\tAppointment Date:%s", detail.appointmentdate);
			printf("\n\t\t\tPatient Disease:%s", detail.patientdisease);
			printf("\n\t\t\tAppointment Description:%s\n\n", detail.appointmentdescription);
		}
		fclose(viewappointment);
	}
	getch();
}

