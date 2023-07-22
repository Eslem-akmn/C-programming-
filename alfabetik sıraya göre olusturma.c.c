/*Disaridan aldigi isimleri alfabetik sira ile
listeleyen, listeye yeni dügüm ekleyen, belirtilen
dügümü silen ve dügümdeki en uzun ismi bulan tek
bagli liste uygulamasi.*/

#include <stdio.h>
#include <stdlib.h>

struct data
{
	char name[20];
	struct data *next;
};

struct data *add (struct data *head)
{
	struct data *names=(struct data*)malloc(sizeof(struct data));
	printf("Enter the name: ");
	scanf("%s", names->name);
	
	names->next=NULL;
	printf("\nName is added the list..\n\n");
	if(head==NULL)
	{
		head=names;
	}
	else
	{
		names->next=head;
		head=names;
    }
    return head;
}	
struct data *remove_name(struct data *head, const char *name_del)
{
    struct data *p = head;
    struct data *q = NULL;

    if (p != NULL && strcmp(p->name, name_del) == 0) {
        head = p->next;
        free(p);
        return head;
    }

    while (p != NULL && strcmp(p->name, name_del) != 0) 
	{
        q = p;
        p = p->next;
    }

    if (p == NULL) 
	{
        printf("No the name found to delete\n");
        return head;
    }

    q->next = p->next;
    free(p);
    printf("The name removed from list\n");
    return head;
}

void longest(struct data *head)
{
	struct data *ptr,*longst;
	ptr=head;
	longst=ptr->next;
	while(ptr!=NULL)
	{
		if(strlen(ptr->name)>strlen(longst->name))
		{
			longst=ptr;
		}
		ptr=ptr->next;
	}
	printf("Longest name is: %s\n\n",longst->name);
	getchar();
}

void list(struct data *head)
{
	if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct data *current = head;
    struct data *temp = NULL;
    char tempName[20];

    while (current != NULL) {
        temp = current->next;
        while (temp != NULL) {
            if (strcmp(current->name, temp->name) > 0) {
                strcpy(tempName, current->name);
                strcpy(current->name, temp->name);
                strcpy(temp->name, tempName);
            }
            temp = temp->next;
        }
        current = current->next;
    }
    current = head;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}
int main()
{
	struct data *head=NULL;
	int choice;
	char name_del[20];
	while(choice!=6)
	{
		printf("---------------------------------------\n");
		printf("1-Add a name: \n");
		printf("2-Delete a name: \n");
		printf("3-Longest name: \n");
		printf("4-List names: \n");
		printf("5-Exit \n");
		
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		printf("\n----------------------------------------\n");
		switch(choice)
		{
			case 1:
				head=add(head);
				break;
			case 2:
				printf("Enter the name: ");
				scanf("%s",name_del);
				remove_name(head,name_del);
				break;
			case 3:
				longest(head);
				break;
			case 4:
				list(head);
				break;
			case 5:
				break;		
				
			
				
		}
	}
}


