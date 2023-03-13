/*
https://codeforces.com/problemset/problem/1659/D

���� t(��1000) ��ʾ t �����ݣ�ÿ���������� n(��2e5) �ͳ�Ϊ n ������ c(0��c[i]��n)��
�������ݵ� n ֮�Ͳ����� 2e5��

����ֻ�� 0 �� 1 ������ a������ b[i] Ϊ�� a ��ǰ i ��Ԫ�ش�С���������������飨�±�� 1 ��ʼ����
���� c[j] = b[1][j] + b[2][j] + ... + b[n][j]��
�������� c ��������ˣ����㹹������һ������Ҫ������� a�����뱣֤���� a ���ڡ�
*/
/*
��ʾ 1�������⵽һ�㣬˼�� a ��ֻ��һ�� 1 ʱ������ c ����ʲô���ġ�����Դ���� 1 ��ĩβ��ʼ˼����

��������������

��ʾ 2��a �� 1 ���������� sum(c)/n������ k��

��ʾ 3�����Ե��Ź��� a��

��ʾ 4������ c[n]=n����ʱ a[n]=1��
Ϊ�˰�����ת���� n-1 ���������⣬��Ҫ�� c ��ȥ�� b[n] ������Ӱ�졣���ȥ����
���� b[n] ��һ��ĩβ�� k �� 1 �����飬���԰� c �е� [n-k+1,n] ����һ���ɡ�
�ò������/��״����/�߶���ʵ�֡�
����˼����ע��ÿ�ζ���Ҫ�� b[i] ������Ӱ��ȥ����
*/
// ��ϰ��״����
#include<bits/stdc++.h>
using namespace std;

#define pr pair<int,int>
#define lowbit(x) x&(-x)
#define int long long
 
using namespace std;
 
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
 
int T,n,tr[200005];
 
void modify(int x,int k)
{
	for(;x<=n;x+=lowbit(x))
		tr[x]+=k; 
}
 
int query(int x)
{
	int ret=0;
	for(;x;x-=lowbit(x))
		ret+=tr[x];
	return ret;
}
 
int a[200005],ans[200005];
 
signed main()
{
	T=read();
	while(T--)
	{
		n=read();int sum=0;
		fill(tr,tr+n+1,0);
		for(int i=1;i<=n;i++)
			a[i]=read(),sum+=a[i];
		sum/=n;
		for(int i=n;i>=1;i--)
		{
			if(a[i]+query(i)==i)
				ans[i]=1;
			else
				ans[i]=0;
			modify(i-sum+1,-1);
			if(ans[i]==1)
				sum--;
		}
		for(int i=1;i<=n;i++)
			printf("%lld ",ans[i]);
		puts("");
	}
	return 0;
}
