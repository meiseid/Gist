#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int	 bytes, in_quot = 0;
	char c, buf[2048], * p1, * p2, * p3, * p4; size_t psize;

	while(1)
	{
		bytes = fread(buf, 1, sizeof(buf) - 1, stdin);
		if(bytes <= 0)
		{
			break;
		}
		buf[bytes] = '\0';
		for(p1 = buf; (p2 = strchr(p1, '\'')) != NULL ||
			(p2 = strchr(p1, '\0')) != NULL; p1 = p2 + 1)
		{
			c	= *p2;
			*p2 = '\0';
			if(in_quot)
			{
				for(p3 = p1; (p4 = strstr(p3, "\r\n")) != NULL ||
					(p4 = strchr(p3, '\r')) != NULL ||
					(p4 = strchr(p3, '\n')) != NULL; p3 = p4 + 1)
				{
					psize = (size_t) p4 - (size_t) p3;
					fwrite(p3, psize, 1, stdout);
					if(*p4 == '\r' && *(p4 + 1) == '\n')
					{
						p4++;
					}
				}
				fwrite(p3, strlen(p3), 1, stdout);
			}
			else
			{
				fwrite(p1, strlen(p1), 1, stdout);
			}
			*p2 = c;
			if(c == '\0')
			{
				break;
			}
			else
			{
				putchar(c);
				in_quot = in_quot ? 0 : 1;
			}
		}
	}
	return 0;
}
