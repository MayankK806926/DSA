int remove(int start, vector<int>& numbers, int n, int k) {
      if (n == 1)
          return numbers[0];
      start = (start + k-1) % n;
      numbers.erase(numbers.begin() + start);

      return remove(start, numbers, n - 1, k);
  }

  int josephus(int n, int k)
  {
      vector<int> numbers(n);
      for (int i = 0; i < n; i++)
          numbers[i] = i + 1;
  
      int start = 0;
      return remove(start, numbers, n, k);
  }
