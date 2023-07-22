/*C dilinde tek yönlü bir baðlý liste kullanarak, bir to-do listesi uygulamasý oluþturmak istiyorsunuz. 
Her görevin adý ve önceliði (1'den 5'e kadar olan bir öncelik deðeri) tutulacak. 
Baðlý listede aþaðýdaki iþlemleri yapmanýz gerekiyor:
>>Yeni bir görev düðümü ekleyebilmeli (görev adý ve öncelik kullanýcýdan alýnacak).
>>Belirli bir görevi görev adýyla arayabilme (eðer bulunursa bilgileri ekrana yazdýrma).
>>Belirli bir görevi görev adýyla silebilme.
>>Tüm görevleri önceliklerine göre sýralayarak ekrana yazdýrabilme.
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
	scanf(" %[^\n]",newTasks->task); //burada SABAH ERKEN KALK yazdýðýmda yanlýþ çalýþýyor tek kelime yazýnca doðru ve gets ile de alamýyorum napabilirim
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

	// Baðlý listeyi kopyalamak için geçici bir dizi oluþturulur
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
	// Önceliklere göre sýralama yapýlýr (küçükten büyüðe)
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
	// Sýralanmýþ görevleri yazdýrma
	printf("\n");
	for (m = 0; m < taskCount; m++)
	{
		printf("%d.The task name: %s\n", m + 1, taskArray[m]->task);
	}
	// Bellekten geçici dizi için ayrýlan alan serbest býrakýlýr
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




