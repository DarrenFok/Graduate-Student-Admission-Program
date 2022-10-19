#include "student.hpp"

//DomesticStudent child class of Student
class DomesticStudent : public Student{
public:
	//overload <<
	friend std::ostream& operator<<(std::ostream& os, const DomesticStudent& inputDS);

	//province
	void setProvince(string province);
	string getProvince() const;

private:
	string province;

};
