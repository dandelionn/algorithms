#include <fstream>
#include <vector>
#include <limits>

using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

std::vector<int> runAlgorithm();
void findLongestSequence();
int findPosition(int);
void extractLongestSequence();
void initTrace(int size);

std::vector<int> _temp;
std::vector<int> _input;
std::vector<int> _output;
std::vector<int> _trace;
std::vector<int>::iterator it;

int n, x;
int main()
{
	f >> n;
	int x;

	for (int i = 0; i < n; i++)
	{
		f >> x;
		_input.push_back(x);
	}

	_output = runAlgorithm();

	g << _output.size() << '\n';
	for (it = _output.begin(); it != _output.end(); ++it)
	{
		g << *it << ' ';
	}

	return 0;
}

void initTrace(int size)
{
	_trace.assign(size, -1);
}

std::vector<int> runAlgorithm()
{
	initTrace(_input.size());
	findLongestSequence();
	extractLongestSequence();

	return _output;
}

void findLongestSequence()
{
	int pos;
	for (int i = _input.size() - 1; i >= 0; --i)
	{
		pos = findPosition(_input[i]);

		if (pos == -1)
		{
			if (_temp.size() > 0)
			{
				_trace[i] = _temp.front();
			}

			_temp.insert(_temp.begin(), i);
		}
		else
		{
			if ((pos + 1) < _temp.size())
			{
				_trace[i] = _temp[pos + 1];
			}

			_temp[pos] = i;
		}
	}
}

int findPosition(int x)
{
	if (_temp.size() == 0)
	{
		return -1;
	}

	int start = 0;
	int end = _temp.size() - 1;
	int m = (start + end) / 2;

	while (true)
	{
		if (m == 0)
		{
			if (x < _input[_temp[0]])
			{
				return -1;
			}

			if (x == _input[_temp[0]])
			{
				return 0;
			}

			if (x > _input[_temp[0]] && _temp.size() == 1)
			{
				return 0;
			}

			if (_temp.size() > 1)
			{
				if (x >= _input[_temp[0]] && x < _input[_temp[1]])
				{
					return m;
				}
			}

			if (x > _input[_temp[0]])
			{
				start = m + 1;
			}
		}

		if (m == (_temp.size() - 1) && _temp.size() > 1)
		{
			if (x >= _input[_temp[m]])
			{
				return m;
			}
			if (x < _input[_temp[m]])
			{
				end = m - 1;
			}
		}

		if (m != 0 && m != (_temp.size() - 1))
		{
			if (x >= _input[_temp[m]] && x < _input[_temp[m + 1]])
			{
				return m;
			}
			if (x < _input[_temp[m]])
			{
				end = m - 1;
			}
			if (x >= _input[_temp[m + 1]])
			{
				start = m + 1;
			}
		}
		m = (start + end) / 2;
	}
}

void extractLongestSequence()
{
	int i = _temp[0];
	while (i != -1)
	{
		_output.push_back(_input[i]);
		i = _trace[i];
	}
}