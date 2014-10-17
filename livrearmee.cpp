#include "livrearmee.h"

LivreArmee::LivreArmee(){

}

QStringList LivreArmee::getSeigneurs(){
    return seigneurs_;
}

QStringList LivreArmee::getHeros(){
    return heros_;
}

QStringList LivreArmee::getBase(){
    return base_;
}

QStringList LivreArmee::getSpeciales(){
    return speciales_;
}

QStringList LivreArmee::getRares(){
    return rares_;
}

QVBoxLayout *LivreArmee::getOptions(QString nomUnite){
    return optionsLayout[nomUnite];
}

void LivreArmee::init(QString nomArmee){

    QDomDocument *dom = new QDomDocument("Livre d'armée");
    QFile xml_doc("./xml/armees/" + nomArmee.remove(" ") + "/Unites.xml");
    if(!xml_doc.open(QIODevice::ReadOnly))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        std::cout<<"Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé"<<std::endl;
        return;
    }

    if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
    {
        xml_doc.close();
        std::cout<<"Erreur lors de l'association du fichier xml"<<std::endl;
        return;
    }
    initWithOptions("Seigneur", &seigneurs_, dom);
    initWithOptions("Hero", &heros_, dom);
    initWithOptions("UniteDeBase", &base_, dom);
    initWithOptions("UniteSpeciale", &speciales_, dom);
    initWithOptions("UniteRare", &rares_, dom);

    initOptionsLayout();

}

void LivreArmee::initWithOptions(QString categorie, QStringList *list, QDomDocument *dom){

    QString name;
    QDomElement e;
    QDomNodeList groupOptionsList;
    QDomNodeList optionsList;
    QDomElement dom_element = dom->documentElement();
    QDomNodeList armees = dom_element.elementsByTagName(categorie);
    for( int i=0; i< armees.count(); i++ ){
        e = armees.item(i).toElement();
        name = e.namedItem("Name").toElement().text();
        Options *newOptions = new Options();
        options[name] = newOptions;
        list->push_back(name);
        groupOptionsList = e.elementsByTagName("OptionGroup");
        for(int j=0; j < groupOptionsList.count(); j++){
            QDomElement groupOptionsElement = groupOptionsList.item(j).toElement();
            OptionGroupBox *newOptionGroup = new OptionGroupBox(groupOptionsElement.attribute("Name"));
            optionsList = groupOptionsElement.elementsByTagName("Option");
            for(int k=0; k < optionsList.count(); k++){
                QDomElement optionElement = optionsList.item(k).toElement();
                choix nouveauChoix;
                nouveauChoix.nom = optionElement.namedItem("Name").toElement().text();
                nouveauChoix.points = optionElement.namedItem("Points").toElement().text().toInt();
                newOptionGroup->addChoix(nouveauChoix);
            }
            newOptions->push_back(newOptionGroup);
        }
    }
}

void LivreArmee::initOptionsLayout(){
    map<QString, Options*>::iterator itUnite;
    for(itUnite = options.begin(); itUnite != options.end(); ++itUnite){
        QVBoxLayout * globalLayout = new QVBoxLayout();
        Options *currentOption = itUnite->second;
        vector<OptionGroupBox*>::iterator itOptionsGroup;
        for(itOptionsGroup = currentOption->begin(); itOptionsGroup != currentOption->end(); ++ itOptionsGroup){
            QVBoxLayout *tempLayout = new QVBoxLayout();
            OptionGroupBox *currentGroupBox = *itOptionsGroup;
            OptionGroupBox::iterator itGroupBox;
            for(itGroupBox = currentGroupBox->begin(); itGroupBox != currentGroupBox->end(); ++itGroupBox){
                choix currentChoix = *itGroupBox;
                QRadioButton *labelOption = new QRadioButton(currentChoix.nom);
                tempLayout->addWidget(labelOption);
            }
            currentGroupBox->setLayout(tempLayout);
            globalLayout->addWidget(currentGroupBox);
        }
        optionsLayout[itUnite->first] = globalLayout;
    }
}
