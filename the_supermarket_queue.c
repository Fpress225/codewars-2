int arr_min(int array_n[], int n) {
    int min_index = 0;
    int mimimum_time_for_the_customer = array_n[0];
    for (int i = 0; i < n; i++) {
      if (mimimum_time_for_the_customer > array_n[i]) {
        mimimum_time_for_the_customer = array_n[i];
        min_index = i;
      }
    }
    return min_index;
  }

  int index_in_the_maximum_element_in_the_array(int array_n[], int n) {
    int maximum_time_for_the_customer = array_n[0];
    for (int i = 0; i < n; i++) {
      if (maximum_time_for_the_customer < array_n[i]) {
        maximum_time_for_the_customer = array_n[i];
      }
    }
    return maximum_time_for_the_customer;
  }

int queue_time(const int *customers, int customers_length, int n) { 
  if (*customers != 0) {
    if (n >= customers_length) { 
      int customers_time = customers[0]; 
      for (int i = 0; i < customers_length; i++) { 
        if (customers_time > customers[i]) { 
          customers_time = customers[i]; 
        } 
        return customers_time; 
      } 
    } else if (n <= 0) { 
      return 0; 
    } else if (n == 1) { 
      int customers_time = customers[0]; 
      for (int i = 1; i < customers_length; i++) { 
        customers_time += customers[i]; 
      } 
      return customers_time; 
    } else {
      int array_n[n - 1];
      for (int i = 0; i < n; i++) {
        array_n[i] = customers[i];
      }
      for (int i = n; i < customers_length; i++) {
        int index_in_the_array = index_in_the_minimum_element_in_the_array(array_n, n);
        array_n[index_in_the_array] += customers[i];
      }
      return index_in_the_maximum_element_in_the_array(array_n, n);
    }
  }
  return 0;
}
