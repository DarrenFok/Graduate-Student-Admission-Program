#compile and link the application
all: main

#run the application
run: main
	./main

#link the stuff to executable main
main: main.o student.o stu_sort.o dataBase.o DomesticStudent.o InternationalStudent.o
	g++ -g -o main main.o student.o stu_sort.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the dataBase.cpp to dataBase.o
dataBase.o: dataBase.cpp
	g++ -g -c dataBase.cpp

#compile the DomesticStudent.cpp to DomesticStudent.o
DomesticStudent.o: DomesticStudent.cpp
	g++ -g -c DomesticStudent.cpp

#compile the InternationalStudent.cpp to InternationalStudent.o
InternationalStudent.o: InternationalStudent.cpp
	g++ -g -c InternationalStudent.cpp

#compile the stu_sort.cpp to stu_sort.o
stu_sort.o: stu_sort.cpp
	g++ -g -c stu_sort.cpp

#remove built files
clean:
	rm -rf main main.o student.o stu_sort.o *~