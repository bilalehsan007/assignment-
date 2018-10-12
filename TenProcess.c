#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
	int arr[1000], s=0, sum=0;
	int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];
	for(int i=0;i<1000;i++)
		arr[i]=i;

	if(pipe(fd1)==-1){
		printf("Pipe failed 1 \n");
		return 0;
	}
	if(pipe(fd2)==-1){
		printf("Pipe failed 2 \n");
		return 0;
	}
	if(pipe(fd3)==-1){
		printf("Pipe failed 3 \n");
		return 0;
	}
	if(pipe(fd4)==-1){
		printf("Pipe failed 4 \n");
		return 0;
	}
	if(pipe(fd5)==-1){
		printf("Pipe failed 5 \n");
		return 0;
	}
	if(pipe(fd6)==-1){
		printf("Pipe failed 6 \n");
		return 0;
	}
	if(pipe(fd7)==-1){
		printf("Pipe failed 7 \n");
		return 0;
	}
	if(pipe(fd8)==-1){
		printf("Pipe failed 8 \n");
		return 0;
	}
	if(pipe(fd9)==-1){
		printf("Pipe failed 9 \n");
		return 0;
	}
	if(pipe(fd10)==-1){
		printf("Pipe failed 10 \n");
		return 0;
	}
	int cpid1=fork();
	if(cpid1==0){
		for(int i=0;i<100;i++){
			s+=arr[i];
		}
		write(fd1[1],&s,sizeof(s));
		close(fd1[1]);
		exit(0);
	}
	else{
		int cpid2=fork();
		if(cpid2==0){
			for(int i=100;i<200;i++){
				s+=arr[i];
			}
			write(fd2[1],&s,sizeof(s));
			close(fd2[1]);
			exit(0);
		}
		else{
			int cpid3=fork();
			if(cpid3==0){
				for(int i=200;i<300;i++){
					s+=arr[i];
				}
				write(fd3[1],&s,sizeof(s));
				close(fd3[1]);
				exit(0);
			}
			else{
				int cpid4=fork();
				if(cpid4==0){
					for(int i=300;i<400;i++){
						s+=arr[i];
					}
					write(fd4[1],&s,sizeof(s));
					close(fd4[1]);	
					exit(0);
				}
				else{
					int cpid5=fork();
					if(cpid5==0){
						for(int i=400;i<500;i++){
							s+=arr[i];
						}
						write(fd5[1],&s,sizeof(s));
						close(fd5[1]);
						exit(0);
					}
					else{
						int cpid6=fork();
						if(cpid6==0){
							for(int i=500;i<600;i++){
								s+=arr[i];
							}
							write(fd6[1],&s,sizeof(s));
							close(fd6[1]);
							exit(0);
						}
						else{
							int cpid7=fork();
							if(cpid7==0){
								for(int i=600;i<700;i++){
									s+=arr[i];
								}
								write(fd7[1],&s,sizeof(s));
								close(fd7[1]);
								exit(0);
							}
							else{
								int cpid8=fork();
								if(cpid8==0){
									for(int i=700;i<800;i++){
										s+=arr[i];
									}
									write(fd8[1],&s,sizeof(s));
									close(fd8[1]);
									exit(0);
								}
								else{
									int cpid9=fork();
									if(cpid9==0){
										for(int i=800;i<900;i++){
											s+=arr[i];
										}
										write(fd9[1],&s,sizeof(s));
										close(fd9[1]);
										exit(0);
									}
									else{
										for(int i=900;i<1000;i++){
											s+=arr[i];
										}
										write(fd10[1],&s,sizeof(s));
										close(fd10[1]);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										wait(NULL);
										read(fd1[0],&s,sizeof(int));
										sum+=s;
										read(fd2[0],&s,sizeof(int));
										sum+=s;
										read(fd3[0],&s,sizeof(int));
										sum+=s;
										read(fd4[0],&s,sizeof(int));
										sum+=s;
										read(fd5[0],&s,sizeof(int));
										sum+=s;
										read(fd6[0],&s,sizeof(int));
										sum+=s;
										read(fd7[0],&s,sizeof(int));
										sum+=s;
										read(fd8[0],&s,sizeof(int));
										sum+=s;
										read(fd9[0],&s,sizeof(int));
										sum+=s;
										read(fd10[0],&s,sizeof(int));
										sum+=s;
										printf("Sum = %d",sum);
										printf("\n\n");
										close(fd1[0]);
										close(fd2[0]);
										close(fd3[0]);
										close(fd4[0]);
										close(fd5[0]);
										close(fd6[0]);
										close(fd7[0]);
										close(fd8[0]);
										close(fd9[0]);
										close(fd10[0]);
									}
									
								}
								
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		
	}
	
	return 0;
}