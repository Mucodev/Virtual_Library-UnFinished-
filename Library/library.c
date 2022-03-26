#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define N 300
int g=0;
FILE *file;

void menu();
void show_books();
void add_book();
void delete_book();
void get_info();
void sort();

struct Books
{
    char name[20];
    char surname[20];
    char book_name[100];
    char page_number[10];
}Book[N];

// void gae()
// {
//     gets(Book[g].name);
//     gets(Book[g].surname);
//     gets(Book[g].book_name);
//     gets(Book[g].page_number);
//     g++;
// }
// void gae_2()
// {
//     int i;
//     for (i=0;i<g;i++){
//         printf("%s %s %s %s", Book[i].name, Book[i].surname, Book[i].book_name, Book[i].page_number);        
//     }
// }

int main(){
    menu();
    return 0;
}

void menu(){
    char a;

    printf("1-Show Books\n");
    printf("2-Add Book\n");
    printf("3-Delete Book\n");
 
    printf(">>>\n");
	a = getch();
    
    if(a=='1'){
        show_books();
    }
    else if(a=='2'){
        add_book();
    }
    else if (a=='3')
    {
        delete_book();
    }
	else if(a=='q'){
		system("exit");
	}
//	else if(a=='4'){
//		sort();
//	}
    else{
        printf("Enter a Valid Number(1-3)!\n");
        menu();
    }
        
       
}

void show_books(){
	int i;
    get_info();
    for(i=0; i<g-1;i++){
        printf("%d-%s %s %s %s\n", i+1, Book[i].name, Book[i].surname, Book[i].book_name, Book[i].page_number);
    }
    getch();
    system("cls");
    menu();
}
void add_book(){
    printf("Writer's Name:");
    scanf("%s", &Book[g].name);
    printf("Writer's Surname:");
    scanf("%s", &Book[g].surname);
    printf("Book's Name:");
    scanf("%s", &Book[g].book_name);
    printf("Book's Page Number:");
    scanf("%s", &Book[g].page_number);
    
    file = fopen("Library.txt","a");
    fprintf(file, "%s", Book[g].name);
    fprintf(file, "\n");
    fprintf(file, "%s", Book[g].surname);
    fprintf(file, "\n");
    fprintf(file, "%s", Book[g].book_name);
    fprintf(file, "\n");
    fprintf(file, "%s", Book[g].page_number);
    fprintf(file, "\n");
    g++;
    fclose(file);
    getch();
    system("cls");
    menu();
}

void delete_book(){
    int i;
    int number;
	get_info();
    for (i=0;i<g-1;i++){
    	printf("%d-%s %s %s %s\n", i+1, Book[i].name, Book[i].surname, Book[i].book_name, Book[i].page_number);
	}
	printf("Enter the book number that you want to delete: ");
	scanf("%d", &number);
	printf("index number is %d", number-1);
	for(i=number-1;i<g-1;i++){
		strcpy(Book[i].name,Book[i+1].name);
		strcpy(Book[i].surname,Book[i+1].surname);
		strcpy(Book[i].book_name,Book[i+1].book_name);
		strcpy(Book[i].page_number,Book[i+1].page_number);		
	}
	file = fopen("Library.txt","w");
	for(i=0; i<g-2;i++){
        fprintf(file, "%s", Book[i].name);
    	fprintf(file, "%s", Book[i].surname);
    	fprintf(file, "%s", Book[i].book_name);
    	fprintf(file, "%s", Book[i].page_number);
    }
    fclose(file);
//    printf("\n");
//    printf("After this operation if you want to add a new book, please restart the program because after delete operation add operation doesn't work properly\n");
//    printf("and I couldn't find a solution Sorry about that.");
	getch();
    system("cls");
    menu();
}

void get_info(){
    g=0;
    file = fopen("Library.txt","r");
    while(!feof(file)){
        fgets(Book[g].name, 20, file);
        fgets(Book[g].surname, 20, file);
        fgets(Book[g].book_name, 100, file);
        fgets(Book[g].page_number, 10, file);
        g++;
    }
    fclose(file);
}
void sort(){

}
