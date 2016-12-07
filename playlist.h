#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include "track.h"
#include "string.h"

class Playlist
{
private:
    std::vector<Track> tracks;
    std::string title;

public:
    std::vector<Track> getTracks() const;
    std::string getTitle() const;

    void setTracks(const std::vector<Track> &value);
    void setTitle(const std::string &value);

    Playlist(std::string title);

    void addTrack(const Track &track);
    std::string print();

};

#endif // PLAYLIST_H
