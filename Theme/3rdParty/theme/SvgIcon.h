#ifndef SVGICON_H
#define SVGICON_H

#include "utils/theme/theme.h"
#include <QDomElement>
#include <QIcon>
#include <QRgb>

class SvgIcon
{
public:
    SvgIcon(const QString& path, bool bystyle = true, const QRgb& rgb = 0);
    QIcon icon();

private:
    static void SetAttrRecur(QDomElement &elem, QString strtagname, QString strattr, QString strattrval);
    static QIcon ChangeSVGColor(const QString& filename, const QRgb& color);

    QString mPath;
    bool    mByStyle;
    QRgb    mSetColor;
};

#endif // SVGICON_H
