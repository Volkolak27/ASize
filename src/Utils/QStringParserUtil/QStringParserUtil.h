#ifndef QSTRINGPARSERUTIL_H
#define QSTRINGPARSERUTIL_H

#include "src/Utils/QStringParserUtil/PartOfString.h"
#include <QList>

class QStringParserUtil
{
	//// Методы
	public:
		static QList<PartOfString> makePartsFromString(const QString& string);
		static QString makeStringFromParts(const QList<PartOfString>& parts);
		static QList<PartOfString> multiplyDigitPartsBy(const QList<PartOfString>& parts, const double& multiplyBy);
};

#endif // QSTRINGPARSERUTIL_H
