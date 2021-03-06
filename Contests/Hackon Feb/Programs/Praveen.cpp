#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &primes_till, int LIMIT)
{
    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(long long i = 2; i*i <= LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*i; multiple <= LIMIT; multiple += i)
            {
                is_prime[multiple] = false;
            }
        }
    }

    for(int i = 2; i <= LIMIT; i++)
        primes_till[i] = primes_till[i - 1] + is_prime[i];
}

int main()
{
    const int LIMIT = 1e6;
    vector <int> primes_till(LIMIT + 1, 0);
    precompute(primes_till, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        double primes_in_range = 1.0*(primes_till[right] - primes_till[left - 1]);
        double range = 1.0*(right - left + 1);

        double probability = primes_in_range/range;
        printf("%.6lf\n", probability);
    }

    return 0;
}
