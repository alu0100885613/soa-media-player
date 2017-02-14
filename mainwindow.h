#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCameraViewfinder>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QList>
#include <QCameraInfo>
#include <QtDebug>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_webcamButton_clicked();

    void on_playButton_clicked();

    void on_stopButton_clicked();

    void on_normalButton_clicked(bool checked);

    void on_rewindButton_clicked(bool checked);

    void on_forwardButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QMediaPlayer* qmedia;
};

#endif // MAINWINDOW_H
