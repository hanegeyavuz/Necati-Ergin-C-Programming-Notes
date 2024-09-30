/*- Palindrom
      - en iyi mese bese mi yine?
      - Ana, Naci Dede ne dedi Canan'a?
      - Tras neden sart?
      - Para hazir. Ama Riza harap!
      - at sahibi gibi hasta
      - A man, a plan, a canal, Panama

  -  do not use another array
  -  do not change array's elements
  -  check if the string is palindrom*/
void ispalindrom(char *pa, int len)
{
    int idx_start = 0;
    int idx_end = len - 1;

    while (1)
    {

        while (idx_start <= idx_end && !(isalpha(pa[idx_start])))
        {
            idx_start++;
        }

        while (idx_start <= idx_end && !(isalpha(pa[idx_end])))
        {
            idx_end--;
        }
        if (idx_start > idx_end || tolower(pa[idx_start]) != tolower(pa[idx_end]))
        {
            break;
        }
        idx_start++;
        idx_end--;
    }
    if (idx_start > idx_end)
    {
        printf("Bu bir palindromdur.\n");
    }
    else
    {
        printf("Bu bir palindrom degildir.\n");
    }
}