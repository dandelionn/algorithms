#include <fstream>
#include <vector>
 
constexpr int countsize = 256;
constexpr int bucketsize = 8;
constexpr unsigned char mask = 255;
 
int computeIndex(int val, int bucket)
{
	return val >> (bucket * bucketsize) & mask;
}
 
std::vector<int> computeFrequencies(const std::vector<int>& input, int bucket)
{
    std::vector<int> frequence(countsize, 0);
 
    for (auto it = input.cbegin(); it != input.cend(); ++it)
    {
        auto pos = computeIndex(*it, bucket);
        frequence[pos]++;
    }
 
    return frequence;
}
 
std::vector<int> computePositions(const std::vector<int>& frequence)
{
    std::vector<int> index(countsize, 0);
    int count = frequence[0];
 
    for (int i = 1; i < countsize; ++i)
    {
        if (frequence[i])
        {
            index[i] = count;
            count += frequence[i];
        }
    }
 
    return index;
}
 
std::vector<int> moveElements(const std::vector<int>& input, std::vector<int>& index, int bucket)
{
    std::vector<int> temp(input.size(), 0);
 
    for (auto it = input.cbegin(); it != input.cend(); ++it)
    {
        auto pos = computeIndex(*it, bucket);
        temp[index[pos]] = *it;
        index[pos]++;
    }
    return temp;
}
 
void sort(std::vector<int>& input)
{
	for (auto bucket = 0; bucket < 4; bucket++)
	{
        auto frequence = computeFrequencies(input, bucket);
        auto index = computePositions(frequence);
        input = moveElements(input, index, bucket);
	}
}
 
std::vector<int> generateInput(int N, int A, int B, int C)
{
    std::vector<int> input(N, 0);
    input[0] = B;
	for (int i = 1; i < N; i++)
	{
		input[i] = (1UL * A * input[i - 1] + B) % C;
	}
 
	return input;
}
 
int main()
{
    std::ifstream f("radixsort.in");
    std::ofstream g("radixsort.out");
 
    auto N=0, A=0, B=0, C=0;
	f >> N >> A >> B >> C;
    auto input = generateInput(N, A, B, C);
 
	sort(input);
 
    for (int i = 0; i < input.size(); i += 10)
	{
		g << input[i] << ' ';
	}
 
	return 0;
}