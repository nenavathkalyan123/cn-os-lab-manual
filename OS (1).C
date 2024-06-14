// WEEK 2A :WRITE A SHELL SCRIPT FIND THE FACTORIAL VAALUE OF GIVEN INTEGER
    #include<stdio.h>  
    int main()    
    {    
     int i,fact=1,number;    
     printf("Enter a number: ");    
      scanf("%d",&number);    
        for(i=1;i<=number;i++){    
          fact=fact*i;    
      }    
      printf("Factorial of %d is: %d",number,fact);    
    return 0;  
    }   
    
    out put : enter a number :5
    120
----------------------------------------------------------------------------------------------------------------------------
// WEEK 2B: WRITE A SHELL SCRIPT TO WISH THE GOOD MORNIG AND GOOD EVENINF DEPENDING ON THE SYSYTEM TIME.
----------------------------------------------------------------------------------------------------------------------------
//WEEK 3:LINUX COMMAND USING FILE AP'S?
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main( int argc,char *argv[3] )
{
int fd,i;
char buf[2];
fd=open(argv[1],O_RDONLY,0777);
if(fd==-argc)
{
printf("file open error");
}
else
{
printf("your program is printing data in th file\n");
while((i=read(fd,buf,1))>0)
{
printf("%c",buf[0]);
}
close(fd);
}
}

output: file open error ubuntu@219:
----------------------------------------------------------------------------------------------------------------------------
//WEEK 4A:IIMPLEMENT THE LINUX COMMAND CP USING LINUX SYSTEM CALLS
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
char buf;
int fd_one, fd_two;

fd_one = open("first_file", O_RDONLY);

if (fd_one == -1)
{
printf("Error opening first_file\n");
close(fd_one);
return;
}

fd_two = open("second_file",
 O_WRONLY | O_CREAT,
 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

while(read(fd_one, &buf, 1))
{
write(fd_two, &buf, 1);
}

printf("Successful copy");

close(fd_one);
close(fd_two);
}

output:error opening first file
----------------------------------------------------------------------------------------------------------------------------
//WEEK 4B:IIMPLEMENT THE LINUX COMMAND MV USING LINUX SYSTEM CALLS
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc ,char *argv[])
{
int i,fd1,fd2;
char *file1,*file2,buf[2];
file1=argv[1];
file2=argv[2];
printf("file1=%s file2=%s",file1,file2);
fd1=open(file1,O_RDONLY,0777);
fd2=creat(file2,0777);
while(i=read(fd1,buf,1)>0)
write(fd2,buf,1);
remove(file1);
close(fd1);
close(fd2);
}

output:file1=(null) file 2=SHELL=/binbash ubuntu@219
---------------------------------------------------------------------------------------------------------------------------
//WEEK 5:WRITE A C PROGRAM TO CREATE ACHILD PROCESS AND ALLOW TO PARENT CLADD CHILD ON THE SCREEN
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int global=10;
int main()
{
int local=20;
pid_t pid;
printf("before fork");
printf("pid=%d,global=%d,local=%d\
n",getpid(),global,local);
pid=fork();
if (pid<0)
printf("failed to create child");
else if (pid==0)
{
printf("after fork\n");
global++;
local++;
}
else if(pid>0)
sleep(2);
printf("cid=%d,global=%d,local=%d\n",getpid(),global,local);
exit(0);
}


output:before fork pid=300k,global=10,local=20
output:after fork pid=300k,global=11,local=21
--------------------------------------------------------------------------------------------------------------------------
//WEEK 6: WRITE A C PROGRAM IN WHICH PARENT WRITES A MAESSEGE TO APIPE AND THE CHILD READS THE MESSEGE
#include <stdio.h> 
#include<stdlib.h>
#include <sys/wait.h> /* contains prototype for wait */ 
int main(void) 
{ 
int pid; 
int status; 
printf("Hello World!\n"); 
pid = fork( );

if(pid == -1) /* check for error in fork */ 
{ 
perror("bad fork"); 
exit(1); 
} 
if (pid == 0) 
printf("I am the child process.\n");
else { wait(&status); /* parent waits for child to finish */ 
printf("I am the parent process.\n");
return 0;
}
}

output :hello world 
iam the child proccess
iam the parent processs
-------------------------------------------------------------------------------------------------------
