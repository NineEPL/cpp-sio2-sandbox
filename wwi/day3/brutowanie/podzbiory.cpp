#include <vector>
#include <iostream>

int main()
{
    int n = 4;
    std::vector<int> vec;

    for (int i = 1; i <= n; i++) vec.push_back(i);

    for (uint mask = 0; mask < (1 << 4); mask++)
    {
        std::vector<int> podzbior;

        for (int i = 0; i < n; i++)
        {
            // Używamy 1U, żeby było unsigned. Żeby używać mask bitowych
            // długości większej niż 32, trzeba pisać 1ULL żeby to 1 było
            // 64-bitowe.
            if ((1U << i) & mask)
            {
                podzbior.push_back(vec[i]);
            }
        }

        for (int elem : podzbior) std::cout << elem << " ";
        std::cout << "\n";
    }
}