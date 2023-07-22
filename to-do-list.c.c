/*C dilinde tek y�nl� bir ba�l� liste kullanarak, bir to-do listesi uygulamas� olu�turmak istiyorsunuz. 
Her g�revin ad� ve �nceli�i (1'den 5'e kadar olan bir �ncelik de�eri) tutulacak. 
Ba�l� listede a�a��daki i�lemleri yapman�z gerekiyor:
>>Yeni bir g�rev d���m� ekleyebilmeli (g�rev ad� ve �ncelik kullan�c�dan al�nacak).
>>Belirli bir g�revi g�rev ad�yla arayabilme (e�er bulunursa bilgileri ekrana yazd�rma).
>>Belirli bir g�revi g�rev ad�yla silebilme.
>>T�m g�revleri �nceliklerine g�re s�ralayarak ekrana yazd�rabilme.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tasks
{
	char task[100];
	int priority;
	struct tasks *next;
};
struct tasks *head=NULL;

void addTask()
{
	struct tasks *newTasks=(struct tasks*)malloc(sizeof(struct tasks));
	printf("Enter a task: ");
	scanf(" %[^\n]",newTasks->task); //burada SABAH ERKEN KALK yazd���mda yanl�� �al���yor tek kelime yaz�nca do�ru ve gets ile de alam�yorum napabilirim
	printf("Enter priority: ");
	scanf("%d", &newTasks->priority);
	newTasks->next=NULL;
	if(head==NULL)
	{
		head=newTasks;
	}
	else
	{
		struct tasks* temp=head;
		while(newTasks->next!=NULL && temp->next->priority<=newTasks->priority )
		{
			temp=temp->next;
		}
		newTasks->next=temp->next;
		temp->next=newTasks;
	}
	printf("The task added..\n");
}

void searchTasks()
{
	char task_name[100];
	printf("Enter the task name: ");
    scanf(" %[^\n]" ,task_name);
    
	struct tasks *temp=head;
	while(temp!=NULL)
	{
		if(strcmp(task_name,temp->task)==0)
		{
			printf("Task name: %s\n",temp->task);
			printf("Task priority: %d\n",temp->priority);
			return;
		}
		temp=temp->next;
	}
	printf("No the task found..\n");
}
void deleteTask()
{
	struct tasks *p,*q;
	char del_name[50];
	int del_priority;
	p=head;
	q=NULL;
	printf("Enter the task name: ");
	scanf(" %[^\n]",del_name);
	printf("Enter the task priority: ");
	scanf("%d",&del_priority);
	while(p!=NULL)
	{
		if(strcmp(del_name,p->task)==0 && del_priority==p->priority)
		{
			if(q==NULL)
			{
				head=p->next;
			}
			else
			{
				q->next=p->next;
			}
			free(p);
			printf("The task deleted..\n");
			return;
		}
		q=p;
		p=p->next;
	}
	printf("No task found..\n");
}

void list()
{
	if (head == NULL)
	{
		printf("List is empty..\n");
		return;
	}

	// Ba�l� listeyi kopyalamak i�in ge�ici bir dizi olu�turulur
	int taskCount = 0;
	struct tasks *temp = head;
	while (temp != NULL)
	{
		taskCount++;
		temp = temp->next;
	}

	struct tasks **taskArray = (struct tasks **)malloc(taskCount * sizeof(struct tasks *));
	temp = head;
	int i = 0;
	while (temp != NULL)
	{
		taskArray[i] = temp;
		temp = temp->next;
		i++;
	}
	int j,k;
	// �nceliklere g�re s�ralama yap�l�r (k���kten b�y��e)
	for (j = 0; j < taskCount - 1; j++)
	{
		for (k = 0; k < taskCount - j - 1; k++)
		{
			if (taskArray[k]->priority > taskArray[k + 1]->priority)
			{
				struct tasks *tempTask = taskArray[k];
				taskArray[k] = taskArray[k + 1];
				taskArray[k + 1] = tempTask;
			}
		}
	}
	int m;
	// S�ralanm�� g�revleri yazd�rma
	printf("\n");
	for (m = 0; m < taskCount; m++)
	{
		printf("%d.The task name: %s\n", m + 1, taskArray[m]->task);
	}
	// Bellekten ge�ici dizi i�in ayr�lan alan serbest b�rak�l�r
	free(taskArray);
}

int main()
{
	int choice=0;
	while(choice!=6)
	{
		printf("\nMenu\n");
    	printf("1.New a task add\n");
    	printf("2.Search for a task by name\n");
    	printf("3.Delete a task by name\n");
    	printf("4.List all tasks\n");
    	printf("5.Exit\n");
    	
    	printf("Make your choice (1-5): ");
    	scanf("%d",&choice);
    	printf("\n\n");
    
    	switch(choice)
    	{
    		case 1:
    			addTask();
    			break;
    		case 2:
       			searchTasks();
				break;
			case 3:
				deleteTask();
				break;
			case 4:
				list();
				break;
			case 5:
				break;				
		}
  	}
}




