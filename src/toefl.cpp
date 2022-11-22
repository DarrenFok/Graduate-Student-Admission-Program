#include "toefl.hpp"

//getters and setters
//reading
void toefl::setReading(int input){
	reading = input;
}

int toefl::getReading() const{
	return reading;
}

//listening
void toefl::setListening(int input){
	listening = input;
}

int toefl::getListening() const{
	return listening;
}

//speaking
void toefl::setSpeaking(int input){
	speaking = input;
}

int toefl::getSpeaking() const{
	return speaking;
}

//writing
void toefl::setWriting(int input){
	writing = input;
}

int toefl::getWriting() const{
	return writing;
}

//total
void toefl::setTotal(){
	total = reading + listening + speaking + writing;
}

int toefl::getTotal() const{
	return total;
}