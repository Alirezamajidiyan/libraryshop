
#include <stdio.h>
#include <string.h>
#include <string>


const  int  max_member = 200;
const  int max_book = 200;
const int max_user=2;


struct member
{
	long int id;
	char fname[25];
	char lname[25];
	int age;
	int books=0;
};



struct book
{
	char name[100];
	char fname_author[100];
	char lname_author[100];
	long int id;
	long int n_page;
	long int NO_book;
};

struct user
{
	char username[4];
	char password[4];
};
member m_list[max_member];
book b_list[max_book];
user user_list[max_user];
int book_No = 0;
int member_No = 0;





int search_memberbyid(long int serachid) {
	int center, rhite, left;
	rhite = 0;
	left = member_No - 1;
	while (rhite <= left) {
		center = (rhite + left) / 2;
		if (serachid == m_list[center].id)return center;
		else if (serachid < m_list[center].id) left = center - 1;
		else rhite = center + 1;
	}
	return(-1);
}


void searching_book_byname();



int add_member(const member& new_member) {
	int i;
	if (member_No == max_member)return 0;
	if (search_memberbyid(new_member.id) != -1)return(1);
	for (i = member_No - 1; i >= 0; i--)
		if (new_member.id < m_list[i].id)
			m_list[i + 1] = m_list[i];
		else break;
	m_list[i + 1] = new_member;
	member_No++;
	return(2);
}




member get_member() {
	member get_member();
	member input_member;
	printf("\nplease enter id member: ");
	scanf("%ld", &input_member.id);
	getchar();
	printf("\n please enter first name member:");
	scanf("%s", input_member.fname);
	printf("\n please enter last name member:");
	scanf("%s", input_member.lname);
	printf("\n enter member age:(number integer) :");
	scanf("%d", &input_member.age);
	return(input_member);
}




void cheekAdd() {
	member new_member;
	int result;
	if (member_No == max_member) {

		printf("\n  lIST IS FULL  ");
		return;
	}
	new_member = get_member();
	result = add_member(new_member);
	if (result == 2)
		printf("\n\xdb MEMBER SUCCESSFULLY ADDED \xdb");
	else printf("\n NOT SUCCESSFULLY ADDED ");
}




int delete_member(long int deleteid) {
	int temp, i;
	temp = search_memberbyid(deleteid);
	if (temp == -1)return (0);
	for (i = temp; i < member_No - 1; i++)
		m_list[i] = m_list[i + 1];
	member_No--;
	return(1);
}



void remove_member() {
	long int deleteid;
	printf("  please enter id to remove: ");
	scanf("%ld", &deleteid);
	if (delete_member(deleteid))printf("\n  member successfully deleted  ");
	else printf("\n  member not found!");
}



void print_member(const member& output_member) {
	printf("\n\t\t\t\xdb members in library \xdb\n\n ");
	printf(" id=%ld\n", output_member.id);
	printf(" first name:%s\n", output_member.fname);
	printf(" last name:%s\n", output_member.lname);
	printf(" age member:%d\n", output_member.age);
}



void searchingbyid() {
	long int searchid;
	int temp;
	printf("please enter id member to search:");
	scanf("%ld", &searchid);
	temp = search_memberbyid(searchid);
	if (temp == -1)printf("\n\n member not found");
	else print_member(m_list[temp]);
}



int search_memberbyname(const char searchname_member[]) {
	int i;
	for (i = 0; i < member_No; i++)
		if (!strcmp(searchname_member, m_list[i].fname)) return (i);
	return (-1);
}



void searching_member_byname() {
	char searchname_member[40];
	int temp;

	printf("\n please enter first name member to search: ");
	scanf("%s", searchname_member);
	getchar();
	temp = search_memberbyname(searchname_member);
	if (temp == -1) printf("\n member not found ");
	else print_member(m_list[temp]);
}



int search_bookbyid(long int serachid) {
	int center, rhite, left;
	rhite = 0;
	left = book_No - 1;
	while (rhite <= left) {
		center = (rhite + left) / 2;
		if (serachid == b_list[center].id)return center;
		else if (serachid < b_list[center].id) left = center - 1;
		else rhite = center + 1;
	}
	return(-1);
}



int add_book(const book& new_book) {
	int i;
	if (book_No == max_book)return 0;
	if (search_bookbyid(new_book.id) != -1)return(1);
	for (i = book_No - 1; i >= 0; i--)
		if (new_book.id < b_list[i].id)
			b_list[i + 1] = b_list[i];
		else break;
	b_list[i + 1] = new_book;
	book_No++;
	return(2);
}




book get_book() {
	book input_book;
	printf("\nplease enter id book: ");
	scanf("%ld", &input_book.id);
	getchar();
	printf("\n please enter name book:");
	scanf("%s", input_book.name);
	getchar();
	printf("\n author first name :");
	scanf("%s", input_book.fname_author);
	getchar();
	printf("\n author last name :");
	scanf("%s", input_book.lname_author);
	getchar();
	printf("\n number of page:");
	scanf("%ld", &input_book.n_page);
	printf("No. book enter: ");
	scanf("%ld", &input_book.NO_book);
	return(input_book);
}




void cheekAddbook() {
	book new_book;
	int result;
	if (book_No == max_book) {

		printf("\n  lIST IS FULL  ");
		return;
	}
	new_book = get_book();
	result = add_book(new_book);
	if (result == 2)
		printf("\n BOOK SUCCESSFULLY ADDED ");
	else printf("\n NOT SUCCESSFULLY ADDED ");
}



int delete_book(long int deleteid) {
	int temp, i;
	temp = search_bookbyid(deleteid);
	if (temp == -1)return (0);
	for (i = temp; i < book_No - 1; i++)
		b_list[i] = b_list[i + 1];
	book_No--;
	return(1);
}



void remove_book() {
	long int deleteid;
	printf("  please enter id to remove: ");
	scanf("%ld", &deleteid);
	if (delete_book(deleteid))printf("\n  book successfully deleted  ");
	else printf("\n  book not found!");
}




void print_book(const book& output_book) {
	printf("\n\t\t   book in library   \n");
	printf("name:%s\n", output_book.name);
	printf("id=%ld\n", output_book.id);
	printf("author first name::%s\n", output_book.fname_author);
	printf("author last name:%s\n", output_book.lname_author);
	printf("no.page:%ld\n", output_book.n_page);
	printf("no.book:%ld\n", output_book.NO_book);

}



void searchingbyidbook() {
	long int searchid;
	int temp;
	printf("please enter id book to search:");
	scanf("%ld", &searchid);
	temp = search_bookbyid(searchid);
	if (temp == -1)printf("\n\n book not found");
	else print_book(b_list[temp]);
}



int search_bookbyname(const char searchname_book[]) {
	int i;
	for (i = 0; i < book_No; i++)
		if (!strcmp(searchname_book, b_list[i].name)) return (i);
	return (-1);
}




void searching_book_byname() {
	char searchname_book[40];
	int temp;

	printf("\n please enter first name member to search: ");
	scanf("%s", searchname_book);
	getchar();
	temp = search_bookbyname(searchname_book);
	if (temp == -1) printf("\n member not found ");
	else print_book(b_list[temp]);
}




void receive() {
	long int receiveid;
	int temp, receiveAmount,result;
	printf("please enter id book:");
	scanf("%ld", &receiveid);
	temp = search_bookbyid(receiveid);
	if (temp == -1) printf("\nbook not found");
	else {
		printf("\nid member enter:");
		scanf("%d",&result);
		printf("enter no.book book:");
		scanf("%d", &receiveAmount);
		b_list[temp].NO_book += receiveAmount;
	}
}



void send() {
	long int sendid;
	int temp, sentAmount,result;
	printf("pelase enter id book:");
	scanf("%ld", &sendid);
	temp = search_bookbyid(sendid);
	if (temp == -1) printf("\n book not found");
	else {
		printf("id member enter:");
		scanf("%d",&result);
		printf("enter no.book book:");
		scanf("%d", &sentAmount);
		if (sentAmount <= b_list[temp].NO_book){
			b_list[temp].NO_book -= sentAmount;
	}
		else printf("no successfully");
	}
}


void print_list_book() {
	int i;
	printf("\n\nid\tnamebook\tfname author\t lname author\t   No.of.page\t   No.book\n");
	printf("__________________________________________________________________________________________\n");
	for (i = 0; i < book_No; i++)
		printf(" %ld\t%s\t\t%s\t\t%s\t   %ld\t\t\t%ld\n\n", b_list[i].id, b_list[i].name, b_list[i].fname_author, b_list[i].lname_author, b_list[i].n_page, b_list[i].NO_book);
}


void print_list_member() {
	int i;
	printf("id\tfirst name\tlast name \tage \tbooks\n");
	printf("________________________________________________________________________\n");
	for (i = 0; i < member_No; i++)
		printf(" %ld\t%s\t\t%s\t  %d\t%d\n", m_list[i].id, m_list[i].fname, m_list[i].lname, m_list[i].age,m_list[i].books);
}



void savetofile_book() {
	FILE* bookFile;
	if (book_No == 0)return;
	bookFile = fopen("book.dat", "wb");
	if (!bookFile) {
		printf("can not open file");
		return;
	}
	fwrite(b_list, sizeof(book), book_No, bookFile);
	printf("book successfully saved");
	fclose(bookFile);
}


void loadfile_book() {
	FILE* bookFile;
	bookFile = fopen("book.dat", "rb");
	if (!bookFile) {
		printf("can not open file");
		return;
	}
	book_No = 0;
	fread(&b_list[book_No], sizeof(book), 1, bookFile);
	while (!feof(bookFile)) {
		book_No++;
		fread(&b_list[book_No], sizeof(book), 1, bookFile);
	}
	printf("book successfully loaded");
	fclose(bookFile);
}



void savetofile_member() {
	FILE* memberFile;
	if (member_No == 0)return;
	memberFile = fopen("member.dat", "wb");
	if (!memberFile) {
		printf("can not open file");
		return;
	}
	fwrite(m_list, sizeof(member), member_No, memberFile);
	printf("member successfully saved");
	fclose(memberFile);
}



void loadfile_member() {
	FILE* memberFile;
	memberFile = fopen("member.dat", "rb");
	if (!memberFile) {
		printf("can not open file");
		return;
	}
	member_No = 0;
	fread(&m_list[member_No], sizeof(member), 1, memberFile);
	while (!feof(memberFile)) {
		member_No++;
		fread(&m_list[member_No], sizeof(member), 1, memberFile);
	}
	printf("members successfully loaded");
	fclose(memberFile);
}



int menu() {
	int choice;
	printf("\n\n\t\t\t\t\t\t\t\xdb\xdb  MENU \xdb\xdb\n\n");
	printf("________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t\xDB\xDB 1.New member registration in the library\n");
	printf("\t\t\t\t\t\t\xDB\xDB 2.Search member in the library by ID\n");
	printf("\t\t\t\t\t\t\xDB\xDB 3.Remove member from library\n");
	printf("\t\t\t\t\t\t\xDB\xDB 4.Search member by name\n");
	printf("\t\t\t\t\t\t\xDB\xDB 5.Insert book in the library\n");
	printf("\t\t\t\t\t\t\xDB\xDB 6.Book search based on ID\n");
	printf("\t\t\t\t\t\t\xDB\xDB 7.Book search besed on name:\n");
	printf("\t\t\t\t\t\t\xDB\xDB 8.Remove the book from the library\n");
	printf("\t\t\t\t\t\t\xDB\xDB 9.Display all members of the library\n");
	printf("\t\t\t\t\t\t\xDB\xDB 10.View all library books\n");
	printf("\t\t\t\t\t\t\xDB\xDB 11.recive book\n");
	printf("\t\t\t\t\t\t\xDB\xDB 12.send book\n");
	printf("\t\t\t\t\t\t\xDB\xDB 13.save to file book\n");
	printf("\t\t\t\t\t\t\xDB\xDB 14.load book from file\n");
	printf("\t\t\t\t\t\t\xDB\xDB 15.save members to file \n");
	printf("\t\t\t\t\t\t\xDB\xDB 16.load members from file\n");
	printf("\t\t\t\t\t\t\xDB\xDB 17.Display User\n");
	printf("\t\t\t\t\t\t\xDB\xDB 18.exit program\n");
	printf("\n\n\n choose:");
	scanf("%d", &choice);
	return(choice);
}                              



int login(){
	user input;
	int temp1,temp2;
	printf("\n\n \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  LOGIN USER  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
	printf("\n\n\n\n\n\t\t\t\t\t Username:");
	scanf("%s",input.username);
	temp1++;
	printf("\n\n\n\n\n\t\t\t\t\t Password:");
	scanf("%s",input.password);
	temp2++;
	
	if(temp1==1 && temp2==1){
		return 1;
	}
	else{
		return 0;
}
}




int  print_user(){
	system("cls");
	int temp;
	printf("\n\n\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb      USERS      \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	printf("\n\n\n\n  ACTIVE    \t CONDITION");
	printf("\n___________________________________________________________\n");
	printf(" user1       \t   online\n\n\n\n");
	printf("\n_____________________________________________________\n\n");
	
	printf("back=1       exit=2");
	printf("\nplease enter:");
	scanf("%d",&temp);
	return temp;
}



int main() {
	
	int i;
	int temp;
	temp=login();
	if(temp==1){
	loop:
	system("cls");
	int choice;
	do {
		choice = menu();
		switch (choice)
		{
		case 1:
			cheekAdd();
			system("cls");
			break;
		case 2:
			searchingbyid();

			break;
		case 3:
			remove_member();

			break;
		case 4:
			searching_member_byname();

			break;
		case 5:
			cheekAddbook();
			system("cls");
			break;
		case 6:
			searchingbyidbook();

			break;
		case 7:
			searching_book_byname();
			break;
		case 8:
			remove_book();

			break;
		case 9:
			print_list_member();

			break;
		case 10:
			print_list_book();
			break;
		case 11:
			receive();
			system("cls");
			break;
		case 12:
			send();
			system("cls");
			break;
		case 13:
			savetofile_book();
			break;
		case 14:
			loadfile_book();
			break;
		case 15:
			savetofile_member();
			break;
		case 16:
			loadfile_member();
			break;
		case 17:
			i=print_user();
			if(i==1) goto loop;
			break;
		case 18:
			exit(0);
			break;
		default:
			printf("\n\xdb\xdb choice again!!!");
			
		}
	} while (choice != 17);
}
else{
	printf(" \n\n\n\n\n\t\t\t\tplease restart program ");
	exit(0);
}
}