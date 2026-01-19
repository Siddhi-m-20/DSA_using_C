#include<stdio.h>
#include<string.h>

int main(){
    char name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin);  // Reads entire line including spaces
    
    // Remove the newline character that fgets adds
    name[strcspn(name, "\n")] = '\0';
    
    char reverse[20];
    printf("Name: %s\n", name);
    
    // Check for empty string
    if(strlen(name) == 0) {
        printf("Empty string entered!\n");
        return 0;
    }
    
    int i;
    int len = strlen(name);
    for(i=0; i<len; i++){
        reverse[len-1-i] = name[i];
    }
    reverse[len] = '\0';
    
    printf("Reversed Name: %s\n", reverse);
    return 0;
}

