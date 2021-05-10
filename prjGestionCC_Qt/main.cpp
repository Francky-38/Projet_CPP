#include "entete.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Récup du path

    QSettings maConfig("parametres.ini", QSettings::IniFormat);
    QString pathOperations=maConfig.value("pathOperations").toString();

    //qDebug() << "Le papath des opé :" + pathOperations;

    MainWindow w;
    w.show();
    return a.exec();
    /*
        QQ questions :
       1 Y a-t-il un close sur le fichier .ini
       2 Comment faire un delete des "new QStandardItem(monClient->GetID())" (dans la construction de QtableView) ?
*/
}
