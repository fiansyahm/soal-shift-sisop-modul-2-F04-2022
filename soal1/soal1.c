#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

char path[20];

void download(){
  char pathdir[] ="/home/misdinar/Sisop1/modul2/no1/";
  time_t t_now = time(NULL);
  struct tm waktu = *localtime(&t_now);
  pid_t child_id;
  int i,status;
  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  } 

  if (child_id == 0) {
    // this is child
    char *argv[3][7] = {    
    {"/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", 0},
    {"/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", 0},
    {"/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", 0}};
    for(i = 0; i< 3;i++ ){
      if (0 == fork()) continue;
      execve(argv[i][0], &argv[i][0], NULL);
      while ((wait(&status)) > 0);
     }

     char *argv_1[3][5] = {
    {"/bin/mkdir", "-p", "Musyik", 0}, 
    {"/bin/mkdir", "-p", "Fylm", 0}, 
    {"/bin/mkdir", "-p", "Pyoto", 0}};
    for(i = 0; i< 3;i++ ){
      if (0 == fork()) continue;
      execve(argv_1[i][0], &argv_1[i][0], NULL);
     }
    }
   else{
    // this is parent
    while ((wait(&status)) > 0);
    char *argv_3[] = {"unzip", "*.zip", NULL};
    execv("/usr/bin/unzip", argv_3);

    while(strcmp(path,"09-04_22:22")!=0)
    {
    sleep(1);
    t_now = time(NULL);
    waktu = *localtime(&t_now);
    strftime(path, sizeof(path)-1, "%d-%m_%H:%M", &waktu);
    printf("%s_%d\n", path, strcmp(path,"09-04_22:22"));
    if(strcmp(path,"09-04_22:22")==0){
      char *argv_4[] = {"zip", "-r", "Lopyu_Stevany", pathdir, "-x", "*.c", "*soal1", "*.zip", NULL};
      execv("/usr/bin/zip", argv_4);
    }
    }
  }
}
int main() {
  // setvbuf(stdout, NULL, _IONBF, 0);
  time_t t_now = time(NULL);
  struct tm waktu = *localtime(&t_now);
  strftime(path, sizeof(path)-1, "%d-%m_%H:%M", &waktu);
  printf("%s\n", path);
  
  while(strcmp(path,"09-04_16:22")!=0)
  {
    sleep(2);
    t_now = time(NULL);
    waktu = *localtime(&t_now);
    strftime(path, sizeof(path)-1, "%d-%m_%H:%M", &waktu);
    printf("%s_%d\n", path, strcmp(path,"09-04_16:22"));
  }
  download();
}
