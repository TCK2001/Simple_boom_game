#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <ctime>
 
using namespace std;

int main()
{
a:	int a=0,b=0;
	cout<<"Set the size of Matrix."<<endl;
	//set Matrix size;
	while(cin>>a>>b) 
	{
		char save[a][b]={'\n'};
		char map[a][b]={'\n'};
		char c;
		
		if(a!=0&&b!=0)
		{
			cout<<"What character want to use ?"<<endl;
			cin>>c;
			cout<<"Example : Your Matrix : "<<endl;
			//Draw Matrix;
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<b;j++)
				{
					cout<<c<<" ";
					map[i][j]=c;
				}
				cout<<endl;
			}
			
			//set the boom coordinate;
			int randomx[a]={0},randomy[b]={0},check=0;
			if(a<=b)
			{
				int check=0;
				for(int i=0;i<a;i++)
				{
					randomx[i]=rand()%a;
					randomy[i]=rand()%a;
					//cout<<randomx[i]<<" "<<randomy[i]<<" "<<endl;		
				}
				
				for(int i=0;i<a;i++)
				{
					for(int j=i;j<a;j++)
					{
						if(randomx[j]==randomx[i])
						{
							int temp=0;
							temp=rand()%a;
							randomx[j]=temp;
						}
					}	
				}
				for(int i=0;i<a;i++)
				{
					for(int j=i;j<a;j++)
					{
						if(randomy[j]==randomy[i])
						{
							int temp=0;
							temp=rand()%a;
							randomy[j]=temp;
						}
					}	
				}
//				cout<<"After fix : "<<endl;
//				for(int i=0;i<a;i++)
//				{
//					cout<<randomx[i]<<" "<<randomy[i]<<" "<<endl;		
//				}	
			}
			else if(a>=b)
			{
				check=1;
				for(int i=0;i<b;i++)
				{
					randomx[i]=rand()%b;
					randomy[i]=rand()%b;
					//cout<<randomx[i]<<" "<<randomy[i]<<" "<<endl;		
				}
				for(int i=0;i<b;i++)
				{
					for(int j=i;j<b;j++)
					{
						if(randomx[j]==randomx[i])
						{
							int temp=0;
							temp=rand()%b;
							randomx[j]=temp;
						}
					}	
				}
				for(int i=0;i<b;i++)
				{
					for(int j=i;j<b;j++)
					{
						if(randomy[j]==randomy[i])
						{
							int temp=0;
							temp=rand()%b;
							randomy[j]=temp;
						}
					}	
				}
//				cout<<"After fix : "<<endl;
//				for(int i=0;i<b;i++)
//				{
//					cout<<randomx[i]<<" "<<randomy[i]<<" "<<endl;		
//				}		
			}
			
			 
				
			//set the boom in Matrix;	
			if(check==1)
			{
				for(int j=0;j<a;j++)
				{
					save[randomx[j]][randomy[j]]=1;
				}	
			}
			else if(check==0)
			{
				for(int j=0;j<b;j++)
				{	
					save[randomx[j]][randomy[j]]=1;
				}
			}
			int count=0;
			//start to choose the coordinate;
			while(1)
			{
				char cc;
				int x=0,y=0;
				int chk=0;
				cout<<"Choose the coordinate!"<<endl;
				cin>>x>>y;
				
				for(int i=0;i<a;i++)
				{
					for(int j=0;j<b;j++)
					{
						if(x==randomx[j]&&y==randomy[j])
						{
							cout<<"Boommmmmm!"<<endl;
							chk=1;
							map[x][y]='X';
							for(int i=0;i<a;i++)
							{
								for(int j=0;j<b;j++)
								{
									cout<<map[i][j]<<" ";
								}
								cout<<endl;
							}
							
							cout<<"You want to try again? (Y/N)"<<endl;
							cin>>cc;
							if(cc=='Y')
							{
								goto a;
							}
							else
							{
								return 0;
							}
						}
						else
						{
							map[x][y]='O';
						
							if(a<b)
							{
								if(count==a-1)
								{
									cout<<"Congratulations!"<<endl;
									cout<<"You want to try again? (Y/N)"<<endl;
									cin>>cc;
									if(cc=='Y')
									{
										goto a;
									}
									else
									{
										return 0;
									}
								}	
							}
							else if(a>b)
							{
								if(count==b-1)
								{
									cout<<"Congratulations!"<<endl;
									cout<<"You want to try again? (Y/N)"<<endl;
									cin>>cc;
									if(cc=='Y')
									{
										goto a;
									}
									else
									{
										return 0;
									}
								}		
							}
							else if(a==b)
							{
								if(count==a*a-1)
								{
									cout<<"Congratulations!"<<endl;
									cout<<"You want to try again? (Y/N)"<<endl;
									cin>>cc;
									if(cc=='Y')
									{
										goto a;
									}
									else
									{
										return 0;
									}	
								}						
							}
						}
					}
					count++;
					if(chk==1)
					{
						break;
					}	
				}	
			}
		}
	}
return 0;
}

