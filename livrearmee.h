#ifndef LIVREARMEE_H
#define LIVREARMEE_H

#include <QString>
#include <QtXml>
#include <iostream>
#include <QMessageBox>
#include <map>
#include <vector>
#include <QVBoxLayout>
#include <QRadioButton>
#include "optiongroupbox.h"

using std::map;

#define Options std::vector<OptionGroupBox*>

class LivreArmee
{
public:

    LivreArmee();
    void init(QString);
    QStringList getSeigneurs();
    QStringList getHeros();
    QStringList getBase();
    QStringList getSpeciales();
    QStringList getRares();

    QVBoxLayout *getOptions(QString);
private:
    QStringList seigneurs_;
    QStringList heros_;
    QStringList base_;
    QStringList speciales_;
    QStringList rares_;

    void initWithOptions(QString, QStringList*, QDomDocument*);
    void initOptionsLayout();

    map<QString, Options*> options;
    map<QString, QVBoxLayout*> optionsLayout;

};

#endif // LIVREARMEE_H
