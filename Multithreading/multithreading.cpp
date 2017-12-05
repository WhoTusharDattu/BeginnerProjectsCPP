/*
* Basic programme covering concepts of multithreading.
* https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
* Build with -lpthread
*/

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data {
   int  thread_id;
   char message[16];
};

void *print_message(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;

   cout << "Thread ID : " << my_data->thread_id ;
   cout << " Message : " << my_data->message << endl;

   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;
   void *status;

   for( i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      td[i].thread_id = i;
      strcpy(td[i].message, "This is message");
      rc = pthread_create(&threads[i], NULL, print_message, (void *)&td[i]);

      if (rc) {
         cout << "Error: unable to create thread," << rc << endl;
         exit(-1);
      }
      else {
          // Don't use pthread_join at this point. Why? Try it.
          // pthread_join(threads[i], &status);
      }
   }

   // Observe difference when pthread_join not used! Try commenting the code
   // main will exit only after all above threads are exited
   for( i = 0; i < NUM_THREADS; i++ ) {
       pthread_join(threads[i], &status);
   }

   cout << "Exiting main..." << endl;
   pthread_exit(NULL);
}
