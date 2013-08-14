// benchmark.c
#include <stdio.h>
#include <time.h>  

main()
{
  printf("\nStarting Test\n");
  time_t startTime = clock();
  
  // test code here
  long  i = 0;
  long j = 0;
  for (i = 0; i < 20000000; i ++)
  {
    j = i + i * 10;
    if (j > 10) j = 0;
  }
  // end of test code
  time_t endTime = clock();
  
  printf("%ld\n", j); // prevent loop being optimized out
  printf("Finished Test\n");
  double timeSpent = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  printf("seconds taken: %f\n", timeSpent); 
  return 0;
}
