#include "QStringParserUtil.h"

QList<PartOfString> QStringParserUtil::makePartsFromString(const QString& string)
{
	QList<PartOfString> result = QList<PartOfString>();

	if (string.length() > 0)
	{
		bool isDigitFlag = string[0].isDigit();
		QString tempPart = string[0];

		for (int i = 1; i < string.length(); i++)
		{
			if (isDigitFlag)
			{
				// Собираем цифры
				if (string[i].isDigit())
				{
					tempPart.append(string[i]);
				}
				else
				{
					result.append(PartOfString(tempPart));
					tempPart = string[i];
					isDigitFlag = false;
				}
			}
			else
			{
				// Собираем НЕ цифры
				if (!string[i].isDigit())
				{
					tempPart.append(string[i]);
				}
				else
				{
					result.append(PartOfString(tempPart));
					tempPart = string[i];
					isDigitFlag = true;
				}
			}
		}

		result.append(PartOfString(tempPart)); // дописываем хвост/остаток
	}

	return result;
}

QString QStringParserUtil::makeStringFromParts(const QList<PartOfString>& parts)
{
	QString result = "";

	for (const PartOfString& item : parts)
	{
		result.append(item.text);
	}

	return result;
}

QList<PartOfString> QStringParserUtil::multiplyDigitPartsBy(const QList<PartOfString>& parts, const double& multiplyBy)
{
	QList<PartOfString> result = QList<PartOfString>();

	for (const PartOfString& part : parts)
	{
		if (part.isDigit)
		{
			double digit = part.text.toDouble() * multiplyBy;
			result.append( PartOfString(QString::number(digit)) );
		}
		else
		{
			result.append( PartOfString(part.text) );
		}
	}

	return result;
}
