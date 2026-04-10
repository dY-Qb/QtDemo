#include "SvgIcon.h"
#include <QByteArray>
#include <QFile>
#include <QSvgRenderer>
#include <QDomDocument>
#include <QPainter>
#include <QRegularExpression>
#include <QIcon>
#include "log.h"

SvgIcon::SvgIcon(const QString& path, bool bystyle, const QRgb& rgb)
{
    mPath = path;
    mByStyle = bystyle;
    mSetColor = rgb;
}

QIcon SvgIcon::icon()
{
    if (mPath.size() == 0
            || (!mPath.toLower().endsWith(".svg"))
            || (!QFile(mPath).exists())) {
        return QIcon();
    }

    if (mByStyle)
        mSetColor = Utils::creatorTheme()->color(Utils::Theme::IconsBaseColor).rgb();

    return ChangeSVGColor(mPath, mSetColor);
}

void SvgIcon::SetAttrRecur(QDomElement &elem, QString strtagname, QString strattr, QString strattrval)
{
    // if it has the tagname then overwritte desired attribute
    if (elem.tagName().compare(strtagname) == 0)
    {
        elem.setAttribute(strattr, strattrval);
    }
    // loop all children
    for (int i = 0; i < elem.childNodes().count(); i++)
    {
        if (!elem.childNodes().at(i).isElement())
        {
            continue;
        }
        QDomElement subElement = elem.childNodes().at(i).toElement();
        SetAttrRecur(subElement/*elem.childNodes().at(i).toElement()*/, strtagname, strattr, strattrval);
    }
}

QIcon SvgIcon::ChangeSVGColor(const QString& filename, const QRgb& color)
{
    // open svg resource load contents to qbytearray
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QByteArray baData = file.readAll();
    // load svg contents to xml document and edit contents
    QDomDocument doc;
    doc.setContent(baData);
    // recurivelly change color
    QDomElement elem = doc.documentElement();
    SetAttrRecur(/*doc.documentElement()*/elem, "path", "fill",  QString("#%1").arg(color & 0x00FFFFFF, 6, 16, QLatin1Char('0')));
    // create svg renderer with edited contents
    QString stri = doc.toString();
    LOGD(stri);
    QSvgRenderer svgRenderer(doc.toByteArray());
    // create pixmap target (could be a QImage)
    QPixmap pix(svgRenderer.defaultSize());
    pix.fill(Qt::transparent);
    // create painter to act over pixmap
    QPainter pixPainter(&pix);
    // use renderer to render over painter which paints on pixmap
    svgRenderer.render(&pixPainter);
    QIcon myicon(pix);
    return myicon;
    // Use icon ....
}

