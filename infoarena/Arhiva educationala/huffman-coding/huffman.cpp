
#include <stdio.h>

struct Node { long long val; long leftPos, rightPos; };

constexpr auto INF = 1LL * 1000000000 * 1000000000;

Node nodes[2000200];
long long len[1000200];
long long code[1000200];

long getNodePosWithMinValue(Node nodes[], long& i, long& qFront, long qEnd, long n)
{
	long pos = -1;
	if (nodes[i].val < nodes[qFront].val)
	{
		pos = i;
		++i;
	}
	else
	{
		pos = qFront;
		++qFront;
	}

	return pos;
}

long Huffman(Node nodes[], long n)
{
	long i = 0;
	long qFront = n + 1;
	long qEnd = n + 1;

	while (!(nodes[i].val == INF && nodes[qFront + 1].val == INF))
	{
		long leftPos = getNodePosWithMinValue(nodes, i, qFront, qEnd, n);
		long rightPos = getNodePosWithMinValue(nodes, i, qFront, qEnd, n);

		nodes[qEnd].val = nodes[leftPos].val + nodes[rightPos].val;
		nodes[qEnd].leftPos = leftPos;
		nodes[qEnd].rightPos = rightPos;

		++qEnd;
	}

	return qFront;
}

void DepthFirst(Node nodes[], long pos, long long int val = 0, long length = 0)
{
	if (nodes[pos].leftPos != -1)
	{
		DepthFirst(nodes, nodes[pos].leftPos, val * 2, length + 1);
		DepthFirst(nodes, nodes[pos].rightPos, val * 2 + 1, length + 1);
	}
	else
	{
		len[pos] = length;
		code[pos] = val;
	}
}

int main()
{
	freopen("huffman.in", "r", stdin);
	freopen("huffman.out", "w", stdout);

	long n;
	scanf("%ld", &n);

	for (long i = 0; i < n; ++i)
	{
		scanf("%lld", &nodes[i].val);
		nodes[i].leftPos = -1;
		nodes[i].rightPos = -1;
	}

	for (long i = n; i <= 2 * n; ++i)
	{
		nodes[i].val = INF;
		nodes[i].leftPos = -1;
		nodes[i].rightPos = -1;
	}

	long root = Huffman(nodes, n);

	DepthFirst(nodes, root);

	long long unsigned lg = 0;
	for (long i = 0; i < n; ++i)
	{
		lg += len[i] * nodes[i].val;
	}

	printf("%lld\n", lg);

	for (long i = 0; i < n; ++i)
	{
		//std::cout<< code[i] <<'\n';
		printf("%lld %lld\n", len[i], code[i]);
	}

	return 0;
}