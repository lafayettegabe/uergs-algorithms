int better_than_average(int class_points[], int class_size, int your_points) {
  int t = 0;
  for (int i = 0; i < class_size; i++)
  {
    t += class_points[i];
  }
  
  return your_points > t/class_size;
}
