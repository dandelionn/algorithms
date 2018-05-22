
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream f("huffman.in");
ofstream g("huffman.out");

struct Nod { int pos, val; Nod *next, *prev1, *prev2; };
struct cmp {
	bool operator()(Nod* x, Nod* y) const
	{
		return x->val > y->val;
	}
};

priority_queue<Nod*, vector<Nod*>, cmp> heap;

int n, i;
long long unsigned a[1000001];
long long unsigned len[1000001];
long long unsigned code[1000001];

Nod* Huffman()
{
	while (heap.size()>1)
	{
		Nod *c1 = heap.top();
		heap.pop();
		Nod *c2 = heap.top();
		heap.pop();

		Nod* p = new Nod;
		p->val = c1->val + c2->val;
		c1->next = p;
		c2->next = p;

		p->prev1 = c1;
		p->prev2 = c2;
		p->next = NULL;

		heap.push(p);
	}

	return heap.top();
}

void DepthFirst(Nod* nod, long long int val = 0, int length = 0)
{
	if (nod->prev1 != NULL)
	{
		val = val * 2;
		DepthFirst(nod->prev1, val, length + 1);
		val = val / 2;
	}

	if (nod->prev2 != NULL)
	{
		val = val * 2 + 1;
		DepthFirst(nod->prev2, val, length + 1);
		val = val / 2;
	}


	if (nod->prev2 == NULL && nod->prev1 == NULL)
	{
		len[nod->pos] = length;
		code[nod->pos] = val;
	}
}

int main()
{
	f >> n;
	for (i = 0; i<n; i++)
	{
		f >> a[i];
		Nod *nod = new Nod;
		nod->pos = i;
		nod->val = a[i];
		nod->next = NULL;
		nod->prev1 = NULL;
		nod->prev2 = NULL;
		heap.push(nod);
	}

    Nod* root;
	root = Huffman();
	DepthFirst(root);

	long long unsigned lg = 0;
	for (i = 0; i < n; i++)
	{
		lg += len[i] * a[i];
	}

	g << lg << '\n';

	for (i = 0; i < n; i++)
	{
		g << len[i] << ' ' << code[i] << '\n';
	}

	f.close();
	g.close();

	return 0;
}
