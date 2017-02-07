#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    camera(new QCamera(this)),
    qmedia(new QMediaPlayer(this))
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete camera;
}


void MainWindow::on_webcamButton_clicked()
{

    if( camera->state() == QCamera::ActiveState )
        return;

    camera->setViewfinder(ui->pantalla);
    camera->start();
}

void MainWindow::on_playButton_clicked()
{
    if( qmedia->mediaStatus() == QMediaPlayer::NoMedia ){
        QString VideoName = QFileDialog::getOpenFileName(this,
               tr("Load Video"), QString(),
               tr("Mp4 Files (*.mp4);;AMV Files (*.amv)"));

        if( !VideoName.isEmpty() ){
            qmedia->setMedia(QUrl::fromLocalFile(VideoName));
            qmedia->setVideoOutput(ui->pantalla);
            qmedia->play();
        }
    }

}


void MainWindow::on_stopButton_clicked()
{
    if( camera->state() == QCamera::ActiveState )
        camera->stop();


}
