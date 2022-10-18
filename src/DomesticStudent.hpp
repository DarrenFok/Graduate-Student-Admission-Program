#include "student.hpp"

//DomesticStudent child class of Student
class DomesticStudent : public Student{
public:
	//province
	void SetProvince(string province);
	string getProvince() const;

private:
	string province;

};
