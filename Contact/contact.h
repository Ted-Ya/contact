#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_NMAE 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_CAPACTICY 3




struct Person
{
	char name[MAX_NMAE];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contract
{
	int size;
	int capacity;
	struct Person ps[];
};


void IntialCon(struct Contract* pcon);

struct Contract* AddContacter(struct Contract* pcon);


void ShowContact(const struct Contract* pcon);

void SearchContacter(const struct Contract* pcon);

void DeleteContacter(struct Contract* pcon);

void ModifyContacter(struct Contract* pcon);

void SortContact(struct Contract* pcon);