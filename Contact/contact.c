#include"contact.h"
#include<string.h>
#include<assert.h>

void IntialCon(struct Contract* pcon) 
{
	memset(pcon->ps,0,sizeof(pcon->ps));
	pcon->size = 0;
}

void AddContacter(struct Contract* pcon)
{
	if (pcon->size == MAX_CON)
	{
		printf("Add faild,Contact has fulled");
	}
	else
	{
		printf("add contacter name:>");
		scanf("%s", pcon->ps[pcon->size].name);
		printf("add contacter age:>");
		scanf("%d", &(pcon->ps[pcon->size].age));
		printf("add contacter sex:>");
		scanf("%s",pcon->ps[pcon->size].sex);
		printf("add contacter tele:>");
		scanf("%s", pcon->ps[pcon->size].tele);
		printf("add contacter addr:");
		scanf("%s",pcon->ps[pcon->size].addr);

		pcon->size++;
	}
}

void ShowContact(const struct Contract* pcon)
{
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "name", "age", "sex", "tele", "addr");
	int i = 0;
	for ( i = 0; i < pcon->size; i++)
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n", pcon->ps[i].name,
			pcon->ps[i].age,
			pcon->ps[i].sex,
			pcon->ps[i].tele,
			pcon->ps[i].addr);
	}
	if (pcon->size == 0)
	{
		printf("Not add any contacter\n");
	}
}

static int FindByName(const struct Contract* pcon, char* name)
{
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (0 == strcmp(pcon->ps[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void SearchContacter(const struct Contract* pcon)
{
	char name[MAX_NMAE];
	printf("please input name:>");
	scanf("%s", name);
	int pos = FindByName(pcon, name);
	if (-1 == pos)
	{
		printf("contacter %s not exit\n",name);
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "name", "age", "sex", "tele", "addr");
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n", pcon->ps[pos].name,
			pcon->ps[pos].age,
			pcon->ps[pos].sex,
			pcon->ps[pos].tele,
			pcon->ps[pos].addr);
	}
}

void DeleteContacter(struct Contract* pcon) 
{
	char name[MAX_NMAE];
	printf("please input name:>");
	scanf("%s",name);
	int pos = FindByName(pcon, name);
	if (-1 == pos)
	{
		printf("contacter %s not exit\n", name);
	}
	else
	{
		int j = 0;
		for ( j = pos; j < pcon->size-1; j++)
		{
			pcon->ps[j] = pcon->ps[j + 1];
		}
		pcon->size--;
		printf("deletion %s success\n",name);
	}
}


void ModifyContacter(struct Contract* pcon)
{
	char name[MAX_NMAE];
	printf("please input name:>");
	scanf("%s",name);
	int pos = FindByName(pcon, name);
	if (-1 == pos)
	{
		printf("contacter %s not exit\n", name);
	}
	else
	{
		printf("add contacter name:>");
		scanf("%s", pcon->ps[pos].name);
		printf("add contacter age:>");
		scanf("%d", &(pcon->ps[pos].age));
		printf("add contacter sex:>");
		scanf("%s", pcon->ps[pos].sex);
		printf("add contacter tele:>");
		scanf("%s", pcon->ps[pos].tele);
		printf("add contacter addr:");
		scanf("%s", pcon->ps[pos].addr);
	}

}


int CompareByName(void* p1,void* p2)
{
	char* name1 = (char*)(((struct Person*)p1)->name);
	char* name2 = (char*)(((struct Person*)p2)->name);
	while ((*name1 !='\0') && (name2 != '\0') && *name1 == *name2)
	{
		name1++;
		name2++;
	}
	return  (*(name1) - *(name2));
}
void Swap(char* buff1, char* buff2, int width)
{
	int i = 0;
	for ( i = 0; i < width; i++)
	{
		char temp = *buff1;
		*buff1 = *buff2;
		*buff2 = temp;
		buff1++;
		buff2++;
	}

}

void* bubble_sort(void* arr,int num,int width, void (*fun)(void* ,void*))
{
	assert(arr);
	if (num == 0)
	{
		return arr;
	}
	char* start = (char*)arr;
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		int j = 0;
		for ( j = 0; j < num-1-i; j++)
		{
			if (CompareByName(start+j*width,start+(j+1)*width) > 0)
			{
				Swap(start + j * width, start + (j + 1) * width,width);
			}
		}
	}
	return arr;
}

void SortContact(struct Contract* pcon)
{
	bubble_sort(pcon->ps, pcon->size, sizeof(pcon->ps[0]), CompareByName);
	ShowContact(pcon);
}

