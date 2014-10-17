#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include "lancementwindows.h"

int main(int argc, char *argv[])
{

    // UTF-8 Encoding
    /*QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));*/
    QApplication app(argc, argv);

    LancementWindow *fenetre = new LancementWindow();
    fenetre->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, fenetre->size(), app.desktop()->availableGeometry()));


    fenetre->show();

    return app.exec();
}
