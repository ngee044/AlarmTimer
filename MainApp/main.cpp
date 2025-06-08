#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;   // QMainWindow 파생 클래스
    w.show();       // 창 띄우기

    return app.exec();  // 이벤트 루프 진입
}
