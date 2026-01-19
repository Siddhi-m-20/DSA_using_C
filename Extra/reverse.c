#include<stdio.h>
#include<string.h>

int main(){
    char name[20]="HelloWorld";
    char reverse[20];
    printf("Name: %s\n",name);
    int i;
    for(i=0;i<strlen(name);i++){
        reverse[strlen(name)-1-i] = name[i];
    }
    reverse[strlen(name)] = '\0'; // Null-terminate the reversed string
    printf("Reversed Name:%s\n",reverse);
    return 0;
}
