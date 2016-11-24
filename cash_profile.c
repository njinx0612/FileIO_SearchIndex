#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int file_create_write(char* location_filename, char* write_data, int size)
{
	int file_descriptor;
	char add_write[1024]={0};
	int ret;
	int iCnt;
	printf("\n");
	printf("[D] loca: %s\n", location_filename);
	printf("[D] data: %s\n", write_data);
	printf("[D] File Open start...\n");

#if 0
	/* replace a data to file  */
	if( (file_descriptor = open(location_filename,O_CREAT|O_TRUNC|O_WRONLY,0644)) > 0 )
	{
		write(file_descriptor, write_data, size);
		close(file_descriptor);
		printf("[D] File close\n");
	}
	else
	{
		printf("File Open Error...\n");
		return -1;
	}
#endif

	/* attach a data to file  */
	if( (file_descriptor = open(location_filename,O_CREAT|O_WRONLY|O_APPEND,0644)) > 0 )
	{
		printf("Open file_descriptor=%d\n",file_descriptor);
		if( write(file_descriptor, write_data, size) == -1 )
		{
			printf("File write Error...\n");
			return -3;
		}
	
#if 0
		printf("[ADD] Input data to file (nothing: Press Enter...) : ");
		fgets(add_write, sizeof(add_write), stdin);
		//scanf("%s",add_write);
		
		for(iCnt=0; iCnt<strlen(add_write); iCnt++)
		{
			printf("[D] add_write[%d]=%c[0x%02x]\n",iCnt,add_write[iCnt],add_write[iCnt]);
		}
		
		if( *(add_write) == '\n' )
		{
			break;
		}
		
		else
		{
			write(file_descriptor, add_write, sizeof(add_write)-1);
			for(iCnt=0; iCnt<sizeof(add_write); iCnt++)
			{
				add_write[iCnt]=0;
				printf(".");
			}
			
		}
#endif

	
		close(file_descriptor);
		printf("[D] File close\n");
	}
	
	else
	{
		printf("File Open Error...\n");
		return -2;
	}

	return 0;
}

int main(int argc, char* argv[])
{
	int ret,iCnt = 0;
	char file_location_name [1024] = {0};
	char file_write [1024] = {0};

	if( argc <= 1 || argc > 2 )
	{
		printf("Argument Error...\n");
		printf("Using manual: ./(execution_file_name) (file_location)\n");
		return -1;
	}

	while(1)
	{
		iCnt = 0;
		printf("\n Input data to file : ");
		fgets(file_write, sizeof(file_write), stdin);
		//for(iCnt=0; iCnt<strlen(file_write); iCnt++)

		while( *(file_write+iCnt) != '\n' )
		{
			printf("[D] file_write[%d]=%c[0x%02x]\n",iCnt,file_write[iCnt],file_write[iCnt]);
			iCnt++;
		}

		if( file_write[0] == '\n' )
		{
			break;
		}

		/* file_write end is '\n' */
		ret = file_create_write( argv[1], file_write, strlen(file_write) );
		
		
		for(iCnt=0; iCnt<strlen(file_write); iCnt++)
		{
			file_write[iCnt]=0;
		}
	}

	/* remove '\n' */
	//ret = file_create_write( file_location_name, file_write, strlen(file_write)-1); 
	printf("[D] File open return=%d\n", ret);

	return 0;
	
}
