#ifndef CREERLISTEARMEE_H
#define CREERLISTEARMEE_H

#include <QWidget>
#include <QString>
#include <QGridLayout>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QListView>
#include <QGroupBox>
#include <QLabel>
#include "livrearmee.h"
#include "optiongroupbox.h"

class CreerListeArmee : public QWidget
{
    Q_OBJECT
public:
    explicit CreerListeArmee(QWidget *parent = 0);
    void init(QString);

private:
    QGridLayout *grille;
    QGroupBox *optionsGroup;
    OptionGroupBox *options;
    QWidget *initCategorie(QString, QStringList);


    LivreArmee *choixPossibles;

public slots:
    void selectionChanged(QItemSelection);

};

#endif // CREERLISTEARMEE_H
