#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <sys/stat.h>
 
void function1(){
  pid_t child_id;
  int status;
 
  child_id = fork();
 
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
 
  }
 
  if (child_id == 0) {
    // this is child
 
    char *argv[] = {"mkdir","/home/user/modul2/", NULL};
    execv("/bin/mkdir", argv);
 
  } else {
 
    // this is parent
    while ((wait(&status)) > 0);
   execlp("unzip","unzip","-j","pets.zip","-i","*.jpg","-d","/home/user/modul2/petshop",NULL);
 
 
   }
 
}
 
 
 
void function211111(char token[],char * nama,char * petname,char age[])
{
 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
 
char *argv[] = {"echo","hai", NULL};
  execv("/bin/echo", argv);
  }
  else{
    while ((wait(&status)) > 0);
    return;
  }
}
 
 
void function21111(char token[],char * nama,char * petname,char age[])
{
 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
    chdir("/home/user/modul2/petshop");
 
   char *argv[] = {"mv",nama,token, NULL};
   execv("/bin/mv", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function211111(token,nama,petname,age);
   return;
  }
}
 
 
 
 
 
void function2111(char token[],char * filename,char * petname,char age[])
{
 pid_t child_id1;
  int status;
 
	age[strlen(age)-1]=' ';
	age[strlen(age)-2]=' ';
	age[strlen(age)-3]=' ';
	age[strlen(age)-4]=' ';
    chdir("/home/user/modul2/petshop");
    chdir(token);
    FILE *fp;
    fp=fopen("keterangan.txt","a");
    fprintf(fp,"Nama:%s\nUmur:%s\n",petname,age);
    fclose(fp);
 
  char *nama=strcat(petname,".jpg");
 
 
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
 
    chdir("/home/user/modul2/petshop");
 
   char *argv[] = {"mv",filename,nama, NULL};
   execv("/bin/mv", argv);
  }
  else{
    while ((wait(&status)) > 0);
   function21111(token,nama,petname,age);
   return;
 
  }
 
}
 
 
void function211(char token1[],char * filename,char * petname,char age[])
{
 
 pid_t child_id1;
  int status;
 
  child_id1 = fork();
 
  if (child_id1 < 0) {
 
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
 
 
    // this is child
   chdir("/home/user/modul2/petshop");
 
    char *argv[] = {"mkdir",token1, NULL};
    execv("/bin/mkdir", argv);
 
 
  } else {
    // this is parent
    while ((wait(&status)) > 0);
	function2111(token1,filename,petname,age);
    return;
 
  }
 
}
 
 
void buatfilekedua(char * filename,char * folder,char * nama2)
{
printf("filekeduakuterakhir:%s\n",filename);
 
  pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  else if (child_id1 == 0) {
 
       char str[strlen(filename)],str1[strlen(filename)];
       strcpy(str,filename);
       strcpy(str1,str);
       char* token=strtok(str1,";");
       token=strtok(NULL,";");
       token=strtok(NULL,".jpg");
 
    chdir("/home/user/modul2/petshop");
    chdir(folder);
    FILE *fp;
    fp=fopen("keterangan.txt","a");
    fprintf(fp,"Nama:%s\nUmur:%s\n",nama2,token);
    fclose(fp);
 
 
 
 
 
    char *argv[] = {"echo","saya", NULL};//belum selesai
    execv("/bin/echo", argv);
 
  } else {
    // this is parent
    while ((wait(&status)) > 0);
        // buatfilekedua(filename,folder,nama2);
	return;
  }
}
 
 
 
 
 
 
 
void function21211111(char * filename,char * folder,char token[],char * nama,char * nama1, char * nama2)
{
printf("filekeduakuterakhir:%s\n",filename);
 
  pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  else if (child_id1 == 0) {
 
    // this is child
    chdir("/home/user/modul2/petshop");
    char *argv[] = {"mv",strcat(nama1,".jpg"),token, NULL};//belum selesai
    execv("/bin/mv", argv);
 
  } else {
    // this is parent
    while ((wait(&status)) > 0);
         buatfilekedua(filename,folder,nama2);
    return;
  }
}
 
 
void function2121111(char * filekedua,char * folderkedua,char token[],char * nama, char * nama1, char * nama2)
{
  pid_t child_id1;
  int status; 
 
   child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
 
    chdir("/home/user/modul2/petshop");
 
      char *argv[] = {"mv",nama,strcat(nama1,".jpg"), NULL};//belum selesai
      execv("/bin/mv", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    function21211111(filekedua,folderkedua,token,nama,nama1,nama2);
    return;
  }
}
 
 
 
 
 
void  pivot(char * filekedua,char * folderkedua,char token[],char * nama, char * nama1, char * nama2)
{
  pid_t child_id1;
  int status;
   child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
 printf("filekedua=%s...........................%s\n",nama,nama1);
    // this is child
    chdir("/home/user/modul2/petshop");
 
      char *argv[] = {"mv",strcat(nama2,".jpg"),folderkedua, NULL};//belum selesai
      execv("/bin/mv", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    function2121111(filekedua,folderkedua,token,nama,nama1,nama2);
 
    return;
  }
}
 
 
 
 
 
 
 
void function212111(char * filekedua,char * folderkedua,char token[],char * nama,char * nama1, char * nama2)
{
  pid_t child_id1;
  int status;
 
 
  child_id1 = fork();
 
  if (child_id1 < 0) {
 
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
    // this is child
   chdir("/home/user/modul2/petshop");
    char *argv[] = {"mv",filekedua,strcat(nama2,".jpg"), NULL};//belum selesai
    execv("/bin/mv", argv);
 
  } else {
    // this is parent
    while ((wait(&status)) > 0);
       pivot(filekedua,folderkedua,token,nama,nama1,nama2);
	 return;
 
  }
 
}
 
 
 
//akhir
void function21211(char token[],char *token3,char * filename,char * nama, char * nama1,char * nama2)
{
       int panjang=strlen(filename);
       char str[panjang],str1[panjang];
       strcpy(str,filename);
       strcpy(str1,str);
       int add=0;
       char* filekedua=strtok(str1,"_");
       filekedua=strtok(NULL,"_");
 
 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
    chdir("/home/user/modul2/petshop");
   char *argv[] = {"mv",filename,filekedua,NULL};//perlu diganti banget
   execv("/bin/mv", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function212111(filekedua,token3,token,nama,nama1,nama2);
   return;
 
  }
 
}
 
 
 
 
 
 
 
void function2121(char token[],char *token3,char * filename,char * nama1, char * nama2,char * age1,char * age2)
{
 
    chdir("/home/user/modul2/petshop");
    chdir(token);
    FILE *fp;
    fp=fopen("keterangan.txt","a");
    fprintf(fp,"Nama:%s\nUmur:%s\n",nama1,age1);
    fclose(fp);
 
       int panjang=strlen(filename);
       char str[panjang],str1[panjang];
       strcpy(str,filename);
       strcpy(str1,str);
       int add=0;
       char* token4=strtok(str1,"_");
       token4=strtok(NULL,"_");
 
char * nama=strcat(str1,".jpg");
 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
   // this is childi
    chdir("/home/user/modul2/petshop");
   char *argv[] = {"cp",filename,nama, NULL};//diubah
   execv("/bin/cp", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function21211(token,token3,filename,nama,nama1,nama2);
   return;
 
  }
 
}
 
 
 
void function212(char token[],char *token3,char * filename,char * nama1,char * nama2,char * age1,char * age2)
{
 
 pid_t child_id1;
  int status;
 
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
   chdir("/home/user/modul2/petshop");
    char *argv[] = {"mkdir",token, NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
       function2121 (token,token3,filename,nama1,nama2,age1,age2);
    return;
 
  }
}
 
 
 
 
void function3()
{
 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
   char *argv[] = {"rm","/home/user/modul2/petshop/keterangan.txt", NULL};
   execv("/bin/rm", argv);
  }
  else{
    while ((wait(&status)) > 0);
   return;
  }
}
 
 
 
 
 
 
 
 
 
void function21()
{ 
printf("bisa\n");
FILE *fp;
  DIR *d;
  struct dirent *dir;
  char *filenames[15];
  //char *filenames = malloc(sizeof *filenames);
  int i=0;
  int a;
  // function1();
  d = opendir("/home/user/modul2/petshop");
	printf("sukses");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
 
     filenames[i]=(dir->d_name);
     int panjang=strlen(filenames[i]);     
       char str[panjang],str1[panjang];
       strcpy(str,filenames[i]);
       strcpy(str1,str);
       int add=0;      
       char* token=strtok(str1,";");
       char* token1[8];
 
       while(token!=NULL){
		token=strtok(NULL,";");
                token1[add]=token;
		printf("token %d =%s\n",add,token1[add]);
		add++;
	}
	if(add==3){
 
	function211(str1,filenames[i],token1[0],token1[1]);
	}
      else{
 
	int lenght=strlen(token1[1]);
       char str2[lenght],str3[lenght];
       strcpy(str2,token1[1]);
       strcpy(str3,str2);
       char* token3=strtok(str3,"_");
       token3=strtok(NULL,"_");
        function212(str1,token3,filenames[i],token1[0],token1[2],str3,token1[4]);      
 
    }
      i++;
 
    }
    printf("\n");
    closedir(d);
  }
 
	function3();
}
 
void function2(){
 
int status;
pid_t child_id1;
 
child_id1=fork();
if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
 
  if (child_id1 == 0) {
	function21();
  } else {
    while ((wait(&status)) > 0);
    function21();
  }
}
 
 
 
 
int main(){
 
int status;
pid_t child_id1;
 
child_id1=fork();
if (child_id1 < 0) {
//  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
 
  if (child_id1 == 0) {
    function1();
  } else {
    while ((wait(&status)) > 0);
    function2();
  }
 
 
}
