#ifndef OPTIONGROUPBOX_H
#define OPTIONGROUPBOX_H

#include <QGroupBox>
#include <vector>
#include "common.h"

using std::vector;

class OptionGroupBox : public QGroupBox
{
    Q_OBJECT
public:

    typedef vector<choix>::iterator iterator;
    typedef vector<choix>::const_iterator const_iterator;

    iterator begin(){ return choixPossibles.begin(); }
    iterator end(){ return choixPossibles.end(); }

    explicit OptionGroupBox(QString title, QWidget *parent = 0);
    OptionGroupBox(const OptionGroupBox &);
    void addChoix(choix);
    OptionGroupBox &operator=(const OptionGroupBox&);

private:
    vector<choix> choixPossibles;

signals:

public slots:

};

#endif // OPTIONGROUPBOX_H
