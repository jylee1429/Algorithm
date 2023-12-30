#include <stdio.h>
#include <stdlib.h>

typedef struct _student {
	char* name[101];
	int age;
}Student;

Student student[100001];
int Compare(void* _a, void* _b);

int main(void) {
	int cnt, i;

	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		scanf("%s", &student[i].name);
		scanf("%d", &student[i].age);
	}

	qsort(student, cnt, sizeof(Student), Compare);
	
	for (i = 0; i < cnt; i++) {
		printf("%s ", student[i].name);
	}

	return 0;
}

int Compare(void* _a, void* _b) {
	Student* a = (Student*)_a;
	Student* b = (Student*)_b;

	if (a->age > b->age)
		return 1;
	else if (a->age < b->age)
		return -1;
	else
		return 0;
}
