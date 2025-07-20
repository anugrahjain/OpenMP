This project provides easier programs to learn OpenMP using C and C++.  
It uses gcc as the underlying C compiler. 
Following commands can be used to compile and run an openmp program.
  gcc -fopenmp program_name.c
  ./a.out
Following command is required to compile the sobel filter file.
  g++ 12_sobel_filter.cpp -fopenmp `pkg-config --cflags --libs opencv4`
