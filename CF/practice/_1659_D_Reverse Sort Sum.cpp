/*
https://codeforces.com/problemset/problem/1659/D

输入 t(≤1000) 表示 t 组数据，每组数据输入 n(≤2e5) 和长为 n 的数组 c(0≤c[i]≤n)。
所有数据的 n 之和不超过 2e5。

对于只有 0 和 1 的数组 a，定义 b[i] 为把 a 的前 i 个元素从小到大排序后的新数组（下标从 1 开始）。
定义 c[j] = b[1][j] + b[2][j] + ... + b[n][j]。
现在数组 c 输入给你了，请你构造任意一个符合要求的数组 a。输入保证数组 a 存在。
*/
/*
提示 1：从特殊到一般，思考 a 中只有一个 1 时，数组 c 会是什么样的。你可以从这个 1 在末尾开始思考。

看到不变量了吗？

提示 2：a 中 1 的数量等于 sum(c)/n，记作 k。

提示 3：试试倒着构造 a。

提示 4：假设 c[n]=n，此时 a[n]=1。
为了把问题转换成 n-1 个数的问题，需要从 c 中去掉 b[n] 带来的影响。如何去掉？
由于 b[n] 是一个末尾有 k 个 1 的数组，所以把 c 中的 [n-k+1,n] 都减一即可。
用差分数组/树状数组/线段树实现。
继续思考，注意每次都需要把 b[i] 带来的影响去掉。
*/
// 补习树状数组
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
