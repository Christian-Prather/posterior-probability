Names: Christian Prather
CWID: 10711855
Structure: All the code is written in a single main.cpp file with functions to handle the calculation of probability per bag, choosing Cherry
           and choosing lime candies, there is also an additional function for generating the result.txt file. All 
           functions are called directly from int main()
Run instructions: This is compiled using cmake any version above 3.11 will be sufficent and should not throw errors
    Linux: 
        1) Enter the build directory
        2) run 'cmake ..' to generate the make files 
        3) run make -j8 (note j8 specifies using 8 threads only allocate as many as your comuter can handle, if unsure just run make with no flag)
        4) An executable called compute_a_posteriori will be generated in the build folder you may now run it with ./compute_a_posteriori and then add any sequence you want
            Ex) ./compute_a_posteriori CLLL
        5) A result.txt file will be generated in the build folder you may now open it 
    Windows:
        I recomend importing the project into clion and compilng that way as the c++ compiler on windows can be tricky
        