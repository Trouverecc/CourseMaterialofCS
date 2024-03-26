#include<iostream>
#include<string.h>
using namespace std;
char ph[101][101];
bool ifx(int x1,int x2,int y1,int y2){      //判断该图形是否关于x轴对称,y轴同理
    if ((x1 - x2) % 2 != 0){
        for (int i = x2; i <= (x1 + x2) / 2; i++) {
            for (int j = y2; j <= y1; j++) {
                if (ph[i][j] != ph[x1][j]) {
                    if (ph[i][j] == '\0' && ph[x1][j] == ' ')
                        continue;
                    else if (ph[x1][j] == '\0' && ph[i][j] == ' ')
                        continue;
                    else
                        return false;
                }
            }
            x1--;
        }
        return true;
    }
    else {
        for (int i = x2; i < (x1 + x2) / 2; i++) {
            for (int j = y2; j <= y1; j++) {
                if (ph[i][j] != ph[x1][j]) {
                if (ph[i][j] == '\0' && ph[x1][j] == ' ')
                    continue;
                else if (ph[x1][j] == '\0' && ph[i][j] == ' ')
                    continue;
                else
                    return false;
                }
            }
            x1--;
        }
        return true;
    }
}

int main()
{
    int theF=1000;
    int p=0;
    int h=0,w=0;
    int n;
    char temp;
    cin>>n;
    temp=getchar(); 
    char str[110][110];
    char line[110];
    int i=0;
    while(i<n)
    {
     int mark=0; 
        int size;
        cin.getline(line+1,110);
        size=strlen(line+1);
        int j=1;
        while(j<=size)
        {
         if(line[j]!=32&&line[j]!='\n'&&line[j]!='\0') 
         {
          theF=min(theF,j);
    w=max(w,j);
    mark=1;
   }
         j++;
  }
  if(mark==1)
  {
   h++;
   int j=1;
   while(j<=size) 
   {
    str[h][j]=line[j];
    j++;
   }
  }
  i++;
 }
 i=1;
 while(i<=h)
 {
  int j=1;
  while(j<=w)
  {
   str[i][j]=str[i][j+theF-1];
   j++;
  }
  i++;
 }
 w-=theF-1;
 int judge1=0,judge2=0,judge3=0;       
   for(int i=1;i<=h;i++)
    {
     int j=1;
     while(j<=w)
     {
      if(str[i][j]!=32&&str[i][j]!='\n'&&str[i][j]!='\0')
      {
       if(str[i][j]!=str[h-i+1][j])judge1++; 
   }
      j++;
  }     
 }
 if(judge1==0)p+=2;         
    for(int i=1;i<=h;i++)
    {
     int j=1;
     while(j<=w)
     {
      if(str[i][j]!=32&&str[i][j]!='\n'&&str[i][j]!='\0')
      {
       if(str[i][j]!=str[i][w-j+1])judge2++; 
   }
      j++;
  }      
 }
 if(judge2==0)p+=1;
    for(int i=1;i<=h;i++)
    {
     int j=1;
     while(j<=w)
     {
      if(str[i][j]!=32&&str[i][j]!='\n'&&str[i][j]!='\0')
      {
       if(str[i][j]!=str[h-i+1][w-j+1])judge3++;
   }
      j++;
  }      
 }
 if(judge3==0)p+=3;
 cout<<p<<endl;
}