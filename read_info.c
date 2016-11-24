#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int read_info(char* file_location, char* find_index)
{
	int file_descriptor;
	char* find_location;
	char file_index[1024] = {0};
	char file_contents[1024] = {0};
	char index[1024] = {0};
	int ret, iCnt=0;
	int inCnt=0;

#if 0
	printf("[FD] location= %s\n", file_location);
	printf("[FD] index= %s\n", find_index);
#endif
	printf("\n");

	if( (file_descriptor = open(file_location,O_RDONLY)) > 0)
	{
		if( read(file_descriptor,file_contents,sizeof(file_contents)) > 0 )
		{
			while(iCnt<strlen(file_contents))
			{
				if( *(file_contents+iCnt) != '\n' )
				{
					printf("[D] file_contents[%d]:%c [0x%02x]\n",iCnt, *(file_contents+iCnt), *(file_contents+iCnt));

				}
				iCnt++;
			}
			printf("\n");
			puts(file_contents);
			
			
#if 0
				printf("Input index to find: ");
				fgets(file_index,sizeof(file_index),stdin);

				if( *(file_index+0) == '\n')
				{
					printf("Exit Program...\n");
					break;
				}
#endif
		
			find_location = strstr(file_contents,find_index);
			while( *(find_location+inCnt) != '\n' )
			{
				printf("%c",*(find_location+inCnt));
				inCnt++;
			}

			printf("\n\n");
	



		} //end of read
			
		else
		{
			printf("read Error!!!\n");
			return -2;
		}
		
		close(file_descriptor);
	}
		
	else
	{
		printf("File open Fail...\n");
		return -3;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	char file_index[1024] = {0};
	int iCnt;
	if( (argc == 1) || (argc > 3) || (argc == 2) )
	{
		printf("\nArgument Error...\n");
		printf("\nUsing manual: ./(execution_file_name) (file_location) (find_index)\n\n");
		return -1;
	}

	read_info(argv[1], argv[2]);
#if 0
	while(1)
	{
		printf("Input index to find: ");
		fgets(file_index,sizeof(file_index),stdin);
		read_info(argv[1], file_index);
		for(iCnt=0; iCnt<sizeof(file_index); iCnt++)
		{
			file_index[iCnt]=0;
		}
	}
#endif

	return 0;
}

