#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  int d;
  scanf("%d", &n);
  int arr[n];
  for (size_t i = 0; i < n; i++) arr[i] = i;  // scanf("%d", &arr[i]);

  // Debugging
  //   for (size_t i = 0; i < n; i++) {
  //       printf("%d ", arr[i]);
  //   if (i==d) printf("\n********\n") ;
  // }

  scanf("%d", &d);
  if (d == 0 || d == n) {  // in this case there is no need to do any thing
    for (size_t i = 0; i < n; i++) {
      printf("%d ", arr[i]);
    }
    return 0;
  }
  int arrBackup[d];

  // get backup
  for (size_t i = 0; i < d; i++) arrBackup[i] = arr[n - d + i];

  // shift items
  for (int i = n; i >= d; i--) arr[i] = arr[i - d];

  for (size_t i = 0; i < d; i++) arr[i] = arrBackup[i];

  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    // if (i == d) printf("\n********\n");
  }
  return 0;
}
