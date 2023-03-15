#include <vector>

long getJumps(const std::vector<int>& cycle, long long k) 
{
  int contador = 0;
  int soma = 0;
 for(auto i: cycle)
  {
    soma++;
  }
  return soma;
}