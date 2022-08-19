#include"contact.h"


void manu()
{
	printf("********************************\n");
	printf("****** 1.Add    2.Delete *******\n");
	printf("****** 3.Modify 4.Search *******\n");
	printf("****** 5.Show   6.Sort   *******\n");
	printf("****** 0.Exit            *******\n");
	printf("********************************\n");

}

enum Options
{
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	SEARCH,
	SHOW,
	SORT
};



int main()
{
	int input = 0;
	struct Contract con;
	IntialCon(&con);
	do
	{
		manu();
		printf("please input option:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContacter(&con);
			break;
		case DELETE:
			DeleteContacter(&con);
			break;
		case MODIFY:
			ModifyContacter(&con);
			break;
		case SEARCH:
			SearchContacter(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("exit\n");
			break;
		default:
			printf("input error\n");
			break;
		}

	} while (input);
	return 0;
}