class toefl{
public:
	//getters and setters
	//reading
	void setReading(int input);
	int getReading() const;

	//listening
	void setListening(int input);
	int getListening() const;

	//speaking
	void setSpeaking(int input);
	int getSpeaking() const;

	//writing
	void setWriting(int input);
	int getWriting() const;

	//total
	void setTotal();
	int getTotal() const;

private:
	int reading;
	int listening;
	int speaking;
	int writing;
	int total;

};
