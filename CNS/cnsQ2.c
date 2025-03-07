#include <stdio.h>
#include <string.h>

int main() {
    char s1[64],s2[64],s3[64];
    int i;
    printf("Enter the String=");
    fgets(s1,sizeof(s1),stdin);
    for(i=0;s1[i]!='\0';i++)
        s2[i]=s1[i]&127;
        s3[i]=s1[i]^127;
    s2[i]=s3[i]='\0';
    printf(" AND result:%s XOR result:%s\n",s2,s3);

}
