#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "ststack.h"

int main()
{
 int adj[10][10],i,j,v,n,degree[10][2]={0},visited[10]={0};
 stack s;
 init(&s);

//  clrscr();
 printf("\nEnter how many vertices:");
 scanf("%d",&n);
 printf("\nEnter inputs for a graph having %d vertices",n);

 for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
	{
	 printf("\nConnection between %d and %d?(1/0):",i,j);
	 scanf("%d",&adj[i][j]);
	 if(i==j && adj[i][j]==1)
	   {
	    printf("\nSelf loop is not allowed");
	    getch();
	    exit(0);
	   }
	}
    }

 printf("\nAdjacency Matrix\n");
 for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
	printf("%d ",adj[i][j]);
     printf("\n");
    }

 for(i=0;i<n;i++)
    for(j=0;j<n;j++)
       degree[i][1] += adj[i][j];


  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
       degree[i][0] += adj[j][i];


  printf("\nIndegree Outdegree\n");
  for(i=0;i<n;i++)
    {
     for(j=0;j<2;j++)
	printf("%d\t",degree[i][j]);
     printf("\n");
    }

   while(1)
   {
      for(i=0;i<n;i++)
		{
	    if(degree[i][0]==0 && visited[i]!=1) // store all unvisited vertices whose indegree is zero
	       {
			  visited[i]=1;
			  push(&s,i);
			  printf("%d ",i);
	       }
	 	}

	 	if(isempty(&s))
	   	 break;

	 	v = pop(&s);  //delete a vertex whose indegree is zero
	 
		for(i=0;i<n;i++)
			{
			if(adj[v][i]==1)	//find adjacent vertices of deleted vertex
				degree[i][0] = degree[i][0]-1;  //decrement indegree of adjacent vertices
			}
   }


//  getch();
 return 0;
}