/*题目描述
Finding Missing Cards
Taro is going to play a card game. However, now he has only n cards, even though there should be 52 cards (he has no Jokers).
The 52 cards include 13 ranks of each of the four suits: spade, heart, club and diamond.
输入
In the first line, the number of cards n (n ≤ 52) is given.
In the following n lines, data of the n cards are given. Each card is given by a pair of a character and an integer which represent its suit and rank respectively. A suit is represented by ‘S’, ‘H’, ‘C’ and ‘D’ for spades, hearts, clubs and diamonds respectively. A rank is represented by an integer from 1 to 13.
输出
Print the missing cards. The same as the input format, each card should be printed with a character and an integer separated by a space character in a line. Arrange the missing cards in the following priorities:
Print cards of spades, hearts, clubs and diamonds in this order.
If the ranks are equal, print cards with lower ranks first.*/
//key1
#include <iostream>
using namespace std;
int main()
{
	int n,num;
	int S[14],H[14],C[14],D[14];
	char a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>num;
	    if(a=='S')
	    {S[num]=num;}
	    if(a=='H')
	    {H[num]=num;}
	    if(a=='C')
	    {C[num]=num;}
	    if(a=='D')
	    {D[num]=num;}
	}
	for(int j=1;j<14;j++)
	{
		if(S[j] !=j)
		{cout<<'S'<<" "<<j<<endl;}
		
	}
	for(int k=1;k<14;k++)
	{
		if(H[k] !=k)
		{cout<<'H'<<" "<<k<<endl;}
		
	}
	for(int l=1;l<14;l++)
	{
		if(C[l] !=l)
		{cout<<'C'<<" "<<l<<endl;}
		
	}
	for(int m=1;m<14;m++)
	{
		if(D[m] !=m)
		{cout<<'D'<<" "<<m<<endl;}
	}
	return 0;
}
//key2
#include<bits/stdc++.h> //改不了iostream
using namespace std;
int main()
{
    int n;
    cin >> n;
    char ch;
    int a[4][13], j0 = 0, j1 = 0, j2 = 0, j3 = 0;
    fill(a[0], a[0] + 52, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        if (ch == 'S')
        {
            cin >> a[0][j0];
            ++j0;
        }
        else if (ch == 'H')
        {
            cin >> a[1][j1];
            ++j1;
        }
        else if (ch == 'C')
        {
            cin >> a[2][j2];
            ++j2;
        }
        else
        {
            cin >> a[3][j3];
            ++j3;
        }

    }
    sort(a[0], a[0] + j0);
    sort(a[1], a[1] + j1);
    sort(a[2], a[2] + j2);
    sort(a[3], a[3] + j3);
    for (int i = 1, j = 0; i <= 13; i++)
    {
        if (a[0][j] != i)
            cout << "S " << i << endl;
        else
            ++j;
    }
    for (int i = 1, j = 0; i <= 13; i++)
    {
        if (a[1][j] != i)
            cout << "H " << i << endl;
        else
            ++j;
    }
    for (int i = 1, j = 0; i <= 13; i++)
    {
        if (a[2][j] != i)
            cout << "C " << i << endl;
        else
            ++j;
    }
    for (int i = 1, j = 0; i <= 13; i++)
    {
        if (a[3][j] != i)
            cout << "D " << i << endl;
        else
            ++j;
    }
    return 0;
}

/*{ 上课整的
	char s;
	struct Card{
		char s;
		int rank;
	};
	Card A[60];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i].s;
		cin>>A[i].rank;
	}
	for(int j=1;j<=13;j++)
	{
		for(int b=1;b<=4;b++)
		{
			
		}
	}
	switch(a)
	{
		case'S':break;
		case'H':break;
		case'C':break;
		case'D':break;
		
	}
}*/