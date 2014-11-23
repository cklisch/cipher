

#include <stdio.h>
void shift(int x, char* character){
    int c;
    c=*character;
    c-=32;
    c+=x;

    while (c<0) {
        c+=94;
    }
    c=(c%94)+32;
    *character=c;
    
 
}

void encrypt(int x, char* message){
   while (*message!='\0') {
       shift(x, message);
       message++;
   }
}
int pw_length(char* pw){
    int length=0;
    while (*pw!='\0') {
        length++;
        pw++;
    }
    return length;
}
void vingere(char* pw, char* message){
    int length, i;
    length = pw_length(pw);
    while (*message!='\0') {
        for (i=0; i<length && *message!='\0' ; i++) {
            shift(pw[i], message);
            message++;
        }
    }
}
void de_vingere(char* pw, char* message){
    int length, i;
    length = pw_length(pw);
    while (*message!='\0') {
        for (i=0; i<length && *message!='\0' ; i++) {
            shift(-pw[i], message);
            message++;
        }
    }
}

int main(void){
    char message[1000] = "hallo heute ist sonntag der 21.22.2014 !!!°°°%&/()";
    char pw[100] = "password&sowas*";
    vingere(pw, message);
//    vingere(pw, message);
    printf("%s\n",message);
    de_git vingere(pw, message);
    printf("%s\n",message);
    return 0;
}
