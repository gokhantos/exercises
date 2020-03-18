#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct quiz{
   char question[100];
   char choices[4][100];
   char answer[100];
};

int main(int argc, char* argv[]){
    FILE *fp;
    char str[100];
    char* filename="quiz.txt";
    char question[100][100];
    int i=0;
    struct quiz arr[10];
    fp=fopen(filename,"r");
    if(fp==NULL){
      printf("Could not open file %s",filename);
      return -1;
    }
    while(i<60 && fgets(str, 100, fp)!=NULL){
         strcpy(question[i],str);
         i++;
    }
    i=0;
    int j=0;
    while(i<60){
      strcpy(arr[j].question,question[i]);
      strcpy(arr[j].choices[0],question[i+1]);
      strcpy(arr[j].choices[1],question[i+2]);
      strcpy(arr[j].choices[2],question[i+3]);
      strcpy(arr[j].choices[3],question[i+4]);
      strcpy(arr[j].answer,question[i+5]);
      i+=6;
      j++;
    }
    int answer;
    printf("%s\n",arr[atoi(argv[1])].question);
    printf("0) %s\n",arr[atoi(argv[1])].choices[0]);
    printf("1) %s\n",arr[atoi(argv[1])].choices[1]);
    printf("2) %s\n",arr[atoi(argv[1])].choices[2]);
    printf("3) %s\n",arr[atoi(argv[1])].choices[3]);
    printf("Enter your answer\n");
    scanf("%d",&answer);
    if(answer!=0 && answer!=1 && answer!=2 && answer!=3){
       while(1){
            printf("Please enter your answer as 0, 1, 2 or 3.\n");
            scanf("%d", &answer);
            if(answer==0 || answer==1 ||answer==2 || answer==3) break;
          }
    }
    if(strcmp(arr[atoi(argv[1])].choices[answer],arr[atoi(argv[1])].answer)==0){
        printf("Correct\n");
        _exit(2);
        }else{
         printf("Wrong\n");
        _exit(3);
      }
    fclose(fp);
}
