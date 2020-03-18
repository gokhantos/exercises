#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]){
   pid_t pid;
   int correct=0;
   int wrong=0;
   int status;
   char str[2];
   int rand_arr[5];
   srand(time(NULL));
   int random, j,chk,x;
   j=0;
   while(j<5){
     random=rand()%10;
     for(int i=0;i<=j;i++){
        if(rand_arr[i]==random){
           chk=0;
           break;
           }else if(rand_arr[i]!=random){
              chk=1;
              }
           }
        if(chk==1){
          rand_arr[j]=random;
          j++;
         }
     }
   for(int i=0;i<5;i++){
      sprintf(str,"%d",rand_arr[i]);
      pid=fork();
      if(pid<0){
        fprintf(stderr,"Fork Failed");
        exit(-1);
      }else if(pid==0){
        char *args[]={"./quiz",str,NULL};
        execvp(args[0],args);
      }else{
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
           int es=WEXITSTATUS(status);
           //printf("exit status: %d\n",es);
           if(es==2){
            correct++;
          }else if(es==3){
            wrong++;
           }
        }
      }
   }
  printf("Number of Correct answers: %d\n Number of Wrong Answers: %d\n",correct,wrong);
  return 0;
}
