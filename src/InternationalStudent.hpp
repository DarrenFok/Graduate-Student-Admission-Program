#include "student.hpp"
#include "toefl.hpp"

class InternationalStudent : public Student{
public:
	//overload the operator
	friend std::ostream& operator<<(std::ostream& os, const InternationalStudent& inputIS);

	//getter, setter
	void setCountry(string input);
	string getCountry() const;

	//compare
	string compareCountry(const InternationalStudent& IS1, const InternationalStudent& IS2);

	void setTOEFL(const toefl input);
	toefl& getTOEFL() const;


private:
	string country;
	toefl TOEFL;

};
