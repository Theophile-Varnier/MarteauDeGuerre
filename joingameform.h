#ifndef JOINGAMEFORM_H
#define JOINGAMEFORM_H

#include <QWidget>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QtXml>
#include <vector>
#include "livrearmee.h"

using std::vector;

class JoinGameForm : public QWidget
{
    Q_OBJECT
public:
    explicit JoinGameForm(QWidget *parent = 0);
    void obtenirArmeesDisponibles();
    QString ArmeeChoisie();
    QPushButton *cancel;
    QPushButton *continue_;

private:
    QFormLayout *formulaire;
    QComboBox *armee;
    QLineEdit *pseudo;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttons;
    vector<QString> armeesDisponibles_;
    LivreArmee *livreArmee_;

signals:

};

#endif // CREATEGAMEFORM_H
