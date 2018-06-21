#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct {
        char name[256];
        int rollno;
        struct list_head head;
}student;

typedef struct {

        char section[256];
        struct list_head students;

}classroom;

void list_classroom(classroom *room)
{
        student *instance = NULL;
        
        printf("\n----------------Class room :%s-----------------\n", room->section);
        list_for_each_entry (instance, &room->students, head)
                printf("Name:%s \t Roll_no:%d\n",instance->name,instance->rollno);
        printf("\n");
        return;
}

int main (void)
{
        classroom myclassroom ;
        student student_1 = {"Ravi",1};
        student student_2 = {"Arun",2};
        student *instance;
        
        INIT_LIST_HEAD (&myclassroom.students);
        strcpy(myclassroom.section, "A-section");
        INIT_LIST_HEAD (&student_1.head);
        INIT_LIST_HEAD (&student_2.head);
        list_add_tail (&student_1.head,&myclassroom.students);
        list_add_tail (&student_2.head,&myclassroom.students);

        list_classroom(&myclassroom);

        return 0;
}
