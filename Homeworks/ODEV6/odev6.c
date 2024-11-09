/*Generic strstr() function HOMEWORK*/
const void *g_strstr(const void *vp1, size_t sizevp1, const void *vp2, size_t sizevp2)
{
	const unsigned char *haystack = (const unsigned char *)vp1;
	const unsigned char *needle = (const unsigned char *)vp2;

	if (sizevp2 == 0) 
		return haystack;

	while (sizevp1 >= sizevp2)
	{
		if (memcmp(haystack, needle, sizevp2) == 0)
		{
			return haystack; 
		}
		haystack++;
		sizevp1--;
	}

	return NULL;
}