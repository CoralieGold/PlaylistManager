#include "interface.h"

Interface::Interface()
{

}

/** Authors **/
bool Interface::authorExist(Author author) {
    bool exist = false;
    for(unsigned int i = 0; i < authors.size(); i++) {
        if(authors.at(i) == author) exist = true;
    }
    return exist;
}

void Interface::setAuthors(const std::vector<Author> &value)
{
    authors = value;
}

std::vector<Author> Interface::getAuthors() const
{
    return authors;
}

void Interface::addAuthor(Author newAuthor) {
    if(!authorExist(newAuthor)) authors.push_back(newAuthor);
}

std::string Interface::seeAllAuthors() {
    std::string result = "";
    std::string actualAuthor;
    for(unsigned int i = 0; i < authors.size(); i ++) {
       actualAuthor = authors.at(i).print() + "\n";
       result.append(actualAuthor);
    }
    return result;
}

void Interface::editAuthorName(unsigned int i, std::string new_name) {
    authors.at(i).setName(new_name);
}

void Interface::exportAuthors() {
    std::ofstream file("C:/Users/Coralie G/Documents/IMAC-Semestre3/C++/Project/CoralieGoldbaum_Project/authors.txt");
    if(file)
    {
        for(unsigned int i = 0; i < authors.size(); i ++) {
            file << authors.at(i).print() << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "ERROR : It was impossible to open the file authors.txt." << std::endl;
    }
}

void Interface::importAuthors() {
    std::ifstream file("C:/Users/Coralie G/Documents/IMAC-Semestre3/C++/Project/CoralieGoldbaum_Project/authors.txt");
    std::string line;
    if(file)
    {
        while (getline(file, line)) {
            addAuthor(line);
        }
        file.close();
    }
    else
    {
        std::cout << "ERROR : It was impossible to open the file authors.txt." << std::endl;
    }
}

/** Tracks **/

std::vector<Track> Interface::getTracks() const
{
    return tracks;
}

void Interface::setTracks(const std::vector<Track> &value){
    tracks = value;
}

void Interface::addTrack(Track newTrack) {
    if(!trackExist(newTrack)) tracks.push_back(newTrack);
}

std::string Interface::seeAllTracks() {
    std::string result;
    std::string actualTrack;
    for(unsigned int i = 0; i < tracks.size(); i ++) {
        actualTrack = tracks.at(i).print() + "\n";
        result.append(actualTrack);
    }
    return result;
}

void Interface::editTrackTitle(unsigned int i, std::string new_title) {
    tracks.at(i).setTitle(new_title);
}

void Interface::editTrackPath(unsigned int i, std::string new_path) {
    tracks.at(i).setPath(new_path);
}

void Interface::editTrackAuthor(unsigned int i, Author &new_author) {
    tracks.at(i).setAuthor(new_author);
}

bool Interface::trackExist(Track track) {
    bool exist = false;
    for(unsigned int i = 0; i < tracks.size(); i++) {
        if(tracks.at(i) == track) exist = true;
    }
    return exist;
}

/** Playlists **/
std::vector<Playlist> Interface::getPlaylists() const {
    return playlists;
}

void Interface::setPlaylists(const std::vector<Playlist> &value) {
    playlists = value;
}

void Interface::addPlaylist(std::string title) {
    playlists.push_back(Playlist(title));
}

std::string Interface::seeAllPlaylists() {
    std::string result;
    std::string actualPlaylist;
    for(unsigned int i = 0; i < playlists.size(); i ++) {
        actualPlaylist = playlists.at(i).print() + "\n";
        result.append(actualPlaylist);
    }
    return result;
}

void Interface::editPlaylistTitle(unsigned int i, std::string new_title) {
    playlists.at(i).setTitle(new_title);
}

void Interface::exportPlaylists() {
    std::ofstream file("C:/Users/Coralie G/Documents/IMAC-Semestre3/C++/Project/CoralieGoldbaum_Project/playlistExport.m3u");
    if(file)
    {
        file << "#EXTM3U\n" << std::endl;
        for(unsigned int i = 0; i < playlists.at(0).getTracks().size(); i ++) {
            file << "#EXTINF:186, " + playlists.at(0).getTracks().at(i).getAuthor().print() + " - " + playlists.at(0).getTracks().at(i).getTitle() << std::endl;
            file << playlists.at(0).getTracks().at(i).getPath() + "\n" << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "ERROR : It was impossible to open the file playlists.m3u." << std::endl;
    }
}

void Interface::importPlaylists() {
    std::ifstream file("C:/Users/Coralie G/Documents/IMAC-Semestre3/C++/Project/CoralieGoldbaum_Project/playlists.m3u");
    std::string line;
    if(file)
    {
        Playlist new_playlist("PlaylistImport");
        std::string authorName = "";
        std::string trackPath = "";
        std::string trackName = "";

        while (getline(file, line)) {
            if(line != "#EXTM3U" && line != "") {
                if(line[0] == '#') {
                    int pos = line.find(' ');
                    line = line.substr(pos+1);

                    pos = line.find('-');
                    authorName = line.substr(0, pos-1);
                    line = line.substr(pos+2);

                    trackName = line;
                }
                else {
                    trackPath = line;
                }
            }
            if(trackName != "" && trackPath != "") {
                Author newAuthor(authorName);
                addAuthor(newAuthor);
                Track new_track(trackName, newAuthor, trackPath);
                addTrack(new_track);
                new_playlist.addTrack(new_track);

                authorName = "";
                trackName = "";
                trackPath = "";
            }
        }

        playlists.push_back(new_playlist);

        file.close();
    }
    else
    {
        std::cout << "ERROR : It was impossible to open the file playlists.m3u." << std::endl;
    }
}
