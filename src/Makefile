#compile and link the application
all: main

#run the application
run: main
	./main

#link the stuff to executable main
main: main.o student.o stu_sort.o toefl.o
	g++ -g -o main main.o student.o stu_sort.o toefl.o

#compile the main.cpp to main.o
main.o: main.cpp student.cpp stu_sort.cpp toefl.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp student.hpp
	g++ -g -c student.cpp


#compile the stu_sort.cpp to stu_sort.o
stu_sort.o: stu_sort.cpp stu_sort.hpp
	g++ -g -c stu_sort.cpp

#compile the toefl.cpp to toefl.0
toefl.o: toefl.cpp toefl.hpp
	g++ -g -c toefl.cpp

#remove built files
clean:
	rm -rf main main.o student.o stu_sort.o toefl.o *~
