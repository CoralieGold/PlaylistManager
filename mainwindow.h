#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextBrowser>
#include <QMediaPlayer>
#include <QComboBox>
#include <QFileInfo>
#include "interface.h"
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void uploadAuthorsList();
    void uploadTracksList();
    void uploadPlaylistsList();

    unsigned int actualTrackPlaylist;

private slots:

    void on_addAuthor_clicked();

    void on_editAuthor_clicked();

    void on_editAuthorInformations_clicked();

    void on_exportAuthors_clicked();

    void on_importAuthors_clicked();

    void on_addTrack_clicked();

    void on_editTrack_clicked();

    void on_editTrackInformations_clicked();

    void on_play_clicked();

    void on_addPlaylist_clicked();

    void on_editPlaylist_clicked();

    void on_editPlaylistInformations_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_importPlaylists_clicked();

    void on_exportPlaylists_clicked();

    void on_playPlaylist_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_timeSlider_valueChanged(int value);

    void on_playPlaylistPrevious_clicked();

    void on_playPlaylistNext_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    Interface myInterface;

    QLineEdit *authorName;
    QTextBrowser *authorsList;
    QLineEdit *editAuthorName;
    QComboBox *authorId;

    QLineEdit *trackTitle;
    QLineEdit *trackPath;
    QTextBrowser *tracksList;
    QComboBox *trackAuthor;
    QLineEdit *editTrackTitle;
    QComboBox *editTrackAuthor;
    QLineEdit *editTrackPath;
    QComboBox *trackId;

    QTextBrowser *playlistsList;
    QLineEdit *playlistTitle;
    QLineEdit *editPlaylistTitle;
    QComboBox *playlistId;

    QComboBox *playTracksList;
    QComboBox *playPlaylistsList;
};

#endif // MAINWINDOW_H
