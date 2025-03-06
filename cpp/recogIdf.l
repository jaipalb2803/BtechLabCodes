%{
    #include<stdio.h>
    int k=0,i=0,c=0,O=0;
%}
%%
   "if"/"else"/"for"/"while"/"do"/"switch"/"case"/"break"/"continue"/"int"/"float"/"char"/"struct"{
      printf("%s is keyword",yytext);
      k++;
   }
   [a-zA-Z][0-9a-zA-Z]*{
      printf("%s is identifier",yytext);
      i++;
   }
    [0-9]+{
      printf("%s is constant",yytext);
      c++;
   }
   "="/"+"/"-"/"*"/"/"/"%"/"=="/"<="/">="{
      printf("%s is opertor",yytext);
      o++;
   }
%%
int main(){
   printf("Enter String:");
   yylex();
   printf("%d keywords,%d identifier,%d constant,%d operator",k,i,c,o);
}
int yywrap(){
   return 1;
}