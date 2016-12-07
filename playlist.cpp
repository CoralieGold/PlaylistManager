#include "playlist.h"

std::string Playlist::getTitle() const
{
    return title;
}

void Playlist::setTitle(const std::string &value)
{
    title = value;
}

std::vector<Track> Playlist::getTracks() const
{
    return tracks;
}

void Playlist::setTracks(const std::vector<Track> &value)
{
    tracks = value;
}

Playlist::Playlist(std::string title)
{
    setTitle(title);
}

void Playlist::addTrack(const Track &track)
{
    tracks.push_back(track);
}

std::string Playlist::print() {
    return title;
}
