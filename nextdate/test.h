#ifndef GTEST_H_
#define GTEST_H_

class date
{
	public:
		int year;
		int month;
		int day;
		date();
		date(int m, int d, int y);
		void putdate(int m, int d, int y);
};

date nextdate(int month, int day ,int year);



#endif
