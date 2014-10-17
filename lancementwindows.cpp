#include "lancementwindows.h"

LancementWindow::LancementWindow(QWidget *parent) :
    QWidget(parent)
{
    joinGameForm = new JoinGameForm();
    QObject::connect(joinGameForm->cancel, SIGNAL(clicked()), this, SLOT(backToMenu()));
    QObject::connect(joinGameForm->continue_, SIGNAL(clicked()), this, SLOT(creerListeArmee()));

    creationListe = new CreerListeArmee();

    setFixedSize(300, 150);
    newGame = new QPushButton("Lancer une nouvelle partie");
    joinGame = new QPushButton("Rejoindre une partie existante");
    quit = new QPushButton("Quitter");
    layout = new QVBoxLayout;
    layout->addWidget(newGame);
    layout->addWidget(joinGame);
    layout->addWidget(quit);
    this->setLayout(layout);

    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(joinGame, SIGNAL(clicked()), this, SLOT(openJoinGameForm()));
}

void LancementWindow::openJoinGameForm(){
    this->close();
    joinGameForm->setGeometry(this->geometry());
    joinGameForm->setWindowTitle("Rejoindre une partie");
    joinGameForm->show();
}

void LancementWindow::backToMenu(){
    joinGameForm->close();
    this->show();
}

void LancementWindow::creerListeArmee(){
    joinGameForm->close();
    //creationListe->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, creationListe->size(), QApplication::desktop()->availableGeometry()));
    creationListe->setWindowTitle("Création de la liste d'armée");
    creationListe->init(joinGameForm->ArmeeChoisie());
    creationListe->showMaximized();
}
