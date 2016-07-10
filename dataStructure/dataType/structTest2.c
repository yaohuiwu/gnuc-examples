#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[10];
	int age;
	double salary;
} Student;

typedef struct{
	char name[10];
	int age;
} Person;


int main(void){
	Student stu;
	strcpy(stu.name, "ZhangSan");
	stu.age = 26;
	stu.salary = 190.00;

	printf("name: %s, age: %d, salary: %f\n", stu.name, stu.age, stu.salary);

	Student *p=&stu;
	strcpy(p->name, "LiSi");

	printf("name: %s, age: %d, salary: %f\n", p->name, p->age, p->salary);

	Person pe;
	strcpy(pe.name, "Foo");
	pe.age = 25;
	printf("Person{age=%d, name=%s}\n", pe.age, pe.name);

	Person *pp = malloc(sizeof(Person));
	strcpy(pp->name, "Bar");
	pp->age = 10;

	printf("Person{age=%d, name=%s}\n", pp->age, pp->name);

	free(pp);
	pp=NULL;

	return 0;
}
