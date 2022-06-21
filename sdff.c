int lengthSupUK(int n, int k) {
  int counter = 0;
  int u[n - 2];
  for (int i = 2; i < n - 2; i++) {
    u[i] = u[i - u[i - 2]] + u [i - u[i - 1]];
    if (u[i] >= k) {
      counter += 1;
    }
  }
  return counter;
}

int comp(int n) {
  return 0;
}
