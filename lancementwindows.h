#ifndef LANCEMENT_H
#define LANCEMENT_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include "joingameform.h"
#include "creerlistearmee.h"

class LancementWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LancementWindow(QWidget *parent = 0);
    QPushButton *newGame;
    QPushButton *joinGame;
    QPushButton *quit;
private:
    QVBoxLayout *layout;
    JoinGameForm *joinGameForm;
    CreerListeArmee *creationListe;

signals:

public slots:
    void openJoinGameForm();
    void backToMenu();
    void creerListeArmee();
};

#endif // LANCEMENT_H
