#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer;

    authorName = ui->addAuthorName;
    authorsList = ui->seeListAuthors;
    editAuthorName = ui->editAuthorName;
    authorId = ui->idEditAuthor;

    tracksList = ui->seeListTracks;
    trackTitle = ui->addTitle;
    trackPath = ui->addFileName;
    trackAuthor = ui->addTrackAuthor;
    editTrackTitle = ui->editTitle;
    editTrackAuthor = ui->editAuthorTrack;
    editTrackPath = ui->editFileName;
    trackId = ui->idEditTrack;

    playlistsList = ui->seeListPlaylists;
    playlistTitle = ui->addTitlePlaylist;
    editPlaylistTitle = ui->editTitlePlaylist;
    playlistId = ui->idEditPlaylist;

    playTracksList = ui->playListTracks;
    playPlaylistsList = ui->playListPlaylists;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uploadAuthorsList() {
   authorsList->setText(QString::fromStdString(myInterface.seeAllAuthors()));
   trackAuthor->clear();
   editTrackAuthor->clear();
   authorId->clear();
   for(unsigned int i = 0; i < myInterface.getAuthors().size(); i++)
   {
       trackAuthor->addItem(QString::fromStdString(myInterface.getAuthors().at(i).print()));
       editTrackAuthor->addItem(QString::fromStdString(myInterface.getAuthors().at(i).print()));
       authorId->addItem(QString::fromStdString(myInterface.getAuthors().at(i).print()));
   }
}

void MainWindow::uploadTracksList() {
   tracksList->setText(QString::fromStdString(myInterface.seeAllTracks()));
   trackId->clear();
   for(unsigned int i = 0; i < myInterface.getTracks().size(); i++)
   {
       trackId->addItem(QString::fromStdString(myInterface.getTracks().at(i).print()));
       playTracksList->addItem(QString::fromStdString(myInterface.getTracks().at(i).print()));
   }
}

void MainWindow::uploadPlaylistsList() {
   playlistsList->setText(QString::fromStdString(myInterface.seeAllPlaylists()));
   playlistId->clear();
   for(unsigned int i = 0; i < myInterface.getPlaylists().size(); i++)
   {
       playlistId->addItem(QString::fromStdString(myInterface.getPlaylists().at(i).print()));
       playPlaylistsList->addItem(QString::fromStdString(myInterface.getPlaylists().at(i).print()));
   }
}

void MainWindow::on_addAuthor_clicked()
{
    std::string authorNameText = authorName->text().toStdString();
    myInterface.addAuthor(authorNameText);

    authorName->setText("Name");

    uploadAuthorsList();
}

void MainWindow::on_editAuthor_clicked()
{
    unsigned int i = authorId->currentIndex();
    editAuthorName->setText(QString::fromStdString(myInterface.getAuthors().at(i).getName()));
}

void MainWindow::on_editAuthorInformations_clicked()
{
    unsigned int i = authorId->currentIndex();
    myInterface.editAuthorName(i, editAuthorName->text().toStdString());

    uploadAuthorsList();
}

void MainWindow::on_exportAuthors_clicked()
{
    myInterface.exportAuthors();
}

void MainWindow::on_importAuthors_clicked()
{
    myInterface.importAuthors();

    uploadAuthorsList();
}

void MainWindow::on_addTrack_clicked()
{
    std::string trackTitleText = trackTitle->text().toStdString();
    std::string trackPathText = trackPath->text().toStdString();
    Author author;
    for(unsigned int i = 0; i < myInterface.getAuthors().size(); i++) {
        if(trackAuthor->currentText().toStdString() == myInterface.getAuthors().at(i).print()) {
            author = myInterface.getAuthors().at(i);
        }
    }
    myInterface.addTrack(Track(trackTitleText, author, trackPathText));

    trackTitle->setText("Title");
    trackPath->setText("Path");

    uploadTracksList();
}

void MainWindow::on_editTrack_clicked()
{
    unsigned int i = trackId->currentIndex();
    editTrackTitle->setText(QString::fromStdString(myInterface.getTracks().at(i).getTitle()));
    editTrackPath->setText(QString::fromStdString(myInterface.getTracks().at(i).getPath()));
    int indexAuthor = editTrackAuthor->findText(QString::fromStdString(myInterface.getAuthors().at(i).print()));
    editTrackAuthor->setCurrentIndex(indexAuthor);
}

void MainWindow::on_editTrackInformations_clicked()
{
    unsigned int i = trackId->currentIndex();
    myInterface.editTrackTitle(i, editTrackTitle->text().toStdString());
    myInterface.editTrackPath(i, editTrackPath->text().toStdString());
    Author author;
    for(unsigned int i = 0; i < myInterface.getAuthors().size(); i++) {
        if(editTrackAuthor->currentText().toStdString() == myInterface.getAuthors().at(i).print()) {
            author = myInterface.getAuthors().at(i);
        }
    }
    myInterface.editTrackAuthor(i, author);

    uploadTracksList();
}

void MainWindow::on_addPlaylist_clicked()
{
    std::string playlistTitleText = playlistTitle->text().toStdString();
    myInterface.addPlaylist(playlistTitleText);

    playlistTitle->setText("Title");

    uploadPlaylistsList();
}

void MainWindow::on_editPlaylist_clicked()
{
    unsigned int i = playlistId->currentIndex();
    editPlaylistTitle->setText(QString::fromStdString(myInterface.getPlaylists().at(i).getTitle()));
}

void MainWindow::on_editPlaylistInformations_clicked()
{
    unsigned int i = playlistId->currentIndex();
    myInterface.editPlaylistTitle(i, editPlaylistTitle->text().toStdString());

    uploadPlaylistsList();
}

void MainWindow::on_importPlaylists_clicked()
{
    myInterface.importPlaylists();

    uploadPlaylistsList();
    uploadTracksList();
    uploadAuthorsList();
}

void MainWindow::on_exportPlaylists_clicked()
{
    myInterface.exportPlaylists();
}

void MainWindow::on_play_clicked()
{
    if(player->state() != QMediaPlayer::PausedState)
    {
        unsigned int i = playTracksList->currentIndex();
        player->setMedia(QUrl::fromLocalFile(QString::fromStdString(myInterface.getTracks().at(i).getPath())));
    }
    player->play();
}

void MainWindow::on_pause_clicked()
{
    player->pause();
}

void MainWindow::on_stop_clicked()
{
    player->stop();
}

void MainWindow::on_playPlaylist_clicked()
{
    if(player->state() != QMediaPlayer::PausedState)
    {
        actualTrackPlaylist = 0;
        unsigned int i = playPlaylistsList->currentIndex();
        player->setMedia(QUrl::fromLocalFile(QString::fromStdString(myInterface.getPlaylists().at(i).getTracks().at(actualTrackPlaylist).getPath())));
        player->setVolume(100);
    }
    player->play();
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
}

void MainWindow::on_timeSlider_valueChanged(int value)
{
    player->setPosition(value);
}

void MainWindow::on_playPlaylistPrevious_clicked()
{
    if(actualTrackPlaylist == 0) actualTrackPlaylist = 0;
    else actualTrackPlaylist --;
    unsigned int i = playPlaylistsList->currentIndex();
    player->setMedia(QUrl::fromLocalFile(QString::fromStdString(myInterface.getPlaylists().at(i).getTracks().at(actualTrackPlaylist).getPath())));
    player->play();
}

void MainWindow::on_playPlaylistNext_clicked()
{
    unsigned int i = playPlaylistsList->currentIndex();
    if(actualTrackPlaylist == myInterface.getPlaylists().at(i).getTracks().size() - 1) actualTrackPlaylist = myInterface.getPlaylists().at(i).getTracks().size() - 1;
    else actualTrackPlaylist ++;
    player->setMedia(QUrl::fromLocalFile(QString::fromStdString(myInterface.getPlaylists().at(i).getTracks().at(actualTrackPlaylist).getPath())));
    player->play();
}
