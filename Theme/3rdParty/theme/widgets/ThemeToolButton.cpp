#include "ThemeToolButton.h"
#include "theme/theme.h"
#include <QStyle>
#include <QStyleOption>
#include <QLatin1Char>

using namespace Utils;
ThemeToolButton::ThemeToolButton(QAction* action, QWidget *parent)
    :QToolButton(parent)
{
    QString stylesheet = " \
      QToolButton{         \
         border: none;     \
         background: none; \
      }                    \
      QToolButton:hover    \
      {                    \
          border: none;    \
          background-color: #%1;\
      }                    \
      QToolButton:selected \
      {                    \
          border: none;    \
          background-color: #%2; \
      }";

      QColor hoverColor = creatorTheme()->color(Theme::BackgroundColorHover);
      QColor selectedColor = creatorTheme()->color(Theme::BackgroundColorSelected);

      /* 0.6 transparent*/
      stylesheet = stylesheet.arg(((hoverColor.rgb() & 0xFFFFFF) | 0x99000000), 6, 16, QLatin1Char('0'))
              .arg(((selectedColor.rgb() & 0xFFFFFF) | 0x99000000), 6, 16, QLatin1Char('0'));
//      setStyleSheet(stylesheet);
      setStyleSheet("border: none;");

      if (nullptr != action)
          this->setDefaultAction(action);

      this->setToolButtonStyle(Qt::ToolButtonIconOnly);
}

void ThemeToolButton::setFlatToolButton(QToolButton* btn)
{
    QString stylesheet = " \
      QToolButton{         \
         border: none;     \
         background: none; \
      }                    \
      QToolButton:hover    \
      {                    \
          border: none;    \
          background-color: #%1;\
      }                    \
      QToolButton:selected \
      {                    \
          border: none;    \
          background-color: #%2; \
      }";

      QColor hoverColor = creatorTheme()->color(Theme::BackgroundColorHover);
      QColor selectedColor = creatorTheme()->color(Theme::BackgroundColorSelected);

      /* 0.6 transparent*/
      stylesheet = stylesheet.arg(((hoverColor.rgb() & 0xFFFFFF) | 0x66000000), 6, 16, QLatin1Char('0'))
              .arg(((selectedColor.rgb() & 0xFFFFFF) | 0x66000000), 6, 16, QLatin1Char('0'));
      btn->setStyleSheet(stylesheet);

}


