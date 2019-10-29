#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mecab.h>

#define strnull(x) (x == NULL || x[0] == '\0')
#define countof(x) sizeof(x) / sizeof(x[0])

int main(void)
{
	char  name[512], * ptr;
	char* argv[] = { (char*) "mecab" }; mecab_t* mecab;

	sprintf(name, "すもももももももものうち");

	if((mecab = mecab_new(countof(argv), argv)) != NULL)
	{
		fprintf(stdout, "mecab_new ok\n");
		if((ptr = (char*) mecab_sparse_tostr(mecab, name)) != NULL)
		{
			fprintf(stdout, "mecab_sparse_tostr ok string is:\n%s\n", ptr);
		}
		mecab_destroy(mecab);
	}

	return 0;
}
