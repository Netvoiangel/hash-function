void choice()
{
	int placeHolder;
	int n;
	bool loop = true;
	while (loop)
	{
		loop = false;
		printf("Choose your operation:\n");
		printf("1. Sign up\n");
		printf("2. Sign in\n");
		printf("3. Exit\n");
		scanf("%d", &n);
		system("cls");

		switch (n)
		{
		case 1:
			registration_func(); //TODO

			printf("Enter any number to continue...\n");
			scanf("%d", &placeHolder);

			system("cls");
			loop = true;
			break;
		case 2:
			login_func(); //TODO

			printf("Enter any number to continue...\n");
			scanf("%d", &placeHolder);

			system("cls");
			loop = true;
			break;
		case 3:
			break;
		default:
			printf("Please enter a valid operation...\n");

			printf("Enter any number to continue...\n");
			scanf("%d", &placeHolder);

			system("cls");
			loop = true;
			break;
		}
	}
}
