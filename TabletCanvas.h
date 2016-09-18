#ifndef TABLETCANVAS_H
#define TABLETCANVAS_H

#include <QWidget>
#include <QTabletEvent>
//#include <vector>
#include <QMessageBox>
#include <QPoint>
//线段
typedef struct myLine{
    QPoint startPnt;
    QPoint endPnt;
}myLine;

using namespace std;

class TabletCanvas : public QWidget
{
    Q_OBJECT
public:
    TabletCanvas(QWidget* parent=0, const char* name="TabletCanvas");
    ~TabletCanvas();
    qreal currentPenPressure(){return mCrntPenPressure;}
    int penXPos(){return mPenXPos;}
    int penYPos(){return mPenYPos;}
    int penXTilt(){return mPenXTilt;}
    int penYTilt(){return mPenYTilt;}
    void paintEvent(QPaintEvent *p); //重载
    int get_lines(int index);
signals:
    void tabletEventProcessed();

protected:
    void tabletEvent(QTabletEvent *ev);
    bool writeFile(const QString filePath);
    //virtual void paintEvent(QPaintEvent *p); //重载

private:
    qreal mCrntPenPressure;
    int mPenXPos;
    int mPenYPos;
    int mPenXTilt;
    int mPenYTilt;
    QVector<myLine*> lines; //存放所有的线段

    QPoint startPnt;   //起点
    QPoint endPnt;     //终点
    bool isPressed;    //鼠标是否按下
};

#endif // TABLETCANVAS_H
