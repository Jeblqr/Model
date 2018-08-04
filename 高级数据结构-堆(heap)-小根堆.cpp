#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#include<map>
#define Max 1000000
using namespace std;


class heap
{
	int heap[Max+100];
	long long hsize,next,now;
	public:
		void clear();
		void push(int x);
		void pop();
		int top();
		long long size();
};

void heap::clear()
{
	memset(heap,0,sizeof heap);
	hsize=0;
}

void heap::push(int x)
{
	heap[++hsize]=x;
	now=hsize,next=hsize/2;
	while (now)
	{
		if (heap[now]<heap[next])
			swap(heap[now],heap[next]);
		else
			break;
		now=next,next=now/2;
	}
}

void heap::pop()
{
	heap[1]=heap[hsize];
	hsize--;
	now=1,next=now*2;
	while (next<=hsize)
	{
		if (next<hsize&&heap[next]>heap[next+1])
			next++;
		if (heap[now]>heap[next])
			swap(heap[now],heap[next]);
		else	
			return;
		now=next,next=now*2;
	}
}

int heap::top()
{
	return heap[1];
}

long long heap::size()
{
	return hsize+1;
}


heap h;

int main()
{
	int n;
	cin>>n;
	int k;
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		if (k==1)
		{
			cin>>k;
			h.push(k);
			continue;
		}
		if (k==2)
		{
			cout<<h.top()<<endl;
			continue;
		}
		h.pop();
	}
	//system("pause");
	return 0;
}
