#include "creerlistearmee.h"

CreerListeArmee::CreerListeArmee(QWidget *parent) :
    QWidget(parent)
{
    grille = new QGridLayout();
    choixPossibles = new LivreArmee();
}

void CreerListeArmee::init(QString armee){
    const QString title("test");
    optionsGroup = new QGroupBox(title);
    grille->addWidget(optionsGroup, 0,1,3,1);

    choixPossibles->init(armee);

    grille->addWidget(initCategorie(QString("Seigneurs"), choixPossibles->getSeigneurs()), 0,0,1,1);
    grille->addWidget(initCategorie(QString("Héros"), choixPossibles->getHeros()),1,0,1,1);
    grille->addWidget(initCategorie(QString("Unités de base"), choixPossibles->getBase()),2,0,1,1);
    grille->addWidget(initCategorie(QString("Unités spéciales"), choixPossibles->getSpeciales()),3,0,1,1);
    grille->addWidget(initCategorie(QString("Unités rares"), choixPossibles->getRares()),4,0,1,1);

    grille->setColumnStretch(0, 1);
    grille->setColumnStretch(1,1);
    setLayout(grille);
}

QWidget *CreerListeArmee::initCategorie(QString title, QStringList choix){
    QGroupBox *groupBox = new QGroupBox(title);
    QStringListModel *model = new QStringListModel(choix);
    QListView *view = new QListView;
    view->setModel(model);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);
    groupBox->setLayout(layout);
    QObject::connect(view->selectionModel(), SIGNAL(selectionChanged(QItemSelection , QItemSelection )), this, SLOT(selectionChanged(QItemSelection)));

    return groupBox;
}

void CreerListeArmee::selectionChanged(QItemSelection newItem){
    QString nomUnite = newItem.indexes()[0].data().toString();
    optionsGroup->setTitle(nomUnite);
    optionsGroup->setLayout(choixPossibles->getOptions(nomUnite));
}
