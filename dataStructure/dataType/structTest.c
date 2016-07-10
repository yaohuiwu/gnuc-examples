#include <stdio.h>
#include <string.h>

struct Student{
	char name[10];
	int age;
	double salary;
};


int main(void){
	struct Student stu;
	strcpy(stu.name, "ZhangSan");
	stu.age = 26;
	stu.salary = 190.00;

	printf("name: %s, age: %d, salary: %f\n", stu.name, stu.age, stu.salary);

	return 0;
}
