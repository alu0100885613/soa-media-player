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

    if( ( qmedia->state() == QMediaPlayer::PlayingState ) || ( qmedia->state() == QMediaPlayer::PausedState ) ){
        qmedia->stop();
        ui->playButton->setText("P&lay");
    }

    if( camera->state() == QCamera::ActiveState )
        return;

    camera->setViewfinder(ui->pantalla);
    camera->start();
}

void MainWindow::on_playButton_clicked()
{
    if( camera->state() == QCamera::ActiveState ){
        camera->stop();
        qmedia->setVideoOutput(ui->pantalla);
    }

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

    const QString play = "P&lay";
    const QString pause = "P&ause";

    if( ui->playButton->text() == play && (qmedia->mediaStatus() != QMediaPlayer::NoMedia) ){
        ui->playButton->setText(pause);

        if( ( qmedia->state() == QMediaPlayer::PausedState ) || ( qmedia->state() == QMediaPlayer::StoppedState) )
            qmedia->play();

    } else {
        ui->playButton->setText(play);
        qmedia->pause();
    }


}


void MainWindow::on_stopButton_clicked()
{
    if( camera->state() == QCamera::ActiveState ){
        camera->stop();
        qmedia->setVideoOutput(ui->pantalla);
    }

    if( ( qmedia->state() ==  QMediaPlayer::PausedState ) || ( qmedia->state() ==  QMediaPlayer::PlayingState ) ){
         if( qmedia->state() ==  QMediaPlayer::PlayingState )
            ui->playButton->setText("P&lay");

         qmedia->stop();
    }


}

void MainWindow::on_normalButton_clicked(bool checked)
{
    if(checked)
        qmedia->setMuted(true);
    if(!checked)
        qmedia->setMuted(false);
}
