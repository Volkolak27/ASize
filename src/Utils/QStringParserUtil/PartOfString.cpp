#include "PartOfString.h"

PartOfString::PartOfString(QString text)
{
	this->text = text;

	for (int i = 0; i < text.length(); i++)
	{
		if (!text[i].isDigit())
		{
			this->isDigit = false;
			return;
		}
	}

	this->isDigit = true;
}
