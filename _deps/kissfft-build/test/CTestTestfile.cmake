# CMake generated Testfile for 
# Source directory: /home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test
# Build directory: /home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(bm_kiss "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test/bm_kiss-float")
set_tests_properties(bm_kiss PROPERTIES  TIMEOUT "3600" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;5;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;22;add_kissfft_test_executable;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
add_test(bm_fftw "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test/bm_fftw-float")
set_tests_properties(bm_fftw PROPERTIES  TIMEOUT "3600" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;5;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;33;add_kissfft_test_executable;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
add_test(st "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test/st-float")
set_tests_properties(st PROPERTIES  TIMEOUT "3600" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;5;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;36;add_kissfft_test_executable;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
add_test(tkfc "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test/tkfc-float")
set_tests_properties(tkfc PROPERTIES  TIMEOUT "3600" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;5;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;38;add_kissfft_test_executable;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
add_test(ffr "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test/ffr-float")
set_tests_properties(ffr PROPERTIES  TIMEOUT "3600" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;5;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;41;add_kissfft_test_executable;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
add_test(tr "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test/tr-float")
set_tests_properties(tr PROPERTIES  TIMEOUT "3600" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;5;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;42;add_kissfft_test_executable;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
add_test(testcpp "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test/testcpp-float")
set_tests_properties(testcpp PROPERTIES  TIMEOUT "3600" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;5;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;44;add_kissfft_test_executable;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
add_test(testkiss.py "" "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/testkiss.py")
set_tests_properties(testkiss.py PROPERTIES  ENVIRONMENT "KISSFFT_DATATYPE=float;KISSFFT_OPENMP=OFF" TIMEOUT "3600" WORKING_DIRECTORY "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-build/test" _BACKTRACE_TRIPLES "/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;57;add_test;/home/ian/VSCODE/C++/Fourier Picture/build/_deps/kissfft-src/test/CMakeLists.txt;0;")
