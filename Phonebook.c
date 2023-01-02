#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>

#define MAX_SIZE 100

typedef struct
{
    char Name[40];
    char Number[20];
} Contact;

typedef enum{NAME,NUMBER} search_t;

Contact phonebook[MAX_SIZE];

int currentSize= 0;

void stat();
void addEntry();
void display(int index);
void displayall();
void search(char *key, search_t type);
void strtolower(char *str);
void savetofile();
void readfromfile();
void removeentry(char *number);
void clear();
int main()
{
    PlaySound(TEXT("welcome.wav"),NULL,SND_SYNC);
    stat();
    readfromfile();
    char selection[20];
    int choice;

    while(1){
    system("color b0");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t#_____________________________________#\n");
    printf("\t\t\t\t\t|-------------------------------------|\n");
    printf("\t\t\t\t\t|     PHONE BOOK APPLICATION          |\n");
    printf("\t\t\t\t\t|-------------------------------------|\n");
    printf("\t\t\t\t\t|                                     |\n");
    printf("\t\t\t\t\t|     [1]  Add Contacts               |\n");
    printf("\t\t\t\t\t|     [2]  Display All Contacts       |\n");
    printf("\t\t\t\t\t|     [3]  Search by Name             |\n");
    printf("\t\t\t\t\t|     [4]  Search by Namber           |\n");
    printf("\t\t\t\t\t|     [5]  Delete a contact(By Number)|\n");
    printf("\t\t\t\t\t|     [6]  Save Database              |\n");
    printf("\t\t\t\t\t|-------------------------------------|\n");
    printf("\t\t\t\t\t|     [7]  Exite                      |\n");
    printf("\t\t\t\t\t|_____________________________________|\n");
    do{

        printf("\n\t\t\t\t\tEnter your Choice: ");
        gets(selection);
        choice=atoi(selection);
    }while(choice<1 || choice>7);

    switch(choice){
        case 1:
        Beep(1200,500);
        system("color 37");
        addEntry();
        clear();
        break;
        case 2:
        Beep(1200,500);
        system("color e0");
        displayall();
        clear();
        break;
        case 3:
        Beep(1200,500);
        system("color ED");
        printf("\n\t\t\t\t\tEnter Name to search:");
        gets(selection);
        search(selection,NAME);
        clear();
        break;
        system("color ED");
        case 4:
        Beep(1200,500);
        printf("\n\t\t\t\t\tEnter Number to search:");
        gets(selection);
        search(selection,NUMBER);
        clear();
        break;
        case 5:
        Beep(1200,500);
        system("color 47");
        printf("\n\t\t\t\t\tEnter Number to delete:");
        gets(selection);
        removeentry(selection);
        clear();
        break;
        case 6:
        Beep(1200,500);
        savetofile();
        clear();
        break;
        case 7:
        Beep(1500,500);
        exit(0);
        break;
        default:
        break;
    }
    }

return 0;
}

void addEntry(){
    if(currentSize==MAX_SIZE){
        puts("Error: Phonebook id full!");
        return;
    }

    Contact c;
    printf("\n\t\t\t\t\ttEnter First Name: ");
    gets(c.Name);
    printf("\n\t\t\t\t\tEnter Mobile Number: ");
    gets(c.Number);

    phonebook[currentSize]=c;
    currentSize++;
}

void display(int index){
    if(index<0 || index>=currentSize){
        puts("Error: invalid index!");
        return;
    }
    Contact c=phonebook[index];
    printf("\n\t\t\t\t\tFull Name:%s\n",c.Name);
    printf("\n\t\t\t\t\tMobile Number:%s\n",c.Number);
}

void displayall(){
    int i;
    for(i=0;i<currentSize;i++){
            display(i);
            printf("\n");
        }
}


void strtolower(char *str){
    int len=strlen(str);
    int i;
    for(i=0;i<len;i++){
        str[i]=tolower(str[i]);
    }
}

void search(char *key, search_t type){
    int found=0;
    int i;

    strtolower(key);
    char content[41];

    if(type==NAME){
        for(i=0;i<currentSize;i++){
            strcpy(content,phonebook[i].Name);
            strtolower(content);
            if(strcmp(content,key)==0){
                display(i);
                found=1;
            }
        }
    }
    else if(type==NUMBER){
        for(i=0;i<currentSize;i++){
            strcpy(content,phonebook[i].Number);
            strtolower(content);
            if(strcmp(content,key)==0){
                display(i);
                found=1;
            }
        }
    }
    else{
        puts("Error: invalid Search!");
        return;
    }

    if(!found){
        puts("Not found in the phonebook");
    }
}


void removeentry(char *number){
    int i,j;
    int count=0;
    for(i=0;i<currentSize;i++){
        if(strcmp(phonebook[i].Number,number)==0){
            strcmp(phonebook[j].Name,"");
            strcmp(phonebook[i].Number,"");

            currentSize-=1;
            count++;
        }
    }
    if(count==0){
        puts("No Entry Deleted");
    }
    else{
        printf("%d Entries deleted\n",count);
    }
}

void readfromfile(){
    FILE *fp;
    if((fp=fopen("phonebook.txt","r"))==NULL){
        puts("Error: can't create a database file!");
        return;
    }
    if(fread(&currentSize,sizeof(currentSize),1,fp)!=1){
        //puts("Error: can't read data!");
        return;
    }
    if(fread(phonebook,sizeof(phonebook),1,fp)!=1){
        //puts("Error: can't read data!");
        return;
    }
}

void savetofile(){
    FILE *fp;
    if((fp=fopen("phonebook.txt","w"))==NULL){
        puts("Error: can't create a database file!");
        return;
    }
    if(fwrite(&currentSize,sizeof(currentSize),1,fp)!=1){
        puts("Error: can't save data!");
        return;
    }
    if(fwrite(phonebook,sizeof(phonebook),1,fp)!=1){
        puts("Error: Can't save data!");
        return;
    }
}

void clear(){
    system("PAUSE");
    system("CLS");
}

 void stat(){

    system(" color 0B");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t-------------------------------------\n\n");
    printf("\t\t\t\t\t    PHONE BOOK CONSOLE APPLICATION\n\n");
    printf("\t\t\t\t\t-------------------------------------\n\n");
    printf("\t\t\t\t\t Loading");
    char x= 219;
    for (int i=0;i<35;i++ ){

        printf("%c",x);
        if(i<10)
            Sleep(300);
        if(i>=10 && i<20)
            Sleep(150);
        if(i>=10)
            Sleep(25);
    }
    system("cls");

}
