#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef long long int lld;
char ohm[12][20]={"silver\0","gold\0","black\0","brown\0","red\0","orange\0","yellow\0","green\0","blue\0","violet\0","grey\0","white\0"};
char in[1000],*tok[5];
int times[12];
double col[5],percent[12]={0.1,0.005,0,0.01,0.02,0,0,0.005,0.0025,0.0010,0.0005,0};
lld gcd(lld x,lld y)
{
	while( y!=0 )
	{
		lld r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main() 
{
	int test_n;
	scanf("%d",&test_n);
	switch(test_n)
	{
		case 1: ;
				printf("Hello, world!\n");
				break;
		case 2: ;
				lld a,b,c,d;
				while(scanf("%lld",&a)!=EOF)
				{
					scanf("%lld",&b);
					c=gcd(a,b);
					d=1;
					lld c_temp=c;
					int ct_2=0;
					for(int i=2;i<c;i++)
					{
						int n=0;
						lld d_=1;
						while(c%i==0)
						{
							n++;
							d_+=pow(i,n);
							c/=i;
						}
						if(d_!=1) d*=d_;
					}
					printf("%lld %lld\n",c_temp,d);		
				}
				break;
		case 3:	;
				int n;
				for(int i=0;i<12;i++)times[i]=i-2;
				while(scanf("%d",&n)!=EOF)
				{
					int c=0;
					scanf("%s",in);
					tok[0]=strtok(in,"/");
					while(tok[c]!=NULL)	tok[++c]=strtok(NULL,"/");
					for(int i=0;i<n-1;i++) for(int j=0;j<12;j++) if( strcmp( &ohm[j][0],tok[i] )==0) col[i]=times[j];
					for(int j=0;j<12;j++) if( strcmp( &ohm[j][0],tok[n-1] )==0) col[n-1]=percent[j];
					double ohms;
					if(n==4)
					{
						ohms=((10*col[0]+col[1])*(pow(10,col[2])));
						printf("R= %.3f ~ %.3f ohms\n",(ohms*(1-col[3])),(ohms*(1+col[3])));
					}
					else if(n==5)
					{
						ohms=((100*col[0]+10*col[1]+col[2])*(pow(10,col[3])));
						printf("R= %.3f ~ %.3f ohms\n",(ohms*(1-col[4])) , ( ohms * (1+col[4]) ) );
					}
				}
				break;
		case 4: ;
				int a_4,b_4,out_4[1000];
				while(scanf("%d",&a_4)!=EOF)
				{
					int ct_4=0;	
					scanf("%d",&b_4);
					while(b_4!=0)
					{
						out_4[ct_4]=a_4/b_4;
						int temp=b_4;
						b_4=a_4%b_4;
						a_4=temp;	
						ct_4++;
					}
					printf("[%d;",out_4[0]);
					for(int i=1;i<ct_4-1;i++)printf("%d,",out_4[i]);
					printf("%d]\n",out_4[ct_4-1]);
				}
				break;
		case 5: ;
				char n_5;
				while(scanf("%c",&n_5)!=EOF)
				{
					if(n_5=='r')
					{
						float r_5[4],x_5,y_5;
						for(int i=0;i<4;i++) scanf("%f",&r_5[i]);
						scanf("%f%f",&x_5,&y_5);
						if( x_5>r_5[0] && x_5<r_5[2] && y_5>r_5[3] && y_5<r_5[1] )printf("The point is contained in the figure.\n");
						else printf("The point is not contained in the figure.\n");
					}
					if(n_5=='c')
					{
						float c_5[3],x_5,y_5,r;
						for(int i=0;i<3;i++) scanf("%f",&c_5[i]);
						scanf("%f%f",&x_5,&y_5);
						r=(x_5-c_5[0])*(x_5-c_5[0])+(y_5-c_5[1])*(y_5-c_5[1]);
						if( r < (c_5[2]*c_5[2]) )printf("The point is contained in the figure.\n");
						else printf("The point is not contained in the figure.\n");
					}
					if(n_5=='t')
					{
						float t_5[3][2],x_5,y_5,v[3][2],u_,v_;
						for(int i=0;i<3;i++)for(int j=0;j<2;j++)scanf("%f",&t_5[i][j]);
						scanf("%f%f",&x_5,&y_5);
						v[0][0]=t_5[2][0]-t_5[0][0];
						v[0][1]=t_5[2][1]-t_5[0][1];
						v[1][0]=t_5[1][0]-t_5[0][0];
						v[1][1]=t_5[1][1]-t_5[0][1];
						v[2][0]=x_5-t_5[0][0];
						v[2][1]=y_5-t_5[0][1];
						float delta=(v[0][0]*v[1][1]-v[0][1]*v[1][0]);
						u_=(v[2][0]*v[1][1]-v[2][1]*v[1][0])/delta;
						v_=(v[0][0]*v[2][1]-v[0][1]*v[2][0])/delta;
						if( u_<1 && v_<1 && u_>0 && v_>0 )printf("The point is contained in the figure.\n");
						else printf("The point is not contained in the figure.\n");
					}

				}
				break;
		case 6: ;
				char in_6[100],name[50][50],todo[3][20]={"abs","negate","print"};
				lld bignum[50];
				int ct_6=0;
				while(gets(in_6)!=NULL)
				{
					for(int i=0;in_6[i]!='\0';i++) if(in_6[i]=='(')in_6[i]='\0';
					if(in_6[0]=='l' && in_6[1]=='o' && in_6[11]=='n' && in_6[12]=='t')
					{
						int i=14,j;
						for(i;in_6[i]!=' ';i++) name[ct_6][i-14]=in_6[i];
						name[ct_6][i-14]='\0';
						j=i+2;
						char temp[20];
						for(i=j ; in_6[i]!=';' ; i++) temp[i-j]=in_6[i];
						temp[i-j]='\0';
						bignum[ct_6]=atoll(temp);
						ct_6++;
					}
					else if(strcmp(todo[0],in_6)==0)
					{
						char temp[20];
						int i=4;
						for(i;in_6[i]!=')';i++)temp[i-4]=in_6[i];
						temp[i-4]='\0';
						for(int i=0;i<ct_6;i++)
							if(strcmp(name[i],temp)==0)bignum[i]=llabs(bignum[i]);
						//printf("%lld\n",bignum[0]);
					}
					else if(strcmp(todo[1],in_6)==0)
					{	

						char temp[20];
						int i=7;
						for(i;in_6[i]!=')';i++)temp[i-7]=in_6[i];
						temp[i-7]='\0';
						for(int i=0;i<ct_6;i++)	if(strcmp(name[i],temp)==0)bignum[i]*=-1;
						//printf("%lld\n",bignum[0]);
					}
					else if(strcmp(todo[2],in_6)==0)
					{	
						char temp[20];
						int i=6;
						for(i;in_6[i]!=')';i++)temp[i-6]=in_6[i];
						temp[i-6]='\0';
						for(int i=0;i<ct_6;i++)	if(strcmp(name[i],temp)==0)	printf("%lld\n",bignum[i]);
					}
					for(int z=0;in_6[z]!='\0';z++)
					{
						if(in_6[z]=='=' &&( in_6[z-1]=='+' || in_6[z-1]=='-') )
						{
							for(int i=0;in_6[i]!='\0';i++)
							{
								char temp_[2][20];
								int j;
								for(j=0;in_6[j]!=' ';j++)temp_[0][j]=in_6[j];
								temp_[0][j]='\0';
								if(in_6[i]=='+')
								{
									for(j=i+3;in_6[j]!=';';j++)temp_[1][j-i-3]=in_6[j];
									temp_[1][j-i-3]='\0';
									for(int k=0;k<ct_6;k++)
										if(strcmp(temp_[0],name[k])==0)
											for(int j=0;j<ct_6;j++)
												if(strcmp(temp_[1],name[j])==0)
													bignum[k]+=bignum[j];
								}
								if(in_6[i]=='-')
								{
									for(j=i+3;in_6[j]!=';';j++)temp_[1][j-i-3]=in_6[j];
									temp_[1][j-i-3]='\0';
									for(int k=0;k<ct_6;k++)
										if(strcmp(temp_[0],name[k])==0)
											for(int j=0;j<ct_6;j++)
												if(strcmp(temp_[1],name[j])==0)
													bignum[k]-=bignum[j];
								}
							}
						}
					}
				}
				break;
	}
	return 0;
}
