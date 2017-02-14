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
    delete qmedia;
}


void MainWindow::on_webcamButton_clicked()
{

    if( ( qmedia->state() == QMediaPlayer::PlayingState ) || ( qmedia->state() == QMediaPlayer::PausedState ) ){
        qmedia->stop();
        ui->playButton->setText("P&lay");
    }

    if( camera->state() == QCamera::ActiveState )
        return;

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    setWindowTitle(cameras[0].deviceName());

    camera->setViewfinder(ui->pantalla);
    camera->start();
}

void MainWindow::on_playButton_clicked()
{

    if( camera->state() == QCamera::ActiveState ){
        camera->stop();
        qmedia->setVideoOutput(ui->pantalla);
    }

    if( qmedia->mediaStatus() == QMediaPlayer::NoMedia || qmedia->state() == QMediaPlayer::StoppedState  ){
        const QString EmptyName;
        QString VideoName = EmptyName;
        VideoName = QFileDialog::getOpenFileName(this,
               tr("Load Video"), QString(),
               tr("Mp4 Files (*.mp4);;AMV Files (*.amv)"));

        if( !VideoName.isEmpty() ){
            qmedia->setMedia(QUrl::fromLocalFile(VideoName));
            this->setWindowTitle(VideoName);
            qmedia->setVideoOutput(ui->pantalla);
            qmedia->play();

            const int plusWidth = (width()-ui->pantalla->width());
            const int plusHeight = (height()-ui->pantalla->height());

            if(qmedia->state() == QMediaPlayer::PlayingState)
                resize(640+plusWidth,360+plusHeight);

            ui->pantalla->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);
        } else {
            QMessageBox::warning(this,"Advertencia", "No ha elegido ningún vídeo", "Ok");
            return;
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
        qmedia->setPlaybackRate(1.0);

}

void MainWindow::on_rewindButton_clicked(bool checked)
{
    if(checked)
        qmedia->setPlaybackRate(-1.0);
}

void MainWindow::on_forwardButton_clicked(bool checked)
{
    if(checked)
        qmedia->setPlaybackRate(1.5);
}
