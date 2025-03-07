%{
  #include<stdio.h>
  #include<string.h>
  int l=1,w=0,c=0; 
%}
%%
\n {l++;c++;}
[ \t]+ {w++;}
[a-zA-Z]+ {w++;c+=strlen(yytext);}
. {c++;
  printf("%d lines %d words %d charecters",l,w,c);
  exit(0);
 }
%%
int main(){
     printf("Enter the input=");
     yylex();
     
}
int yywrap(){
     return 1;
}

