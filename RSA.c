#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
int isprime(int);
int modpow(int,int,int);

int main()
{
	int csrch,P,ch,i,num,flag,i1,z,p,q,j,k,n,f1,f2,n1,k1,j1,x,e[100],d[100],ff;
	double E;
	char c,csrenc[100],csrdec[100],a[100],filnam[100];
	FILE *fp1;
	// no clrscr() as Dev C++ cannot recognise it
	do
	{
	printf("\n\nCRYPTOGRAPHY");
	printf("\n1. Simple Cryptography\n2. Difficult Cryptography\n3. Exit\nEnter your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
            yy:
			printf("Enter the file name(having only one word) with it's extension:");
			scanf("%s",&filnam);
	        fp1=fopen(filnam,"r");
	        if (fp1==NULL)
			{
  			printf("file doesn't exists");
			}
			else
			{
			i=0;
	        while((c=getc(fp1))!=EOF)
			{
				a[i]=c;
				i++;
			}
			a[i]='\0';
			printf("The plain message is: ");
            puts(a);

            ff=0;
            do
            {   zz:
                printf("\n1.Encryption\n2. Decryption\n3. Exit from Ceaser Cipher\nEnter your choice :");
                scanf("%d",&csrch);
                switch(csrch)
                {
                    case 1:
                    if(ff==1)
                        goto yy;
                    ff=1;
                    for(i=0;i<strlen(a);i++)
                {
                    if(a[i]<=90&&a[i]>=65)
                    	csrenc[i]=(a[i]-64)%26 + 65;
                    else if(a[i]>=97&&a[i]<=122)
                    	csrenc[i]=(a[i]-96)%26 + 97;
                    else
                    	csrenc[i]=a[i];
			    }
			    csrenc[i]='\0';

                    printf("The encrypted message is ");
                    puts(csrenc);
                    ff=1;
                    break;

                case 2:
                if(ff==0)
                {
                printf("Encrypt the message first !\n");
                goto zz;
                }
                    for(i=0;i<strlen(a);i++)
                {
                    if(csrenc[i]==97)
                    csrdec[i]=122;
                    else if(csrenc[i]==65)
                    csrdec[i]='Z';
                    else  if((csrenc[i]>65&&csrenc[i]<=90)||(csrenc[i]>97&&csrenc[i]<=122))
                    csrdec[i]=csrenc[i]-1;
                    else
                    csrdec[i]=csrenc[i];

                }
                csrdec[i]='\0';
                    printf("The decrypted message is : ");
                    puts(csrdec);
                      printf("\n");
                    break;
                case 3:
                    break;

            }
            }while(csrch!=3);
        }
            break;
		case 2:
			printf("Enter the file name(having only one word) with it's extension:");
			scanf("%s",&filnam);
			fp1=fopen(filnam,"r");
	        if (fp1==NULL)
			{
  			printf("file doesn't exists");
			}
			else
			{
			i=0;
	        while((c=getc(fp1))!=EOF)
			{
				a[i]=c;
				i++;
			}
			printf("The plain message is: ");
			puts(a);
			printf("\nEnter two different large prime nos. :");
			scanf("%d%d",&p,&q);
			f1=isprime(p);
			f2=isprime(q);
			if (f1==1&&f2==1)  //this condition executes if nos. are prime
			{
				n=p*q;
				z=(p-1)*(q-1);
				for(i=1;i<z;i++)
				{
					if(z%i!=0)
					{
					   P=isprime(i);
						if(P==1)
						   break;

					}
				}
				k=i;
				printf("\nYour Public Key(n,k) is :(%d,%d)",n,k);

			for(j=0;j<z;j++)
			{
				if((j*i)%z==1)
				{
					break;
				}
			}
			g:
				printf("\nYour Private Key(j) is :%d\n",j);
		    printf("Enter the public key(n,k) to encrypt the message: ");
		    scanf("%d%d",&n1,&k1);
		    	if(n1==n&&k1==k)
		    	{

                for(i=0;i<strlen(a);++i)
			 		{x=(int)a[i];
			 		e[i]=(int)modpow(x,k,n);

			 		}
				 	printf("The encrypted message is:");
			 		for(i1=0;i1<i;i1++)
			 		{
			 			printf("%d ",e[i1]);  //dont use j as the loop variable as j is the private key
			 		}
				}
				else
				{
					printf("\nThe public key entered by you is invalid ! \n");
					goto g;
				}
				g1:
				printf("\nEnter the private key(j) to decrypt the message :");
				scanf("%d",&j1);

				if(j==j1)
				{

					for(i1=0;i1<i;i1++) // i is the limit of e[100], please don't alter it
					{

					d[i1]=(char)modpow(e[i1],j,n);
					}
					printf("The decrypted message is: ");
					for(i1=0;i1<i;i1++)
					{
						printf("%c",d[i1]);
					}
				}
				else
				{
					printf("\nThe private key that you entered is invalid !\n");
					goto g1;
				}
		   }
		else
		{
			printf("\nPlease enter two prime numbers. ");
		}
	}
			break;
		case 3:
			exit(0);
		default:
			printf("\nWrong Choice");
}
}while(ch!=3);
   getch();
   return 0;
}


int isprime( int a) // func to check if p and q are prime
{
	long int i;
	for(i=2;i<=a/2;i++)
	{
		if(a%i==0)
		return 0;
	}
	return 1;
}
int modpow(int b,int e ,int m) //Using the method of modular exponentation to find the value of b^e mod m
{ int remainder;
int x = 1;

while (e != 0)
{
remainder = e % 2;
e= e/2;

if (remainder == 1)
x = (x * b) % m;
b= (b * b) % m; // New base equal b^2 % m
}
return x;
}
