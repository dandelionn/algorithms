#include <payment_with_minimal_value_of_bancnotes.h>
#include <algorithm>

std::vector<int> findMinimalAmountOfBancnotes(std::vector<int> bancnotes, int sum)
{
	std::sort(bancnotes.begin(), bancnotes.end(), std::greater<int>());
	auto result = std::vector<int>();
    auto i=0;
    while( sum != 0 )
    {
		if( sum / bancnotes[i] != 0 )
        {
			result.push_back(sum / bancnotes[i]);
            sum = sum % bancnotes[i];
        }
		i++;
	}
	return result;
}