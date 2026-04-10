#ifndef THEMETOOLBUTTON_H
#define THEMETOOLBUTTON_H

#include <QToolButton>
#include <QObject>

class ThemeToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ThemeToolButton(QAction* action = nullptr, QWidget *parent = nullptr);
    static void setFlatToolButton(QToolButton* btn);
};

#endif // THEMETOOLBUTTON_H
