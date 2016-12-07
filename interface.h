#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include "author.h"
#include "playlist.h"
#include "track.h"

class Interface
{
private:
    std::vector<Author> authors;
    std::vector<Track> tracks;
    std::vector<Playlist> playlists;

public:
    Interface();

    /** Authors **/
    void setAuthors(const std::vector<Author> &value);
    std::vector<Author> getAuthors() const;
    void addAuthor(Author newAuthor);
    std::string seeAllAuthors();
    void editAuthorName(unsigned int i, std::string new_name);
    void exportAuthors();
    void importAuthors();
    bool authorExist(Author author);


    /** Tracks **/
    std::vector<Track> getTracks() const;
    void setTracks(const std::vector<Track> &value);
    void addTrack(Track newTrack);
    std::string seeAllTracks();
    void editTrackTitle(unsigned int i, std::string new_title);
    void editTrackPath(unsigned int i, std::string new_path);
    void editTrackAuthor(unsigned int i, Author &new_author);
    bool trackExist(Track track);


    /** Playlists **/
    std::vector<Playlist> getPlaylists() const;
    void setPlaylists(const std::vector<Playlist> &value);
    void addPlaylist(std::string title);
    std::string seeAllPlaylists();
    void editPlaylistTitle(unsigned int i, std::string new_title);
    void exportPlaylists();
    void importPlaylists();
};

#endif // INTERFACE_H
