#ifndef PARTOFSTRING_H
#define PARTOFSTRING_H

#include <QString>

struct PartOfString
{
	QString text;
	bool isDigit;

	//// Методы
	public:
		PartOfString(QString text);
};

#endif // PARTOFSTRING_H
