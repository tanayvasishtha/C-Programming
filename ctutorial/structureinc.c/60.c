#include<stdio.h>

typedef struct Bankaccount{
    int accountno;
    char name[100];
}acc;//typedef is used as we were given to make alias for it

int main(){
acc acc1={123,"shraddha"};
acc acc2={124,"Tanay"};
acc acc3={125,"raja"};

printf("acc no=%d\n",acc1.accountno);
printf("name=%s\n",acc1.name);
return 0;
}