unsigned sequence_sum(unsigned start, unsigned end, unsigned step)
{
  int sum = 0;
  for (int i = start; i <= end; i += step)
    sum += i;
  return sum;
}
