#include "joingameform.h"

JoinGameForm::JoinGameForm(QWidget *parent) :
    QWidget(parent)
{
    obtenirArmeesDisponibles();
    setFixedSize(300,150);
    pseudo = new QLineEdit();
    armee = new QComboBox();
    for( unsigned int i = 0; i < armeesDisponibles_.size(); i++ ){
        armee->addItem(armeesDisponibles_[i]);
    }
    formulaire = new QFormLayout();
    formulaire->addRow("Pseudo", pseudo);
    formulaire->addRow("Armee", armee);

    cancel = new QPushButton("Annuler");
    continue_ = new QPushButton("Continuer");

    buttons = new QHBoxLayout();
    buttons->addWidget(cancel);
    buttons->addWidget(continue_);

    mainLayout = new QVBoxLayout();
    mainLayout->addLayout(formulaire);
    mainLayout->addLayout(buttons);
    setLayout(mainLayout);
}

void JoinGameForm::obtenirArmeesDisponibles(){
    QDomDocument *dom = new QDomDocument("Liste des armees disponibles");
    QFile xml_doc("./xml/ArmeesDisponibles.xml");
    if(!xml_doc.open(QIODevice::ReadOnly))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return;
    }

    if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
    {
        xml_doc.close();
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
        return;
    }
    QDomElement dom_element = dom->documentElement();
    QDomNodeList armees = dom_element.elementsByTagName("Armee");
    for( int i=0; i< armees.count(); i++ ){
        QDomElement e = armees.item(i).toElement();
        armeesDisponibles_.push_back(e.attribute("Name"));
    }
}

QString JoinGameForm::ArmeeChoisie(){
    return armee->currentText();
}
