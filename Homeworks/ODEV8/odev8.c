/*ODEV dynamic array structures*/
int isDuplicated(const char **str1, size_t size, const char *str2)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (strcmp(str1[i], str2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void printCharArray(char **arr, size_t size)
{
	if (!arr || size == 0)
	{
		printf("Hic isim girilmedi!\n");
		return;
	}
	printf("Girilen isimler:\n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%s\n", arr[i]);
	}
}
int ccmp(const void *c1, const void *c2)
{
	const char *str1 = *(const char **)c1;
	const char *str2 = *(const char **)c2;
	return strcmp(str1, str2);
}

int main()
{
	int ch;
	char *isim = NULL;
	size_t size = 0;
	size_t isim_len = 0;
	char **pd = NULL;
	for (;;)
	{
		printf("bir isim girecek misiniz (e) (h)");
		while ((ch = _getch()) != 'e' && ch != 'h')
			; // null statement
		printf("\nch = %c\n", ch);
		if (ch == 'h')
		{
			break;
		}
		if (!isim)
		{
			isim = malloc(isim_len * sizeof(char));
		}
		else if (strlen(isim) + 1 >= isim_len)
		{
			isim_len *= 2;
			isim = realloc(isim, isim_len * sizeof(char));
		}
		pd = (char **)realloc(pd, (size + 1) * sizeof(char *));
		if (!pd || !isim)
		{
			printf("allocation failed\n");
			abort();
		}

		printf("tam isim girin: ");
		scanf("%s", isim);
		printf("isim = %s\n", isim);
		if (isDuplicated((const char **)pd, size, isim))
		{
			printf("bu isim daha onceden girildi\n");
			free(isim);
			continue;
		}
		pd[size++] = my_strdup(isim);
	}
	printf("donguden cikti\n");
	printf("size = %zu\n", size);
	qsort(pd, size, sizeof(char *), ccmp);
	printCharArray(pd, size);
	for (size_t i = 0; i < size; ++i)
	{
		free(pd[i]);
	}
	free(pd);
	if (!size)
	{
		printf("hic giris yapmadiniz!\n");
	}
}