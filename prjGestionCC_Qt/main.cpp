#include "entete.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Récup du path
    QSettings maConfig("parametres.ini", QSettings::IniFormat);
    QString pathOperations=maConfig.value("pathOperations").toString();

    QFile fileQSS(":/styles/mesStyles.qss");
    //bool openOK = fileQSS.open(QIODevice::ReadOnly);
    if (fileQSS.open(QIODevice::ReadOnly))
    {
        //QString tt=fileQSS.readAll();
        a.setStyleSheet(fileQSS.readAll());
        qDebug() << fileQSS.readAll();
        fileQSS.close();
    }

    MainWindow w;
    w.show();
    return a.exec();

}
