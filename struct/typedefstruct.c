#include <stdio.h>

/*Define a struct with tag 'Point', and a struct variable pt*/
struct Point {
	float x;
	float y;
} pt;

/*Define a struct with tag 'Person', and a alias named 'People'*/
typedef struct Person { 
	char name[10];
	int age;
} People;

/*Define a linklist*/
typedef struct Node {
	char data;
	struct Node *next;
} LinkList;

void printPerson(struct Person p);
void printLinkList(LinkList *list);

int main(void){ 
	
	/*pt = { 1.0, 2.0 }; pt is already initialized.*/
	pt.x = 1.0;
	pt.y = 2.0;
	printf("pt.x %f, pt.y %f\n", pt.x, pt.y);

	struct Person p1 = {"foo", 25};
	People p2 = {"bar", 26};
	
	printPerson(p1);
	printPerson(p2);

	LinkList mylist;
	mylist.data = 'a';

	LinkList n1;
	n1.data = 'b';
	mylist.next=&n1;

	LinkList n2;
	n2.data = 'c';
	n1.next = &n2;
	n2.next = NULL;

	printLinkList(&mylist);

	return 0;
}

void printPerson(struct Person p){
	printf("name:%s, age:%d\n", p.name, p.age);
}

void printLinkList(LinkList *list){
	LinkList *p = list;
	while(p!=NULL){
		printf("%c\n", p->data);
		p = p->next;
	}
}
