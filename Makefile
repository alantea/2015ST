all: main.cpp  main_unittest.cpp
	g++ main.cpp  main_unittest.cpp -lgtest -lgtest_main -pthread -o hw1.exe
clean:
	rm -f hw1.exe
